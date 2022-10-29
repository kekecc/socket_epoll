#ifndef _LOGGER_H_
#define _LOGGER_H_
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

enum class Log {
  Error,
  Warning,
  Info,
};

class Logger {
private:
   const char *file_path = "log.txt";

public:
void setLog(Log type, const string message) {
    ofstream of;
    of.open(file_path, ofstream::app);
    time_t t = time(nullptr);
    char* other = ctime(&t);
    switch (type) {
        case Log::Error: of << other << "Error:" << message << endl; break;
        case Log::Warning: of << other << "Warning:" << message << endl; break;
        case Log::Info: of << other << "Information:" << message << endl; break;
    }
    of.close();
  }
};
//const char* Logger::file_path = "log.txt";

//extern Logger logger;
#endif