#include<iostream>
#include<chrono>
#include<cstdint>
#include<map>
using namespace std;

static char chars[] = {"QWERTYUIOPASDFGHJKLZXCVBNM1234567890qwertyuiopasdfghjklzxcvbnm"};

static char magical_ten_chars[] = { "ilrawjoagk" };

static char magical_five_chars[] = {"sptde"}; // s = sapta, p = pancha, t = threya, d = dwe, e = eka

string getRandString(int len = 40)
{
	string randString = "";
	using namespace std::chrono;
	uint64_t nanoTime = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    uint tenPos = nanoTime % 10;
    uint64_t start = nanoTime/magical_ten_chars[tenPos];
    for(uint64_t i=start; i <= start + len; i++)
    {
        uint64_t num = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count() + i;
        if(num % 7 == 0)
        {
            num = num * magical_five_chars[0];
        }
        else if(num % 5 == 0)
        {
            num = num * magical_five_chars[1];
        }
        else if(num % 3 == 0)
        {
            num = num * magical_five_chars[2];
        }
        else if(num % 2 == 0)
        {
            num = num * magical_five_chars[3];
        }
        else
        {
            num = num * magical_five_chars[4];
        }
        int charPos = num % 62;
        randString = randString + string(1, chars[charPos]);
    }
    return randString;
}

int main()
{
    map<string,bool> mapstr;
    string strTemp;
    int iMax = 0;
    int iLen = 0;
    cout<<"Enter number of tries :"<<endl;
    cin>>iMax;
    cout<<"Enter string length :"<<endl;
    cin>>iLen;
    for(int i=0;i<iMax;i++)
    {
       strTemp = getRandString(iLen);
       cout<<i+1<<" "<<strTemp<<endl;
       if(mapstr.find(strTemp)!=mapstr.end())
       {
           cout<<"string found"<<endl;
           cout<<"strTemp = "<<strTemp<<endl;
           cout<<"i = "<<i<<endl;
           break;
       }
       else
       {
           mapstr.insert(make_pair(strTemp,true));
       }
    }
    cout<<"map size = "<<mapstr.size()<<endl;
    return 0;
}