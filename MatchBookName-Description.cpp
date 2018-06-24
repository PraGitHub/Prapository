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
            strArrayBookDes[i-2-iN]=strLine;
        }
    }
    for(int i=0;i<iN;i++){
        cout<<"Name="<<strArrayBookNames[i]<<";"<<"Des="<<strArrayBookDes[i]<<endl;
    }
    
    return 0;
}
