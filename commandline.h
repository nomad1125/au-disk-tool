/* 
 * Jarrett Tang (903482852)
 * commandline.h
 */
 
 #ifndef COMMANDLINE_H
 #define COMMANDLINE_H
 #include <iostream>
 #include <string>
 #include <sstream>
 using namespace std;
 
 enum cmd_t {
		RUN, SET, PRINT, SAVE, HELP, ERROR, EXIT
 };
 
 typedef unsigned int u_int;
 
 // cmd_t str_to_cmd_t (string const& cmdString);
 // void respond_cmd (CommandLine& cmd);
 
 enum flag_t {
	 INTERVAL, COUNT, BLK_READ, BLK_READ_S, 
	 KB_READ_S, BLK_WRITE, BLK_WRITE_S, 
	 KB_WRITE_S, REPORT, CONF
 };
 
 // flag_t str_to_flag_t (string const& flagString);

 
 class CommandLine {
	 private:
		cmd_t type;
		flag_t flag;
		u_int value;
		cmd_t str_to_cmd_t (string const&);
		flag_t str_to_flag_t (string const&);
	 
	 public:
		CommandLine();
		cmd_t get_type(void);
		flag_t get_flag(void);
		u_int get_value(void);
		void get_command(void); // get user cmd input
 };
 #endif