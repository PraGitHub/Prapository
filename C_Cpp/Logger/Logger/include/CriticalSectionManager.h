#pragma once

#include<iostream>
#ifdef _WIN32 || WIN32
#include<Windows.h>
#elif
#include<mutex>
#endif
using namespace std;

class CriticalSectionManager
{
	#ifdef _WIN32 || WIN32
	CRITICAL_SECTION m_csData;
	#elif
	mutex m_csData;
	#endif
public:
	CriticalSectionManager();
	~CriticalSectionManager();
	void Lock();
	void Unlock();
};
