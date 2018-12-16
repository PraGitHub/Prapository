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

int FindTheBookForDescription(string strDescription,string* strArrayBookNames,int iN){
    int iValue = 0;
    int iTempValue = 0;
    int iOutput = -1;
    for(int i=0;i<iN;i++){
        iTempValue = 0;
        string strBookName = strArrayBookNames[i];
        size_t iPos = -1;
        while((iPos = strBookName.find(" "))!=strBookName.npos){
            string strToFind = strBookName.substr(0,iPos);
            if(strDescription.find(strToFind)!=strDescription.npos){
                iTempValue++;
            }
            strBookName = strBookName.substr(iPos+1);
        }
        if(iTempValue>iValue){
            iValue = iTempValue;
            iOutput = i+1;
        }
    }
    return iOutput;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iN;
    cin>>iN;
    string strArrayBookNames[iN];
    string strArrayBookDes[iN];
    for(int i=0;i<=2*iN+1;i++){
        string strLine;
        getline(cin,strLine);
        if(i==0 || i==iN+1){
            continue;
        }
        strToLower(strLine);
        if(i<=iN){
            strArrayBookNames[i-1]=strLine;
        }
        if(i>iN+1){
            int iOutput = -1;
            iOutput = FindTheBookForDescription(strLine,strArrayBookNames,iN);
            cout<<iOutput<<endl;
        }
    }
    return 0;
}
