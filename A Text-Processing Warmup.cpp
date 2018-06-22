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

//This will also check the chaacter immediately before the substring.
//If that character is not an alphabet then only it counts.
int CountSubStringInString(string strString, string strSubString){
    int iCount = 0;
    size_t iPos = -1;
    while((iPos = strString.find(strSubString))!=strString.npos){
        if(iPos == (size_t)0){
            iCount++;
        }
        else{
            string strTemp = strString.substr(iPos-1,1);
            char* cTemp = (char*)strTemp.c_str();
            //cout<<"CountSubStringInString :: "<<*cTemp<<endl;
            if(*cTemp<'a'||*cTemp>'z'){
                iCount++;
            }
        }
        strString = strString.substr(iPos+1);
    }
    return iCount;
}

//There is no point in countng full month string occurances when counting short month string occurances.
int CountMonthStrings(string strLine){
    int iCount = 0;
    for(int i=0;i<12;i++){
        string strTempLine = strLine;
        size_t iPos = -1;
        while((iPos = strTempLine.find(strArrayMonthShort[i]))!=strTempLine.npos){
            iCount++;
            strTempLine = strTempLine.substr(iPos+1);
        }
    }
    return iCount;
}

int CountNDigitSets(string strLine,int iN){
    char* pcstrLine = (char*) strLine.c_str();
    int iCount = 0;
    int iCountTemp = 0;
    bool bIsPreviousCountN = false;
    while(*pcstrLine!=0){
        if(*pcstrLine>='0' && *pcstrLine<='9'){
            iCountTemp++;
        }
        else{
            iCountTemp = 0;
        }
        if(iCountTemp==iN){
            bIsPreviousCountN = true;
            //cout<<"iCountTemp=4"<<endl;
        }
        if(bIsPreviousCountN == true && iCountTemp!=iN){
            //cout<<"bIsPreviousCount4=true ; iCountTemp = "<<iCountTemp<<endl;
            if(iCountTemp==0){
                iCount++;
            }
            bIsPreviousCountN = false;
        }
        pcstrLine++;
    }
    return iCount;
}

int DecideCountOfDate(int iCount4Digit, int iCount2Digit, int iCountMonth){
    if(iCount4Digit == 0 || iCount2Digit == 0 || iCountMonth == 0){
        return 0;
    }
    /*
    if(iCount4Digit == iCount2Digit){
        if(iCountMonth>=iCount2Digit){
            return iCount2Digit;
        }
        else{
            return iCountMonth;
        }
    }
    else{
        int iLesserBetween4And2;
        if(iCount4Digit<=iCount2Digit){
            iLesserBetween4And2 = iCount4Digit;
        }
        else{
            iLesserBetween4And2 = iCount2Digit;
        }
        if(iLesserBetween4And2<=iCountMonth){
            return iLesserBetween4And2;
        }
        else{
            retrun iCountMonth;
        }
    }
    */
    //Above commented logic is same as below (least of 3)
    if(iCount4Digit<=iCount2Digit && iCount4Digit<=iCountMonth){
        return iCount4Digit;
    }
    else if(iCount2Digit<=iCountMonth){
        return iCount2Digit;
    }
    else{
        return iCountMonth;
    }
    return 0;//To satisfy the compiler
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
        if(strLine=="" || i==0){
            continue;
        }
        strToLower(strLine);
        //cout<<strLine.c_str()<<endl;
        iCountOfa = CountSubStringInString(strLine,"a ");//need to improvise
        iCountOfan = CountSubStringInString(strLine,"an ");//need to improvise
        iCountOfthe = CountSubStringInString(strLine,"the ");//need to improvise
        
       
        int iCount4Digit = CountNDigitSets(strLine,4);
        int iCount2Digit = CountNDigitSets(strLine,2);
        int iCountMonth = CountMonthStrings(strLine);
        
       // cout<<"iCount2Digit = "<<iCount2Digit<<";"<<"iCount4Digit = "<<iCount4Digit<<";"<<"iCountMonth = "<<iCountMonth<<endl;
        iCountOfDate = DecideCountOfDate(iCount4Digit,iCount2Digit,iCountMonth);
         cout<<iCountOfa<<endl<<iCountOfan<<endl<<iCountOfthe<<endl<<iCountOfDate<<endl;
    }
    return 0;
}
