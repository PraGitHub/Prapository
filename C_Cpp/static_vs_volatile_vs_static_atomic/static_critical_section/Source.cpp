#include<iostream>
#include<Windows.h>
#include<thread>
#include<vector>
#include<atomic>
using namespace std;

static string strTemp = "";
static CRITICAL_SECTION csTemp;

void temp(int i)
{
	
	static atomic_bool abIsInitialised{ false };
	//if (abIsInitialised.is_lock_free() == true)
	//{
	//	cout << "temp :: abIsInitialised.is_lock_free() = " << "true" << endl;
	//}
	//else
	//{
	//	cout << "temp :: abIsInitialised.is_lock_free() = " << "false" << endl;
	//}
	if (abIsInitialised.load(memory_order_acquire) == false)
	{
		InitializeCriticalSection(&csTemp);
		abIsInitialised.store(true, memory_order_release);
		cout << (const char*)__TIMESTAMP__ <<  " :: " <<i << " :: temp :: Initialised critical section " << endl;
	}
	
	
	/*
	static atomic_int aiInit{ 0 };
	if (aiInit.load(memory_order_relaxed) == 0)
	{
		InitializeCriticalSection(&csTemp);
		aiInit.store(1 + 2*i, memory_order_relaxed);
		cout << i << " :: temp :: Initialised critical section " << endl;
	}
	*/
	/*
	static volatile bool vbIsInitialised = false;
	if (vbIsInitialised == false)
	{
		InitializeCriticalSection(&csTemp);
		vbIsInitialised = true;
		cout << i << " :: temp :: Initialised critical section " << endl;
	}
	*/
	

	/*
	static bool bIsInitialised = false;
	if (bIsInitialised == false)
	{
		InitializeCriticalSection(&csTemp);
		bIsInitialised = true;
		cout << i << " :: temp :: Initialised critical section " << endl;
	}
	*/
	cout <<(const char*)__TIMESTAMP__<<" :: " << i << " :: temp :: Waiting on critical section " << endl;
	EnterCriticalSection(&csTemp);
	cout << (const char*)__TIMESTAMP__ << " :: " << i << " :: temp :: Entered critical section " << endl;
	LeaveCriticalSection(&csTemp);
	cout << (const char*)__TIMESTAMP__ << " :: " << i << " :: temp :: Left critical section " << endl;
	return;
}

int main()
{
	
	vector <thread*> pth;
	for (int i = 0; i < 10; i++)
	{
		pth.push_back(new thread(temp, i));
		pth.push_back(new thread(temp, i*10));
		//pth.push_back(new thread(temp, i * 100));
		//pth.push_back(new thread(temp, i * 1000));
	
		//Sleep(10);
	}
	Sleep(1000);
	//system("pause");
}