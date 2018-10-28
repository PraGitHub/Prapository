#include"logger.h"

CriticalSectionManager Logger::m_csmgrAccessBuffer;
CriticalSectionManager Logger::m_csmgrAccessBufferCS;
long double Logger::m_ldPreviousFlushTime;
mapstrstr Logger::m_mapModuleBuffer;
mapstrstr Logger::m_mapModuleFile;

Logger::Logger()
{
	Init(DEFAULT_NAME);
}

Logger::Logger(string strModuleName)
{
	if (strModuleName.empty())
	{
		strModuleName = DEFAULT_NAME;
	}
	Init(strModuleName);
}

Logger::~Logger()
{

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
	Logger::m_csmgrAccessBufferCS.Lock();
	Logger::m_csmgrAccessBuffer.Lock();
	Logger::m_mapModuleBuffer.insert(m_strModuleName, (string)"");
	Logger::m_mapModuleFile.insert(m_strModuleName, m_strLogFilePath);
	Logger::m_csmgrAccessBuffer.Unlock();
	Logger::m_csmgrAccessBufferCS.Unlock();
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
		m_csmgrAccessBufferCS.Lock();
		m_csmgrAccessBuffer.Lock();
		for (mapstrstr::iterator iterModuleBuffer = Logger::m_mapModuleBuffer.begin(); iterModuleBuffer != Logger::m_mapModuleBuffer.end(); ++iterModuleBuffer)
		{
			string strModuleName = iterModuleBuffer->first;
			string strBuffer = iterModuleBuffer->second;
			string strFilePath = m_mapModuleFile[strModuleName];
			if (!Logger::m_mapModuleBuffer[m_strModuleName].empty())
			{
				FILE* fpFile = fopen(strFilePath.c_str(), "a");
				if (fpFile)
				{
					fprintf(fpFile, "%s", Logger::m_mapModuleBuffer[m_strModuleName].c_str());
					Logger::m_mapModuleBuffer[m_strModuleName].clear();
					Logger::m_mapModuleBuffer[m_strModuleName] = "";
					fclose(fpFile);
				}
			}
		}
		m_csmgrAccessBuffer.Unlock();
		m_csmgrAccessBufferCS.Unlock();
		Sleep((DWORD)LOGGING_INTERVAL);
	}
}
