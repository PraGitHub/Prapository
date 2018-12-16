#include"CriticalSectionManager.h"

CriticalSectionManager::CriticalSectionManager()
{
	InitializeCriticalSection(&m_csData);
}

CriticalSectionManager::~CriticalSectionManager()
{
	DeleteCriticalSection(&m_csData);
}

void CriticalSectionManager::Lock()
{
	EnterCriticalSection(&m_csData);
}

void CriticalSectionManager::Unlock()
{
	LeaveCriticalSection(&m_csData);
}