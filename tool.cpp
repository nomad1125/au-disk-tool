/* 
 * Jarrett Tang (903482852)
 * tool.cpp
 */
 
 #include "tool.h"
 Tool::Tool(void) {
 }
 
 void Tool::init(CommandLine& cmd, Configuration& conf, Report& rpt) {
	 cmd = CommandLine();
	 conf = Configuration();
	 rpt = Report();
 }
 
 void Tool::start(CommandLine& cmdline, Configuration& conf, Report& report) {
	 cmd_t type;
	 flag_t flag;
	 u_int value;
	 cmdline.get_command();
	 while ((type = cmdline.get_type()) != EXIT) {
		 flag = cmdline.get_flag();
		 value = cmdline.get_value();
		 respond_cmd(cmdline, conf, report);
		 cmdline.get_command();
	 }
 }
 
 void Tool::exit() {
	 return;
 }
 
 void Tool::respond_cmd(CommandLine& cmdline, Configuration& conf, Report& report) {
	 switch (cmdline.get_type()) {
		 case RUN:
			Tool::run(cmdline, conf, report);
			break;
			
		 case SET:
			conf.set(cmdline.get_flag(), cmdline.get_value());
			break;
			
		 case PRINT:
			if (cmdline.get_flag() == REPORT) {
				report.print_report();
			}
			else if (cmdline.get_flag() == CONF){
				conf.print_conf();
			}
			break;
			
		 case SAVE:
			conf.save_conf();
			break;
			
		 case HELP:
			cout << "run - run the monitoring tool."
				   << "\nset interval [value] - set sampling period to [value]"
				   << "\nset count [value] - set the number of records to [value]"
				   << "\nset blk_read\t[0|1] - set print_blk_read to 0 or 1"
				   << "\nset blk_read/s\t[0|1] - set print_blk_read/s to 0 or 1"
				   << "\nset kb_read/s\t[0|1] - set print_kb_read/s to 0 or 1"
				   << "\nset blk_write\t[0|1] - set print_blk_write to 0 or 1"
				   << "\nset blk_write/s\t[0|1] - set print_blk_write/s to 0 or 1"
				   << "\nset kb_write\t[0|1] - set print_kb_write to 0 or 1"
				   << "\nprint conf - display all the parameters"
				   << "\nprint report - open and display the report file"
				   << "\nsave - the configuration file audisktool.conf is updated"
				   << "\nexit - exit the tool.\n\n";
			 break;
			 
		 case ERROR:
			cout << "Parameters not recognized. Please type \'help\' for a list of options.";
			break;
	 }
 }
 
 void Tool::run(CommandLine& cmdline, Configuration& conf, Report& report) {
	 conf.print_conf();
	 cout << "Please wait ...\n\n";
	 
	 Record newRecord; 
	 int position;
	 int fieldNum = 0;
	 string input = "";
	 double fieldThreeA, fieldSevenA, fieldThreeB, fieldSevenB;
	 vector<char> tempVector;
	 vector<double> doubleVector;
	 ifstream infile;
	 infile.open ("/proc/diskstats");
	 if (infile.is_open()) {
		 while (!infile.eof()) {
			 tempVector.push_back((char) infile.get());
		 }
		 infile.close();
	 }
	 else {
		 cout << "Error opening file";
	 }
	 // finds starting position/number
	 for (int i = 0; i < tempVector.size(); i++) {
		 string check = "";
		 check += tempVector[i];
		 check += tempVector[i+1];
		 check += tempVector[i+2];
		 if (check == "sda") {
			 position = i+3;
			 break;
		 }
	 }
	 
	 for (int i = 0; i < conf.get_count(); i++) {
		 // this loop is to find field 3
		 for (int x = position; x < tempVector.size(); x++) {
			 if (tempVector[x] == ' ') {
				 fieldNum++;
			 }
			 if (fieldNum == 3) {
				 if (tempVector[x+1] != ' ') {
					 cin >> fieldThreeA;
				 }
			 }
			 if (fieldNum == 7) {
				 if (tempVector[x+1] != ' ') {
					 cin >> fieldSevenA;
				 }
			 }
		 }
		 // sleep((conf.get_interval() * 1000));
		  for (int x = position; x < tempVector.size(); x++) {
			 if (tempVector[x] == ' ') {
				 fieldNum++;
			 }
			 if (fieldNum == 3) {
				 if (tempVector[x+1] != ' ') {
					 cin >> fieldThreeB;
				 }
			 }
			 if (fieldNum == 7) {
				 if (tempVector[x+1] != ' ') {
					 cin >> fieldSevenB;
				 }
			 }
		 }
		 newRecord.blk_read = (fieldThreeB - fieldThreeA);
		 newRecord.blk_read_s = ((fieldThreeB - fieldThreeA) / (conf.get_interval() * 1000));
		 newRecord.kb_read_s = ((fieldThreeB - fieldThreeA) / (conf.get_interval() * 2000));
		 
		 newRecord.blk_write = (fieldSevenB - fieldSevenA);
		 newRecord.blk_write_s = ((fieldSevenB - fieldSevenA) / (conf.get_interval() * 1000));
		 newRecord.kb_write_s = ((fieldSevenB - fieldSevenA) / (conf.get_interval() * 2000));
		 report.add_record(newRecord);
	 }
 }