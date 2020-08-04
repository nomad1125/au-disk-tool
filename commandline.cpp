/* 
 * Jarrett Tang (903482852)
 * commandline.cpp
 */
 
 #include "commandline.h"
 
 CommandLine::CommandLine() {
	 
 }
 
 cmd_t CommandLine :: str_to_cmd_t (string const& cmdString) {
	 if (cmdString == "run") return RUN;
	 if (cmdString == "set") return SET;
	 if (cmdString == "print") return PRINT;
	 if (cmdString == "save") return SAVE;
	 if (cmdString == "help") return HELP;
	 if (cmdString == "exit") return EXIT;
	 else {
		 return ERROR;
	 }
 }
 
 flag_t CommandLine :: str_to_flag_t (string const& flagString) {
	 if (flagString == "interval") return INTERVAL;
	 if (flagString == "count") return COUNT;
	 if (flagString ==  "blk_read") return BLK_READ;
	 if (flagString == "blk_read/s") return BLK_READ_S;
	 if (flagString == "kb_read/s") return KB_READ_S;
	 if (flagString == "blk_write") return BLK_WRITE;
	 if (flagString == "blk_write/s") return BLK_WRITE_S;
	 if (flagString == "kb_write/s") return KB_WRITE_S;
	 if (flagString == "report") return REPORT;
	 if (flagString == "conf") return CONF;
	 else {
		 // return ERROR;
	 }
 }
 
 cmd_t CommandLine::get_type(void) {
	 return type;
 }
 
 flag_t CommandLine::get_flag(void) {
	 return flag;
 }
 
 u_int CommandLine::get_value(void) {
	 return value;
 }
 
 void CommandLine::get_command(void) {
	 string userCommand;
	 string commandType;
	 string commandFlag;
	 int position;
	 
	 cout << "Enter a command line below" << endl;
	 cout << "> ";
	 getline(cin, userCommand);
	 
	 position = userCommand.find(" ");
	 commandType = userCommand.substr(0, position);
	 type = str_to_cmd_t(commandType);
	 
	 // removes command type
	 userCommand = (userCommand.substr(position + 1));
	 
	 if (userCommand != commandType) {
		 position = userCommand.find(" ");
		 commandFlag = userCommand.substr(0, position);
		 flag = str_to_flag_t(commandFlag);
		 
		 // removes command flag 
		 userCommand = userCommand.substr(position + 1);
		 if (userCommand != commandFlag) {
			 istringstream value_buffer(userCommand);
			 value_buffer >> value;
		 }
		 else {
			 value = 0;
		 }
	 }
 }