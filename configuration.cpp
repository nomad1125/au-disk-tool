/* 
 * Jarrett Tang (903482852)
 * configuartion.cpp
 */
 
 #include "configuration.h"
 
 Configuration::Configuration() {
	 load_conf();
 }
 
 void Configuration :: print_conf() {
	 cout << "Monitoring time = " << interval << " Seconds, Number of records = "
			<< count << ",\n" << "print_blk_read = " << blkReadFlag << ", print_blk_read/s = "
			<< blkReadSFlag << ", print_kb_read/s = " << kbReadSFlag << ",\nprint_blk_write = "
			<< blkWrtnFlag << ", print_blk_write/s = " << blkWrtnSFlag << ", print_kb_write/s = "
			<< kbWrtnSFlag << ",\nreport file name = \'report.adt\'\n\n";
 }
 
 void Configuration :: save_conf() {
	 string filename = "audisktool.conf";
	 ofstream outStream;
	 outStream.open(filename.c_str());
	 
	 outStream << interval << " " << count << " " << blkReadFlag << " " << blkReadSFlag
					<< " " << kbReadSFlag << " " << blkWrtnFlag << " " << blkWrtnSFlag
					<< " " << kbWrtnSFlag;
	 outStream.close();
 }
 
 void Configuration::load_conf() {
	 string filename = "audisktool.conf";
	 ifstream inStream;
	 vector<int> tempVector;
	 char tempNum;
	 inStream.open(filename.c_str());
	 if (inStream.fail()) {
		 cout << "Config file not found. Program may run abnormally if not found.\n";
		 return;
	 }
	 while (inStream >> tempNum) {
		 if (tempNum != ' ') {
			 tempVector.push_back((int)tempNum);
		 }
	 }
	 interval = tempVector[0];
	 count = tempVector[1];
	 blkReadFlag = tempVector[2];
	 blkReadSFlag = tempVector[3];
	 kbReadSFlag = tempVector[4];
	 blkWrtnFlag = tempVector[5];
	 blkWrtnSFlag = tempVector[6];
	 kbWrtnSFlag = tempVector[7];
 }
		
 void Configuration::set(flag_t inFlag, int inValue) {
	 if (inValue < 0) {
		 cout << "Value out of bounds.\n";
		 return;
	 }
	 
	 // should check if value is 0 or 1 if its an option necessary for it.
	 if (inFlag > 1) {
		 if (inValue > 1) {
			 cout << "Value out of bounds for this parameter.\n";
			 return;
		 }
	 }
	 
	 switch (inFlag) {
		 case INTERVAL:
			interval = inValue;
			break;
		 case COUNT:
			count = inValue;
			break;
		 case BLK_READ:
			blkReadFlag = inValue;
			break;
		 case BLK_READ_S:
			blkReadSFlag = inValue;
			break;
		 case KB_READ_S:
			kbReadSFlag = inValue;
			break;
		 case BLK_WRITE:
			blkWrtnFlag = inValue;
			break;
		 case BLK_WRITE_S:
			blkWrtnSFlag = inValue;
			break;
		 case KB_WRITE_S:
			kbWrtnSFlag = inValue;
			break;
	 }
	 changed = true;
 }
 
 int Configuration::get_count(void) {
	 return count;
 }
 
 int Configuration::get_interval(void) {
	 return interval;
 }