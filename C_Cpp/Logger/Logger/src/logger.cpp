#include"logger.h"

mutex Logger::m_mtxAccessBuffer;
mutex Logger::m_mtxAccessFile;
long double Logger::m_ldPreviousFlushTime;
mapstrstr Logger::m_mapModuleBuffer;
FILE* Logger::m_fpLogFile = NULL;
string Logger::m_strLogFileName;
string Logger::m_strLogFilePath;
string Logger::m_strLogFolder;
thread Logger::m_threadWriteLog;
atomic_bool Logger::m_abIsFirstInstance{ true };
int Logger::m_iMaxLogLevel;
int Logger::m_iMaxFileCount;
long Logger::m_lMaxFileSize;
DWORD Logger::m_dwLoggingInterval;
strings Logger::vecLogFilePaths;

Logger::Logger()
{
	Init(DEFAULT_NAME, eInfo, LOGGING_INTERVAL);
	OpenFile();
}

Logger::Logger(string strModuleName, int iLogLevel, DWORD dwLoggingInterval)
{
	if (strModuleName.empty())
	{
		strModuleName = DEFAULT_NAME;
	}
	Init(strModuleName, iLogLevel, dwLoggingInterval);
	OpenFile();
}

Logger::~Logger()
{
	Logger::WriteToFile(m_strModuleName);
}

void Logger::Init(string strModuleName, int iLogLevel, DWORD dwLoggingInterval)
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
	{
		autoLockUnlockMutex lock_unlock(m_mtxAccessBuffer);
		Logger::m_mapModuleBuffer.insert(mapstrstr::value_type(strModuleName, (string)""));
		if (Logger::m_abIsFirstInstance.load(memory_order_acquire) == true)
		{
			m_threadWriteLog = thread(&Logger::WriteLogThread);
			m_iMaxLogLevel = iLogLevel; 
			m_dwLoggingInterval = dwLoggingInterval;
			m_lMaxFileSize = (long)MAX_FILE_SIZE;
			m_iMaxFileCount = (int)MAX_NUM_FILES;
			FillFilePathVector();
			Logger::m_abIsFirstInstance.store(false, memory_order_release);
		}
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

void Logger::FillFilePathVector()
{
	int iCount = 0;
	while (iCount < m_iMaxFileCount)
	{
		string strLogFilePath = m_strLogFolder + "\\" + m_strLogFileName + to_string(iCount);
		vecLogFilePaths.push_back(strLogFilePath);
		iCount++;
	}
}

void Logger::OpenFile()
{
	autoLockUnlockMutex lock_unlock(m_mtxAccessFile);
	if (m_fpLogFile == NULL)
	{
		m_fpLogFile = fopen(m_strLogFilePath.c_str(), "a");
	}
}

void Logger::CloseFile()
{
	autoLockUnlockMutex lock_unlock(m_mtxAccessFile);
	if (m_fpLogFile)
	{
		fclose(m_fpLogFile);
		m_fpLogFile = NULL;
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
	if (iMessageType > m_iMaxLogLevel)
	{
		return;
	}

	char pcstrBuffer[MAX_MESSAGE_LENGTH];
	va_list arglist;
	va_start(arglist, pcstrFormattedMessage);
	vsprintf(pcstrBuffer, pcstrFormattedMessage, arglist);
	va_end(arglist);
	string strMessage(pcstrBuffer);
	string strTimeStamp = GetTimeStamp();
	string strMessageType = GetMessageType(iMessageType);
	
	//"%s\t%s\t%s\r\n", strTimeStamp.c_str(), strMessageType.c_str(), strMessage.c_str()
	{
		autoLockUnlockMutex lock_unlock(m_mtxAccessBuffer);
		Logger::m_mapModuleBuffer[m_strModuleName] = Logger::m_mapModuleBuffer[m_strModuleName] + strTimeStamp + "\t" + m_strModuleName + "\t" + m_strThreadId + "\t" + strMessageType + "\t" + strMessage + "\t\r\n";
	}
}

void Logger::WriteLogThread()
{
	while (true) 
	{
		Logger::WriteToFile("");
		Sleep(m_dwLoggingInterval);
	}
}

void Logger::CheckFileSize()
{
	// this is a part of critical section and for sure m_fpLogFile is a valid pointer.
	// this function is called only if m_fpLogFile is valid pointer. 
	long lFileSize = ftell(m_fpLogFile);
	if (lFileSize >= m_lMaxFileSize)
	{
		// need to work out the logic
	}
}

void Logger::WriteToFile(string strModuleName, string strBuffer)
{
	if (strBuffer.empty())
	{
		return;
	}
	{
		autoLockUnlockMutex lock_unlock(m_mtxAccessFile);
		if (m_fpLogFile)
		{
			fprintf(m_fpLogFile, "%s", strBuffer.c_str());
			fflush(m_fpLogFile);
			m_mapModuleBuffer[strModuleName].clear();
			m_mapModuleBuffer[strModuleName] = "";
			CheckFileSize();
		}
	}
}

void Logger::WriteToFile(string strModuleName)
{
	autoLockUnlockMutex lock_unlock(m_mtxAccessBuffer);
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
}
