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
	static FILE* m_fpFile;

	static string m_strModuleName;
	static string m_strLogFileName;
	static string m_strLogFilePath;
	static string m_strLogFolder;
	static string m_strBuffer;

	static CRITICAL_SECTION m_csAccessBuffer;
	static CRITICAL_SECTION m_csAccessBufferCS;

	static thread m_threadWriteLog;

	static long double m_ldPreviousFlushTime;

	static void Init(string strModule);
	static void OpenFile();
	static void CloseFile();
	static void WriteLogThread();

	static string GetMessageType(int iMessageType);

	static time_t GetTime();
public:
	Logger();
	Logger(string strModule);
	~Logger();

	static void Log(int iMessageType, const char* pcstrMessage, ...);

	static bool IsLogFileValid();

	static string GetFileName();
	static string GetFullPath();
	static string GetFolderPath();
	static string GetModuleName();
	static string GetTimeStamp();
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