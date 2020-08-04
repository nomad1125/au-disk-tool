#	Jarrett Tang (903482852)
#	Makefile
#	variables
CC = g++
CFLAGS = -c
OBJ = configuration.o tool.o commandline.o report.o audisktool_jkt0011.o

all : audisktool_jkt0011

audisktool_jkt0011 : $(OBJ)
	$(CC) -o audisktool_jkt0011 $(OBJ)
	
commandline.o : commandline.cpp commandline.h
	$(CC) $(CFLAGS) commandline.cpp
	
report.o : report.cpp report.h
	$(CC) $(CFLAGS) report.cpp
	
configuration.o : configuration.cpp configuration.h commandline.h
	$(CC) $(CFLAGS) configuration.cpp
	
tool.o : tool.cpp tool.h commandline.h report.h configuration.h
	$(CC) $(CFLAGS) tool.cpp
	
audisktool_jkt0011.o : audisktool_jkt0011.cpp tool.h
	$(CC) $(CFLAGS) audisktool_jkt0011.cpp
	
clean :
	rm -rf *o audisktool_jkt0011