#include"logger.h"

CriticalSectionManager Logger::m_csmgrAccessBuffer;
long double Logger::m_ldPreviousFlushTime;
mapstrstr Logger::m_mapModuleBuffer;
mapstrFile Logger::m_mapModuleFile;
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
	Logger::RemoveFileFromMap(m_strModuleName);
	Logger::WriteToFile(m_strModuleName);
	CloseFile();
}

void Logger::Init(string strModuleName)
{
	m_strModuleName = strModuleName;
	m_strLogFileName = m_strModuleName + ".log";
	CHAR pcstrModulePath[MAX_PATH];
	GetModuleFileName(NULL, pcstrModulePath, (DWORD)MAX_PATH);
	string strLogFolder(pcstrModulePath);
	strLogFolder = strLogFolder.substr(0, strLogFolder.rfind("\\"));
	m_strLogFolder = strLogFolder;
	m_strLogFilePath = m_strLogFolder + "\\" + m_strLogFileName;
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
	m_fpLogFile = fopen(m_strLogFilePath.c_str(), "a");
	if (m_fpLogFile)
	{
		Logger::m_csmgrAccessBuffer.Lock();
		Logger::m_mapModuleFile.insert(mapstrFile::value_type(m_strModuleName,m_fpLogFile));
		Logger::m_csmgrAccessBuffer.Unlock();
	}
}

void Logger::CloseFile()
{
	if (m_fpLogFile)
	{
		fclose(m_fpLogFile);
	}
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
	Logger::m_mapModuleBuffer[m_strModuleName] = Logger::m_mapModuleBuffer[m_strModuleName] + strTimeStamp + "\t" + strMessageType + "\t" + strMessage + "\t\r\n";
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

void Logger::WriteToFile(string strInputModuleName)
{
	m_csmgrAccessBuffer.Lock();
	for (mapstrstr::iterator iterModuleBuffer = Logger::m_mapModuleBuffer.begin(); iterModuleBuffer != Logger::m_mapModuleBuffer.end(); ++iterModuleBuffer)
	{
		string strModuleName = iterModuleBuffer->first;
		if ((!(strInputModuleName == "")) && (strModuleName == strInputModuleName))
		{
			continue;
		}
		string strBuffer = iterModuleBuffer->second;
		if (strBuffer.empty())
		{
			continue;
		}
		FILE* fpLogFile = m_mapModuleFile[strModuleName];
		fprintf(fpLogFile, "%s", strBuffer.c_str());
		m_mapModuleBuffer[strModuleName].clear();
		m_mapModuleBuffer[strModuleName] = "";
	}
	m_csmgrAccessBuffer.Unlock();
}

void Logger::RemoveFileFromMap(string strModuleName)
{
	m_csmgrAccessBuffer.Lock();
	for (mapstrFile::iterator iterModuleFile = m_mapModuleFile.begin(); iterModuleFile != m_mapModuleFile.end(); ++iterModuleFile)
	{
		if (strModuleName == iterModuleFile->first)
		{
			m_mapModuleFile.erase(iterModuleFile);
			break;
		}
	}
	m_csmgrAccessBuffer.Unlock();
}