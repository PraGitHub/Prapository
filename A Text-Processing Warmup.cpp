#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

string strArrayMonthShort[12] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};

string strArrayMonth[12] ={"january","february","march","april","may","june","july","august","september","october","november","december"};

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

int CountSubStringInString(string strString, string strSubString){
    int iCount = 0;
    int iPos = -1;
    while((iPos = strString.find(strSubString))>-1){
        iCount++;
        strString = strString.substr(iPos+1);
    }
    return iCount;
}

int CountMonthStrings(string strLine){
    int iCount = 0;
    int iCountFull = 0;
    int iCountShort = 0;
    cout<<"CountMonthStrings :: strLine = "<<strLine.c_str()<<endl;
    for(int i=0;i<12;i++){
        if(strLine.find(strArrayMonth[i])>-1){
            iCountFull++;
        }

        if(strLine.find(strArrayMonthShort[i])>-1){
            iCountShort++;
        }
    }
    iCount = iCountFull + iCount;
    return iCount;
}

int CountFourDigitSets(string strLine){
    char* pcstrLine = (char*) strLine.c_str();
    int iCount = 0;
    int iCountTemp = 0;
    bool bIsPreviousCount4 = false;
    while(*pcstrLine!=0){
        if(*pcstrLine>='0' && *pcstrLine<='9'){
            iCountTemp++;
        }
        else{
            iCountTemp = 0;
        }
        if(iCountTemp==4){
            bIsPreviousCount4 = true;
            //cout<<"iCountTemp=4"<<endl;
        }
        if(bIsPreviousCount4 == true && iCountTemp!=4){
            //cout<<"bIsPreviousCount4=true ; iCountTemp = "<<iCountTemp<<endl;
            if(iCountTemp==0){
                iCount++;
            }
            bIsPreviousCount4 = false;
        }
        pcstrLine++;
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
        int iCountOfan = 0;
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
        
        //cout<<iCountOfa<<endl<<iCountOfan<<endl<<iCountOfthe<<endl<<iCountOfDate<<endl;
        cout<<CountFourDigitSets(strLine)<<";"<<CountMonthStrings(strLine)<<endl;
    }
    return 0;
}
