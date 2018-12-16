#include"main.h"

void SubRoutine(int iArg,char** ppcstrArgs, CRITICAL_SECTION *pcsMainSubRoutine)
{
	EnterCriticalSection(pcsMainSubRoutine);
	Logger* pLogger = new Logger("LoggerTest.SubRoutine");
	for (int i = 0; i < iArg; i++)
	{
		pLogger->Log(eInfo, "Arg %d : %s", i, ppcstrArgs[i]);
	}
	LeaveCriticalSection(pcsMainSubRoutine);
	return;
}

int main(int iArg, char** ARGS)
{
	system("pause");
	CRITICAL_SECTION csMainSubRoutine;
	InitializeCriticalSection(&csMainSubRoutine);
	thread SubRoutineThread = thread(&SubRoutine, iArg, ARGS, &csMainSubRoutine);
	Logger* pLogger = new Logger("LoggerTest.Main");

	if (iArg == 1)
	{
		cout << "This is a test application to Logger Library (Logger.dll)" << endl;
		cout << "Arguments are passed to Logger to write into a text file" << endl;
		return 0;
	}
	
	for (int i = 0; i < iArg; i++)
	{
		pLogger->Log(eInfo, "Arg %d : %s", i, ARGS[i]);
	}
	
	EnterCriticalSection(&csMainSubRoutine);
	LeaveCriticalSection(&csMainSubRoutine);
	DeleteCriticalSection(&csMainSubRoutine);
}