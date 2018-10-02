#include<iostream>
#include<map>
#include<cstdarg>
#include<ctime>
#include<Windows.h>
using namespace std;

#define DLLEXPORT __declspec(dllexport)
#define STDCALL __stdcall
#define DEFAULT_NAME "Logs"
#define DISABLE_LOG_FILE "DisableLog"
#define MAX_MESSAGE_LENGTH 1024
#define MAX_TIME_DIFF_BETWEEN_TWO_FLUSHES 60000 //in milliseconds

enum MessageType{
	eInfo = 0,
	eError,
	eCritical
};

map <int, string> mapMessageType = {
	{eInfo, "INFO" },
	{ eError, "ERROR"},
	{ eCritical, "CRITICAL"}
};

class DLLEXPORT Logger{
	string m_strModuleName;
	string m_strLogFileName;
	string m_strLogFilePath;
	string m_strLogFolder;
	FILE* m_fpFile;
	long double m_ldPreviousFlushTime;
	void Set(string strModule);
	void OpenFile();
	void CloseFile();
	void Flush();
	string GetMessageType(int iMessageType);
	time_t GetTime();
public:
	Logger();
	Logger(string strModule);
	~Logger();
	string GetFileName();
	string GetFullPath();
	string GetFolderPath();
	string GetModuleName();
	string GetTimeStamp();
	bool IsLogFileValid();
	bool Log(int iMessageType,const char* pcstrMessage, ...);
};

//Need to create a thread that will be continously monitoring the log file size
//Log file size must be configurable
//Registry key would be better
//Let the application using this logger pass a parameter with constructor
//By default let the file size be 5MB
//And at any time let us keep 10 log files - 1 current and 9 backup logs
//Let the size and number of backup files be configurable - Constructor

//A function which does the above work has to be written
//and has to be spawned as a thread while executing the constructor