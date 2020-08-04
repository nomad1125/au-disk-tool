/* 
 * Jarrett Tang (903482852)
 * tool.h
 */
 
 #ifndef TOOL_H
 #define TOOL_H
 #include <iostream>
 #include <string>
 #include <fstream>
 #include <vector>
 #include <stdlib.h>
 #include "commandline.h"
 #include "report.h"
 #include "configuration.h"
 
 using namespace std;
 
 class Tool {
	 private:
		void respond_cmd(CommandLine& cmdline, Configuration& conf, Report& report);
		void run(CommandLine& cmdline, Configuration& conf, Report& report);
	 
	 public:
		Tool();
		void init(CommandLine& cmd, Configuration& conf, Report& rpt);
		void start(CommandLine& cmdline, Configuration& conf, Report& report);
		void exit();
 };
 
 #endif