/* 
 * Jarrett Tang (903482852)
 * audisktool_jkt0011.cpp
 */
 
 #include "tool.h"
 
 int main() {
	 Tool tool;
	 CommandLine cmdline;
	 Configuration conf;
	 Report report;
	 
	 tool.init(cmdline, conf, report);
	 tool.start(cmdline, conf, report);
	 tool.exit();
	 
	 return 0;
 }