/* 
 * Jarrett Tang (903482852)
 * report.cpp
 */
 
 #include "report.h"
 
 Report::Report() {}
 
 void Report::add_record(Record newRecord) {
	 recordList.push_back(newRecord);
 }
 
 Record Report :: get_record(int key) { 
	 return recordList[key];
 }
 
 void Report::print_report() { // used by tool.respond_cmd()
	 bool isReportSet;
	 isReportSet = load_report();
	 string output = "";
	 if (isReportSet = false) {
		 cout << "No reports found.";
		 return;
	 }
	 cout << recordList.size() << " records found in \'report.adt\'\n";
	 cout << "blk_read\tblk_read/s\tkb_read/s\tblk_write\tblk_write/s\tkb_write/s";
	 // if recorded score = 0 make output N/A
	 // for (int i = 0; i < recordList.size(); i++) {
		 // cout << recordList[i].blk_read << "\t" <<  recordList[i].blk_read_s << "\t"
				// <<  recordList[i].kb_read_s; << "\t" <<  recordList[i].blk_write << "\t"
				// <<  recordList[i].blk_write_s << "\t" <<  recordList[i].kb_write_s << "\t"
				// << "\n";
	 // }
	 for (int i = 0; i < recordList.size(); i++) {
		 if (recordList[i].blk_read == 0) {
			 output += "N/A\t";
		 }
		 else {
			 output += recordList[i].blk_read;
			 output += "\t";
		 }
		 if (recordList[i].blk_read_s == 0) {
			 output += "N/A\t";
		 }
		 else {
			 output += recordList[i].blk_read_s;
			 output += "\t";
		 }
		 if (recordList[i].kb_read_s == 0) {
			 output += "N/A\t";
		 }
		 else {
			 output += recordList[i].kb_read_s;
			 output += "\t";
		 }
		 if (recordList[i].blk_write == 0) {
			 output += "N/A\t";
		 }
		 else {
			 output += recordList[i].blk_write;
			 output += "\t";
		 }
		 if (recordList[i].blk_write_s == 0) {
			 output += "N/A\t";
		 }
		 else {
			 output += recordList[i].blk_write_s;
			 output += "\t";
		 }
		 if (recordList[i].kb_write_s == 0) {
			 output += "N/A\t";
		 }
		 else {
			 output += recordList[i].kb_write_s;
			 output += "\n";
		 }
	 }
	 cout << output << "\n";
 }
 
 bool Report::save_report() { // used by commandline.respond_cmd()
	 string filename = "report.adt";
	 ofstream outStream;
	 outStream.open(filename.c_str());
	 
	 for (int i = 0; i < recordList.size(); i++) {
		 outStream << recordList[i].blk_read << " " << recordList[i].blk_read_s << " "
						<< recordList[i].kb_read_s << " " << recordList[i].blk_write << " "
						<< recordList[i].blk_write_s << " " << recordList[i].kb_write_s << "\n";
	 }
	 outStream.close();
	 return true;
 }
 
 bool Report::load_report() { // used by tool.init()
	 string filename = "report.adt";
	 string fileData;
	 double tempNum;
	 Record newRecord;
	 vector<double> tempVector;
	 ifstream inStream;
	 inStream.open(filename.c_str());
	 if (inStream.fail()) {
		 cout << "File not found.";
		 return false;
	 }
	 
	 while (inStream >> tempNum) {
		 tempVector.push_back(tempNum);
	 }
	 for (int i = 0; i < (tempVector.size() / 6); i++) {
		 newRecord.blk_read = tempVector[i];
		 newRecord.blk_read_s = tempVector[i+1];
		 newRecord.kb_read_s = tempVector[i+2];
		 newRecord.blk_write = tempVector[i+3];
		 newRecord.blk_write_s = tempVector[i+4];
		 newRecord.kb_write_s = tempVector[i+5];
		 add_record(newRecord);
	 }
	 return true;
 }