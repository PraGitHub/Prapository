#include<iostream>
#include<chrono>
#include<cstdint>
#include<map>
using namespace std;

//http://cpp.sh/7cehe

static char ten_chars[] = { "ilrawjoagk" };
static char five_chars[] = {"sptde"}; // s = sapta, p = pancha, t = threya, d = dwe, e = eka

string getRandString()
{
	string strRandString;
	using namespace std::chrono;
	uint64_t uiTime = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
	uint64_t uiTemp = uiTime;
	while (uiTemp)
	{
		int iPos = uiTemp % 9;
		char c = ten_chars[iPos];
		string strChar(1,c);
		strRandString = strRandString + strChar;

		if (uiTemp % 7 == 0)
        {
            strRandString = strRandString + string(1,five_chars[0]);
        }
        else if (uiTemp % 5 == 0)
        {
            strRandString = strRandString + string(1,five_chars[1]);
        }
        else if (uiTemp % 3 == 0)
        {
            strRandString = strRandString + string(1,five_chars[2]);
        }
        else if (uiTemp % 2 == 0)
        {
            strRandString = strRandString + string(1,five_chars[3]);
        }
        else
        {
            strRandString = strRandString + string(1,five_chars[4]);
        }

		uiTemp = uiTemp / 9; 
	}
	
	strRandString = strRandString.substr(0,20);
	
    uiTemp = uiTime;
	while (uiTemp)
	{
		int iPos = uiTemp % 10;
		char c = ten_chars[iPos];
		string strChar(1,c);
		strRandString = strRandString + strChar;

		if (uiTemp % 7 == 0)
        {
            strRandString = strRandString + string(1,five_chars[0]);
        }
        else if (uiTemp % 5 == 0)
        {
            strRandString = strRandString + string(1,five_chars[1]);
        }
        else if (uiTemp % 3 == 0)
        {
            strRandString = strRandString + string(1,five_chars[2]);
        }
        else if (uiTemp % 2 == 0)
        {
            strRandString = strRandString + string(1,five_chars[3]);
        }
        else
        {
            strRandString = strRandString + string(1,five_chars[4]);
        }

		uiTemp = uiTemp / 10; 
	}
	strRandString = strRandString.substr(0,40);
	//cout<<"strRandString = "<<strRandString<<endl;
	cout<<strRandString.length()<<" "<<strRandString<<endl;
	return strRandString;
}

int main()
{
    map<string,bool> mapstr;
    string strTemp;
    for(int i=0;i<50000;i++)
    {
       strTemp = getRandString();
       if(mapstr.find(strTemp)!=mapstr.end())
       {
           cout<<"string found"<<endl;
           cout<<"strTemp = "<<strTemp<<endl;
           cout<<"i = "<<i<<endl;
           return 0;
       }
       else
       {
           mapstr.insert(make_pair(strTemp,true));
       }
    }
    return 0;
}
