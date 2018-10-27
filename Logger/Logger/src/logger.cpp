#include"logger.h"

string Logger::m_strBuffer;
string Logger::m_strLogFileName;
string Logger::m_strLogFilePath;
string Logger::m_strLogFolder;
string Logger::m_strModuleName;
CRITICAL_SECTION Logger::m_csAccessBuffer;
CRITICAL_SECTION Logger::m_csAccessBufferCS;
thread Logger::m_threadWriteLog;
long double Logger::m_ldPreviousFlushTime;
FILE* Logger::m_fpFile = NULL;

Logger::Logger()
{
	Init(DEFAULT_NAME);
	OpenFile();
}

Logger::Logger(string strModuleName)
{
	if (strModuleName.empty())
	{
		strModuleName = DEFAULT_NAME;
	}
	Init(strModuleName);
	OpenFile();
}

Logger::~Logger()
{
	CloseFile();
	EnterCriticalSection(&Logger::m_csAccessBufferCS);
	DeleteCriticalSection(&Logger::m_csAccessBuffer);
	LeaveCriticalSection(&Logger::m_csAccessBufferCS);
	DeleteCriticalSection(&Logger::m_csAccessBufferCS);
}

void Logger::Init(string strModuleName)
{
	m_strBuffer = "";
	m_strModuleName = strModuleName;
	m_strLogFileName = m_strModuleName + ".log";
	CHAR pcstrModulePath[MAX_PATH];
	GetModuleFileName(NULL, pcstrModulePath, (DWORD)MAX_PATH);
	string strLogFolder(pcstrModulePath);
	strLogFolder = strLogFolder.substr(0, strLogFolder.rfind("\\"));
	m_strLogFolder = strLogFolder;
	m_strLogFilePath = m_strLogFolder + "\\" + m_strLogFileName;
	m_ldPreviousFlushTime = GetTime();
	m_threadWriteLog = thread(&Logger::WriteLogThread);
}

void Logger::OpenFile()
{
	m_fpFile = fopen(m_strLogFilePath.c_str(), "a");
}

void Logger::CloseFile()
{
	if (m_fpFile)
	{
		fclose(m_fpFile);
	}
}

string Logger::GetFileName()
{
	return m_strLogFileName;
}

string Logger::GetFullPath()
{
	return m_strLogFilePath;
}

string Logger::GetFolderPath()
{
	return m_strLogFolder;
}

string Logger::GetModuleName()
{
	return m_strModuleName;
}

time_t Logger::GetTime()
{
	long double ldTime = time(NULL);
	return ldTime;
}

string Logger::GetTimeStamp()
{
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	char pcstrTimeStamp[MAX_PATH];
	sprintf(pcstrTimeStamp, "%d/%d/%d %d:%d:%d.%d", sysTime.wDay, sysTime.wMonth, sysTime.wYear, sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);
	string strTimeStamp(pcstrTimeStamp);
	return strTimeStamp;
}

string Logger::GetMessageType(int iMessageType)
{
	string strMessageType = mapMessageType[iMessageType];
	return strMessageType;
}

bool Logger::IsLogFileValid()
{
	bool bReturnValue = false;
	if (m_fpFile)
	{
		bReturnValue = true;
	}
	return bReturnValue;
}

void Logger::Log(int iMessageType,const char* pcstrFormattedMessage, ...)
{
	char pcstrBuffer[MAX_MESSAGE_LENGTH];
	va_list arglist;
	va_start(arglist, pcstrFormattedMessage);
	vsprintf(pcstrBuffer, pcstrFormattedMessage, arglist);
	va_end(arglist);
	string strMessage(pcstrBuffer);
	string strTimeStamp = GetTimeStamp();
	string strMessageType = GetMessageType(iMessageType);
	//"%s\t%s\t%s\r\n", strTimeStamp.c_str(), strMessageType.c_str(), strMessage.c_str()
	EnterCriticalSection(&Logger::m_csAccessBuffer);
	m_strBuffer = m_strBuffer + strTimeStamp + "\t" + strMessageType + "\t" + strMessage + "\t\r\n";
	LeaveCriticalSection(&Logger::m_csAccessBuffer);
}

void Logger::WriteLogThread()
{
	while (true) 
	{
		EnterCriticalSection(&Logger::m_csAccessBufferCS);
		EnterCriticalSection(&Logger::m_csAccessBuffer);
		if (!m_strBuffer.empty())
		{
			if (m_fpFile) 
			{
				fprintf(m_fpFile, "%s", m_strBuffer.c_str());
				m_strBuffer.clear();
				m_strBuffer = "";
			}
		}
		LeaveCriticalSection(&Logger::m_csAccessBuffer);
		LeaveCriticalSection(&Logger::m_csAccessBufferCS);
		Sleep((DWORD)LOGGING_INTERVAL);
	}
}
