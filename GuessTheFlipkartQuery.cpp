#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


string strArrayOfQueries[] = {
    "axe deo",
    "best-seller books",
    "best seller books",
    "calvin klein",
    "camcorder",
    "camera",
    "chemistry",
    "chromebook",
    "c programming",
    "data structures algorithms",
    "dell laptops",
    "dslr canon",
    "mathematics",
    "nike-deodrant",
    "nike deodrant",
    "physics",
    "sony cybershot",
    "spoken english",
    "timex watch",
    "titan watch",
    "tommy watch",
    "written english",
    "EOA"
};

int IsThere(string strLine,string strQuery){
    if(strLine.find(strQuery)!=strLine.npos){
        return 1;
    }
    return 0;
}

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

string GetTheBestMatch(string strLine){
    int i=0;
    int iCount = 0;//this varibale is not requires
    string strBestQuery = "";
    while(true){
        string strQuery = strArrayOfQueries[i];
        string strQueryCopy = strQuery;
        if(strQuery == "EOA"){
            break;
        }
        int iCountSpaces = 0;
        int iCountOfThisQuery = 0;
        size_t iPos = -1;
        while((iPos = strQuery.find(" "))!=strQuery.npos){
            iCountSpaces++;
            string strQuerySubString = strQuery.substr(0,iPos);
            iCountOfThisQuery += IsThere(strLine,strQuerySubString);
            strQuery = strQuery.substr(iPos+1);
        }
        iCountOfThisQuery += IsThere(strLine,strQuery);
        if(iCountSpaces+1 == iCountOfThisQuery){
            strBestQuery = strQueryCopy;
            break;
        }
        //cout<<strBestQuery<<" "<<iCountOfThisQuery<<endl;
        i++;
        if(iCountOfThisQuery>iCount){
            iCount = iCountOfThisQuery;
            strBestQuery = strQueryCopy;
        }
    }
    return strBestQuery;
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
        //cout<<strLine<<endl;
        strToLower(strLine);
        string strQuery = GetTheBestMatch(strLine);
        cout<<strQuery<<endl;
    }
    return 0;
}
