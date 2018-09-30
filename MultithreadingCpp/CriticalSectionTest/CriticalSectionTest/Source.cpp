#include<iostream>
#include<thread>
#include<Windows.h>
using namespace std;

#define MAX_THREADS 500

class CriticalSectionTest
{
private:
	CRITICAL_SECTION m_csTemp;
	int m_iVar;
	bool IsValidCriticalSection();
public:
	CriticalSectionTest();
	~CriticalSectionTest();
	void Write();
	void Read(int iVal);
};

CriticalSectionTest :: CriticalSectionTest()
{
	InitializeCriticalSection(&m_csTemp);
	return;
	while (true)
	{
		unsigned long ulAddress = (unsigned long)(m_csTemp.DebugInfo);
		if (ulAddress > NULL)// because it will be 0x0000....0 or 0xffff....f
		{
			break;
		}
		else
		{
			cout << "CriticalSectionTest :: CriticalSectionTest :: DebugInfo is NULL" << endl;
		}
		Sleep(1000);
	}
	
	m_iVar = -1;
}

CriticalSectionTest::~CriticalSectionTest()
{
	DeleteCriticalSection(&m_csTemp);
}

bool CriticalSectionTest::IsValidCriticalSection()
{
	return true;
	bool bRetVal = true;
	unsigned long ulAddress = (unsigned long)m_csTemp.DebugInfo;
	if (ulAddress <= NULL)// because it will be 0x0000....0 or 0xffff....f
	{
		cout << "CriticalSectionTest :: Write :: Critical Section Debug Info is NULL" << endl;
		bRetVal = false;
	}
	//cout << "CriticalSectionTest :: Write :: Critical Section Debug Info Type = " << m_csTemp.DebugInfo->Type << endl;
	return bRetVal;
}

void CriticalSectionTest::Write()
{
	if (IsValidCriticalSection() == false)
	{
		return;
	}
	EnterCriticalSection(&m_csTemp);
	cout << "CriticalSectionTest :: Write :: iVar = " << m_iVar << endl;
	LeaveCriticalSection(&m_csTemp);
}

void CriticalSectionTest::Read(int iVal)
{
	if (IsValidCriticalSection() == false)
	{
		return;
	}
	EnterCriticalSection(&m_csTemp);
	m_iVar = iVal;
	LeaveCriticalSection(&m_csTemp);
}

void Read(CriticalSectionTest* pCriticalSectionTest,int iVal)
{
	pCriticalSectionTest->Read(iVal);
	//Sleep(1);
	return;
}

void Write(CriticalSectionTest* pCriticalSectionTest,int iNumThreads)
{
	for (int i = 0; i < iNumThreads; i++)
	{
		pCriticalSectionTest->Write();
		//Sleep(1);
	}
	return;
}

int main(int iArg, char** ARGS)
{
	if (iArg != 2)
	{
		cout << "Specify number of threads" << endl;
		cout << "Eg : CriticalSectionTest.exe 10" << endl;
		system("pause");
		return 0;
	}
	int iNumThreads = atoi(ARGS[1]);
	if (iNumThreads > (int)MAX_THREADS)
	{
		cout << "Number of threads must be less than " << (int)MAX_THREADS << endl;
	}
	CriticalSectionTest* pCriticalSectionTest = new CriticalSectionTest();

	thread thrWrite(Write, pCriticalSectionTest, iNumThreads);
	thread thrArrayRead[MAX_THREADS];
	for (int i = 0; i < iNumThreads; i++)
	{
		thrArrayRead[i] = thread(Read, pCriticalSectionTest, i);
	}

	system("pause");
	return 0;
}