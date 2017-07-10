#include <iostream>
#include "appLogger.h"

int main(int argc,char *argv[]){
	AppLogger::ChangeLogLevel(AppLogger::eLOG_DEBUG);
	AppLogger::Log(AppLogger::eLOG_WARN,"warning message");
	AppLogger::Log(AppLogger::eLOG_ERROR,"error is occured");
	return 0;
}
