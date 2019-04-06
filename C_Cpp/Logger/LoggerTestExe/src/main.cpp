#include"main.h"

void SubRoutine(int iArg,char** ppcstrArgs,string strModuleName)
{
	Logger* pLogger = new Logger(strModuleName);
	for (int i = 0; i < iArg; i++)
	{
		for (int j = 0; j < iArg; j++)
		{
			pLogger->Log(eInfo, "Arg %d : %s", i, ppcstrArgs[j]);
			Sleep(1000);
		}
		Sleep(1000);
	}
	delete pLogger;
	return;
}

int main(int iArg, char** ARGS)
{
	//system("pause");
	thread SubRoutineThread = thread(&SubRoutine, iArg, ARGS,"LoggerTest.SubRoutine");
	thread SubRoutineThread_1 = thread(&SubRoutine, iArg, ARGS, "");
	Logger* pLogger = new Logger("LoggerTest.Main");

	if (iArg == 1)
	{
		cout << "This is a test application to Logger Library (Logger.dll)" << endl;
		cout << "Arguments are passed to Logger to write into a text file" << endl;
		return 0;
	}
	
	for (int i = 0; i < iArg; i++)
	{
		pLogger->Log(eDebug, "Arg %d : %s", i, ARGS[i]);
		pLogger->Log(eVerbose, "Arg %d : %s", i, ARGS[i]);

	}
	
	SubRoutineThread.join();
	SubRoutineThread_1.join();

	delete pLogger;
	//system("pause");
}