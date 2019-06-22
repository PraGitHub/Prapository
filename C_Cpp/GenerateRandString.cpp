#include<iostream>
#include<chrono>
#include<cstdint>
using namespace std;

//executed in cpp.sh site - http://cpp.sh/4skv3

static char ten_chars[] = { "ilrawjoagk" };

string getRandString()
{
	string strRandString;
	using namespace std::chrono;
	uint64_t uiTime = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
	uint64_t uiTemp = uiTime;
	while (uiTemp)
	{
		int iPos = uiTemp % 10;
		char c = ten_chars[iPos];
		string strChar((const char*)&c);
		strRandString = strRandString + strChar;
		if (uiTemp % 7 == 0)
		{
			strRandString = strRandString + "7";
		}
		else if (uiTemp % 5 == 0)
		{
			strRandString = strRandString + "5";
		}
		else if (uiTemp % 3 == 0)
		{
			strRandString = strRandString + "3";
		}
		else if (uiTemp % 2 == 0)
		{
			strRandString = strRandString + "2";
		}
		else
		{
			strRandString = strRandString + "p";
		}
		uiTemp = uiTemp / 10; 
	}
	cout<<"strRandString = "<<strRandString<<endl;
	return strRandString;
}

int main()
{
    cout<<getRandString()<<endl;
    return 0;
}
