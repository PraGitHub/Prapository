#include"CriticalSectionManager.h"

CriticalSectionManager::CriticalSectionManager()
{
#ifdef _WIN32 || WIN32
	InitializeCriticalSection(&m_csData);
#elif
#endif
}

CriticalSectionManager::~CriticalSectionManager()
{
#ifdef _WIN32 || WIN32
	DeleteCriticalSection(&m_csData);
#elif
#endif
}

void CriticalSectionManager::Lock()
{
#ifdef _WIN32 || WIN32
	EnterCriticalSection(&m_csData);
#elif
	m_csData.lock();
#endif
}

void CriticalSectionManager::Unlock()
{
#ifdef _WIN32 || WIN32
	LeaveCriticalSection(&m_csData);
#elif
	m_csData.unlock();
#endif
}