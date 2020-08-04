/* 
 * Jarrett Tang (903482852)
 * report.h
 */
 
 #ifndef REPORT_H
 #define REPORT_H
 #include <iostream>
 #include <string>
 #include <fstream>
 #include <vector>
 using namespace std;
 
 struct Record
 {
	 double blk_read;
	 double blk_read_s;
	 double kb_read_s;
	 double blk_write;
	 double blk_write_s;
	 double kb_write_s;
 };
 
 class Report {
	 private:
		vector<Record> recordList;
		
	 public:
		Report();
		void add_record(Record newRecord);
		Record get_record(int key);
		void print_report(); // used by tool.respond_cmd()
		bool save_report(); // used by tool.respong_cmd()
		bool load_report(); // used by tool.init()
 };
 #endif