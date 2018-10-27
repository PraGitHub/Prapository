#include"main.h"

void SubRoutine(int iArg,char** ppcstrArgs)
{
	Logger* pLogger = new Logger("LoggerTextExe.SubRoutine");
	for (int i = 0; i < iArg; i++)
	{
		Logger::Log(eInfo, "Arg %d : %s", i, ppcstrArgs[i]);
	}
	return;
}

int main(int iArg, char** ARGS)
{
	system("pause");
	Logger::Logger("LoggerTest");
	if (iArg == 1)
	{
		cout << "This is a test application to Logger Library (Logger.dll)" << endl;
		cout << "Arguments are passed to Logger to write into a text file" << endl;
		return 0;
	}
	
	for (int i = 0; i < iArg; i++)
	{
		Logger::Log(eInfo, "Arg %d : %s", i, ARGS[i]);
	}
	SubRoutine(iArg, ARGS);
	return 0;
}