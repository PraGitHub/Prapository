#include<iostream>
#include<map>
#include<cstdarg>
#include<ctime>
#include<thread>
#include<Windows.h>
using namespace std;

#define DLLEXPORT __declspec(dllexport)
#define STDCALL __stdcall
#define DEFAULT_NAME "Logs"
#define DISABLE_LOG_FILE "DisableLog"
#define MAX_MESSAGE_LENGTH 1024
#define LOGGING_INTERVAL 60000 //in milliseconds
#define MAX_NUM_FILES 10
#define MAX_FILE_SIZE 5 // in MB

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
	FILE* m_fpFile;

	string m_strModuleName;
	string m_strLogFileName;
	string m_strLogFilePath;
	string m_strLogFolder;
	string m_strBuffer;

	CRITICAL_SECTION m_csAccessBuffer;
	CRITICAL_SECTION m_csAccessBufferCS;

	thread m_threadWriteLog;

	long double m_ldPreviousFlushTime;

	void Init(string strModule);
	void OpenFile();
	void CloseFile();
	void WriteLogThread();

	string GetMessageType(int iMessageType);

	time_t GetTime();
public:
	Logger();
	Logger(string strModule);
	~Logger();

	void Log(int iMessageType, const char* pcstrMessage, ...);

	bool IsLogFileValid();

	string GetFileName();
	string GetFullPath();
	string GetFolderPath();
	string GetModuleName();
	string GetTimeStamp();
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