#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

string DecideTheIts(string strLine){
    size_t iPos = -1;
    iPos = strLine.find("???");
    if(iPos == 0){
        return "It's";
    }
    string strBehind = strLine.substr(iPos-1,1);
    if(strBehind == "."||strBehind=="?"||strBehind=="!"){
        return "It's";
    }
    return "Its";
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int iN;
    cin>>iN;
    for(int i=0;i<=iN;i++){
        string strLine;
        getline(cin,strLine);
        if(i==0){
            continue;
        }
        string strOutput = "";
        strOutput = DecideTheIts(strLine);
        cout<<strOutput<<endl;
    }
    return 0;
}
