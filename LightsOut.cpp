#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int iPlayer;
    cin>>iPlayer;
    for(int i=0;i<8;i++){
        string strLine;
        cin>>strLine;
        size_t iPos = -1;
        if((iPos = strLine.find("1"))!=strLine.npos){
            cout<<i<<" "<<iPos<<endl;
            break;
        }
    }
    return 0;
}
