#include <iostream>
#include "appLogger.h"

int main(int argc,char *argv[]){
	AppLogger::ChangeLogLevel(AppLogger::eLOG_DEBUG);
	AppLogger::ChangeLogFileName("test.log");

	AppLogger::Warn("warning message");

	int val = 10;
	AppLogger::Info("val = %d", val);

	return 0;
}
