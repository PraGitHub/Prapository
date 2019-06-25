#include <iostream>

using namespace std;

enum HR{
    HR_OK = 0,
    HR_ERROR = -1,
};

int main()
{
    int m = HR_OK;
    int n = HR_ERROR;
    if(m)
    {
        cout<< "m = "<<m<<endl;
    }
    if(n)
    {
        cout<<"n = "<<n<<endl;
    }
    if(0)
    {
        cout<<0<<endl;
    }
    if(1)
    {
        cout<<1<<endl;
    }
    if(-1)
    {
        cout<<-1<<endl;
    }
}
