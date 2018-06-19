#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

void strToLower(string &strIn){
    char* ctemp = (char*)strIn.c_str();
    while(*ctemp!=0){
        //cout<<*ctemp<<endl;
        if(*ctemp >= 'A' && *ctemp <= 'Z'){
            *ctemp = *ctemp - 'A' + 'a';
        }
        ctemp++;
    }
}

int CountSubStringInString(string strString, strSubString){
    int iCount = 0;
    int iPos = -1;
    while((iPos = strString.find(strSubString))>-1){
        iCount++;
        strString = strString.substr(iPos+1);
    }
    return iCount;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iNumLines;
    cin>>iNumLines;
    for(int i=0;i<(2*iNumLines+1);i++){
        string strLine;
        int iCountOfa = 0;
        int icountOfan = 0;
        int iCountOfthe = 0;
        int iCountOfDate = 0;
        getline(cin,strLine);
        if(strLine==""){
            continue;
        }
        strToLower(strLine);
        //cout<<strLine.c_str()<<endl;
        iCountOfa = CountSubStringInString(strLine,"a ");//need to improvise
        iCountOfan = CountSubStringInString(strLine,"an ");//need to improvise
        iCountOfthe = CountSubStringInString(strLine,"the ");//need to improvise
        
        cout<<iCountOfa<<endl<<iCountOfan<<endl<<iCountOfthe<<endl<<iCountOfDate<<endl;
    }
    return 0;
}
