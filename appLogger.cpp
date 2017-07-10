#include <stdio.h>
#include <time.h>
#include <sstream>
#include "appLogger.h"

AppLogger::LogLevel AppLogger::WRITE_LOG_LEVEL=AppLogger::eLOG_NOTHING;
AppLogger::LogLevel AppLogger::FORCE_TERMINATE_LEVEL=AppLogger::eLOG_ERROR;
std::string AppLogger::LOG_FILE_NAME="app.log";

void AppLogger::ChangeLogLevel(AppLogger::LogLevel lv){
	WRITE_LOG_LEVEL=lv;
}

void AppLogger::ChangeForceTerminateLevel(AppLogger::LogLevel lv){
	FORCE_TERMINATE_LEVEL=lv;
}

void AppLogger::ChangeLogFileName(std::string fname){
	LOG_FILE_NAME=fname;
}

bool AppLogger::Log(AppLogger::LogLevel log_level,std::string message){
	if(log_level>=WRITE_LOG_LEVEL){
		FILE *fp=fopen(LOG_FILE_NAME.c_str(),"a");
		if(fp){
			// format: [INFO] year-month-day hour:min:sec message
			std::stringstream output;
			output<<"[";
			switch(log_level){
			case eLOG_DEBUG:
				output<<"DEBUG";
				break;
			case eLOG_WARN:
				output<<"WARN";
				break;
			case eLOG_ERROR:
				output<<"ERROR";
				break;
			default:
				return false;
			}
			output<<"] ";

			// output date
			time_t now=time(NULL);
			struct tm *t=localtime(&now);
			output<<(t->tm_year+1900)<<"-"<<(t->tm_mon+1)<<"-"<<t->tm_mday<<" ";
			output<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec<<" ";

			output<<message<<"\n";
			fputs(output.str().c_str(),fp);
			fclose(fp);
		}else
			return false;
		return true;// success of adding a log
	}
	return false;
}
