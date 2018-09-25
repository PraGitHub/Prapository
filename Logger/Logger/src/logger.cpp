#include"logger.h"

Logger::Logger()
{
	Set(DEFAULT_NAME);
	OpenFile();
}

Logger::Logger(string strModuleName)
{
	if (strModuleName.empty())
	{
		strModuleName = DEFAULT_NAME;
	}
	Set(strModuleName);
	OpenFile();
}

Logger::~Logger()
{
	CloseFile();
}

void Logger::Set(string strModuleName)
{
	m_strModuleName = strModuleName;
	m_strLogFileName = m_strLogFileName + ".log";
	CHAR pcstrModulePath[MAX_PATH];
	GetModuleFileName(NULL, pcstrModulePath, (DWORD)MAX_PATH);
	string strLogFolder(pcstrModulePath);
	strLogFolder = strLogFolder.substr(0, strLogFolder.rfind("\\"));
	m_strLogFolder = strLogFolder;
	m_strLogFilePath = m_strLogFolder + "\\" + m_strLogFileName;
	m_ldPreviousFlushTime = GetTime();

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

void Logger::Flush()
{
	long double ldCurrentTime = GetTime();
	long double ldTimeDiff = ldCurrentTime - m_ldPreviousFlushTime;
	if (ldTimeDiff >= (long double)MAX_TIME_DIFF_BETWEEN_TWO_FLUSHES)
	{
		if (m_fpFile)
		{
			fflush(m_fpFile);
			m_ldPreviousFlushTime = ldCurrentTime;
		}
	}
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

bool Logger::Log(int iMessageType,const char* pcstrFormattedMessage, ...)
{
	bool bReturnValue = false;
	char pcstrBuffer[MAX_MESSAGE_LENGTH];
	va_list arglist;
	va_start(arglist, pcstrFormattedMessage);
	vsprintf(pcstrBuffer, pcstrFormattedMessage, arglist);
	va_end(arglist);
	string strMessage(pcstrBuffer);
	string strTimeStamp = GetTimeStamp();
	string strMessageType = GetMessageType(iMessageType);
	if (m_fpFile)
	{
		fprintf(m_fpFile, "%s\t%s\t%s\r\n", strTimeStamp.c_str(), strMessageType.c_str(), strMessage.c_str());
		Flush();
		bReturnValue = true;
	}
	return bReturnValue;
}
