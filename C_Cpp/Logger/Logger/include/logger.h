#pragma once

#include<iostream>
#include<map>
#include<cstdarg>
#include<ctime>
#include<thread>
#include<sstream>
#include<mutex>
#include<atomic>

#ifdef _WIN32 || WIN32
#include<Windows.h>
#endif

using namespace std;

typedef map<string, string> mapstrstr;
typedef lock_guard<std::mutex> autoLockUnlockMutex;

#define DLLEXPORT __declspec(dllexport)
#define STDCALL __stdcall
#define DEFAULT_NAME "Unspecified Module"
#define DISABLE_LOG_FILE "DisableLog"
#define MAX_MESSAGE_LENGTH 1024
#define LOGGING_INTERVAL 6000 //in milliseconds
#define MAX_NUM_FILES 10
#define MAX_FILE_SIZE 5 // in MB


enum MessageType{
	eCritical = 0,
	eError,
	eInfo,
	eDebug
};

map <int, string> mapMessageType = {
	{eInfo, "INFO" },
	{ eError, "ERROR"},
	{ eCritical, "CRITICAL"},
	{ eDebug, "DEBUG"}
};


class DLLEXPORT Logger{
	string m_strModuleName;
	string m_strThreadId;

	static string m_strLogFileName;
	static string m_strLogFilePath;
	static string m_strLogFolder;

	static FILE* m_fpLogFile;

	static mapstrstr m_mapModuleBuffer;

	static mutex m_mtxAccessBuffer;
	static mutex m_mtxAccessFile;

	static thread m_threadWriteLog;

	static long double m_ldPreviousFlushTime;

	static atomic_bool m_abIsFirstInstance;

	static int m_iMaxLogLevel;

	void Init(string strModule);
	void OpenFile();
	void CloseFile();

	static string GetMessageType(int iMessageType);
	static time_t GetTime();
	static void WriteToFile(string strModuleName, string strBuffer);
	static void WriteToFile(string strModuleName);
	static void WriteLogThread();
public:
	Logger();
	Logger(string strModule);
	~Logger();

	void Log(int iMessageType, const char* pcstrMessage, ...);

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
