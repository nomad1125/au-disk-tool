/* 
 * Jarrett Tang (903482852)
 * configuartion.h
 */
 
 #ifndef CONFIGURATION_H
 #define CONFIGURATION_H
 #include <iostream>
 #include <string>
 #include <fstream>
 #include <vector>
 #include "commandline.h"
 using namespace std;
 
 class Configuration {
	 private:
		int interval;
		int count;
		int blkReadFlag;
		int blkReadSFlag;
		int kbReadSFlag;
		int blkWrtnFlag;
		int blkWrtnSFlag;
		int kbWrtnSFlag;
		bool changed;
		
	 public: 
		Configuration();
		void print_conf(); // used by tool.respond_cmd()
		void save_conf(); // used to overwrite changes
		void load_conf();
		int get_count(void);
		int get_interval(void);
		
		// go back and look up how to parse commands
		void set(flag_t inFlag, int inValue);
 };
 #endif