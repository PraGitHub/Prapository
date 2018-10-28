#pragma once

#include<iostream>
#include<Windows.h>
using namespace std;

class CriticalSectionManager
{
	CRITICAL_SECTION m_csData;
public:
	CriticalSectionManager();
	~CriticalSectionManager();
	void Lock();
	void Unlock();
};
