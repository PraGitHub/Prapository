#include"logger.h"

CriticalSectionManager Logger::m_csmgrAccessBuffer;
long double Logger::m_ldPreviousFlushTime;
mapstrstr Logger::m_mapModuleBuffer;
FILE* Logger::m_fpLogFile = NULL;
string Logger::m_strLogFileName;
string Logger::m_strLogFilePath;
string Logger::m_strLogFolder;
thread Logger::m_threadWriteLog;
bool Logger::m_bIsFirstInstance = true;

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
	Logger::WriteToFile(m_strModuleName);
	CloseFile();
	OpenFile();
}

void Logger::Init(string strModuleName)
{
	m_strModuleName = strModuleName;
	thread::id tidThisThread = this_thread::get_id();
	ostringstream oss;
	oss << tidThisThread;
	m_strThreadId = oss.str();
	if (m_strLogFileName.empty())
	{
		CHAR pcstrModulePath[MAX_PATH];
		GetModuleFileName(NULL, pcstrModulePath, (DWORD)MAX_PATH);
		string strLogFolder(pcstrModulePath);
		size_t iPos = strLogFolder.rfind("\\");
		m_strLogFileName = strLogFolder.substr(iPos + 1);
		m_strLogFileName = m_strLogFileName.substr(0, m_strLogFileName.find(".exe"));
		m_strLogFileName = m_strLogFileName + ".log";
		strLogFolder = strLogFolder.substr(0, iPos);
		m_strLogFolder = strLogFolder;
		m_strLogFilePath = m_strLogFolder + "\\" + m_strLogFileName;
	}
	m_ldPreviousFlushTime = GetTime();
	Logger::m_csmgrAccessBuffer.Lock();
	Logger::m_mapModuleBuffer.insert(mapstrstr::value_type(strModuleName, (string)""));
	if (Logger::m_bIsFirstInstance)
	{
		m_threadWriteLog = thread(&Logger::WriteLogThread);
		Logger::m_bIsFirstInstance = false;
	}
	Logger::m_csmgrAccessBuffer.Unlock();
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

void Logger::OpenFile()
{
	m_csmgrAccessBuffer.Lock();
	if (m_fpLogFile == NULL)
	{
		m_fpLogFile = fopen(m_strLogFilePath.c_str(), "a");
	}
	m_csmgrAccessBuffer.Unlock();
}

void Logger::CloseFile()
{
	m_csmgrAccessBuffer.Lock();
	if (m_fpLogFile)
	{
		fclose(m_fpLogFile);
	}
	m_csmgrAccessBuffer.Unlock();
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
	m_csmgrAccessBuffer.Lock();
	Logger::m_mapModuleBuffer[m_strModuleName] = Logger::m_mapModuleBuffer[m_strModuleName] + strTimeStamp + "\t" + m_strModuleName + "\t" + m_strThreadId + "\t" + strMessageType + "\t" + strMessage + "\t\r\n";
	m_csmgrAccessBuffer.Unlock();
}

void Logger::WriteLogThread()
{
	while (true) 
	{
		Logger::WriteToFile("");
		Sleep((DWORD)LOGGING_INTERVAL);
	}
}

void Logger::WriteToFile(string strModuleName, string strBuffer)
{
	if (strBuffer.empty())
	{
		return;
	}
	if (m_fpLogFile)
	{
		fprintf(m_fpLogFile, "%s", strBuffer.c_str());
		m_mapModuleBuffer[strModuleName].clear();
		m_mapModuleBuffer[strModuleName] = "";
	}
}

void Logger::WriteToFile(string strModuleName)
{
	m_csmgrAccessBuffer.Lock();
	string strBuffer;
	if (!strModuleName.empty())
	{
		strBuffer = m_mapModuleBuffer[strModuleName];
		WriteToFile(strModuleName, strBuffer);
	}
	else
	{
		for (mapstrstr::iterator iterModuleBuffer = Logger::m_mapModuleBuffer.begin(); iterModuleBuffer != Logger::m_mapModuleBuffer.end(); ++iterModuleBuffer)
		{
			strModuleName = iterModuleBuffer->first;
			strBuffer = iterModuleBuffer->second;
			WriteToFile(strModuleName, strBuffer);
		}
	}
	m_csmgrAccessBuffer.Unlock();
}
