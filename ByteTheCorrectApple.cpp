#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<fstream>
#include <algorithm>
using namespace std;

string strArrayCompany[]={
    "mac",
    "macintosh",
    "illion",
    "$",
    "business",
    "samsung",
    "nokia",
    "apple i",
    "company",
    "EOA"//End of attributes
};

string strArrayFruit[]={
    "fruit",
    "apples",
    "tree",
    "pomaceous",
    "eat",
    "grow",
    "juice",
    "variet",
    "EOA"//End of attributes
};

int FindScore(string strLine,string* strArray){
    int iScore = 0;;
    for(int i=0;true;i++){
        if(strArray[i]=="EOA"){
            break;
        }
        if(strLine.find(strArray[i])!=strLine.npos){
            iScore++;
        }
    }
    return iScore;
}

void strToLower(string &strIn)
{
    char* ctemp = (char*)strIn.c_str();
    while(*ctemp!=0)
    {
        //cout<<*ctemp<<endl;
        if(*ctemp >= 'A' && *ctemp <= 'Z')
        {
            *ctemp = *ctemp - 'A' + 'a';
        }
        ctemp++;
    }
}

string Decide(int iScoreCompany, int iScoreFruit){
    cout<<"iScoreCompany = "<<iScoreCompany<<";"<<"iScoreFruit = "<<iScoreFruit<<endl;
    if(iScoreCompany>iScoreFruit){
        return "computer-company";
    }
    if(iScoreFruit>iScoreCompany){
        return "fruit";
    }
    return "computer-company";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iNumLines;
    cin>>iNumLines;
    for(int i=0;i<iNumLines;i++){
        string strLine;
        string strResult;
        int iScoreCompany;
        int iScoreFruit;
        cin>>strLine;
        strToLower(strLine);
        iScoreCompany = FindScore(strLine,strArrayCompany);
        iScoreFruit = FindScore(strLine,strArrayFruit);
        strResult = Decide(iScoreCompany,iScoreFruit);
        cout<<strResult<<endl;
    }
    return 0;
}
