#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<fstream>
#include <algorithm>
#include<string>
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
    "phone",
    "mobile",
    "comput",
    "ui",
    "itune",
    "xerox",
    "steve",
    "jobs",
    "ceo",
    "director",
    "notebook",
    "iphone",
    "ipad",
    "system",
    "microsoft",
    "software",
    "hardware",
    "engineer",
    "compet",
    "os x",
    "operating",
    "ios",
    "program",
    "language",
    "architecture",
    "graphic",
    "rival",
    "release",
    "htc",
    "developer",
    "radio",
    "service",
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
    "ica",
    "ae",
    "aceae",
    "ton",
    "cultivat",
    "climat",
    "seed",
    " rain",
    "season",
    "plant",
    "flower",
    "bacteria",
    "pest",
    "fertili",
    "EOA"//End of attributes
};

int FindScore(string strLine,string* strArray){
    int iScore = 0;;
    for(int i=0;true;i++){
        //cout<<strArray[i]<<" ";
        if(strArray[i]=="EOA"){
            break;
        }
        if(strLine.find(strArray[i])!=strLine.npos){
            iScore++;
            //cout<<strArray[i]<<" ";
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
    //cout<<"iScoreCompany = "<<iScoreCompany<<";"<<"iScoreFruit = "<<iScoreFruit<<endl;
    if(iScoreCompany>iScoreFruit){
        return "computer-company";
    }
    if(iScoreFruit>iScoreCompany){
        return "fruit";
    }
    return "fruit";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iNumLines;
    cin>>iNumLines;
    for(int i=0;i<=iNumLines;i++){
        //cout<<i<<" : ";
        string strLine;
        string strResult;
        int iScoreCompany;
        int iScoreFruit;
        getline(cin,strLine);
        if(i==0){
            continue;
        }
        //cout<<"Length Before Lower= "<<strLine.length();
        strToLower(strLine);
        //cout<<" ; Length After Lower = "<<strLine.length();
        iScoreCompany = FindScore(strLine,strArrayCompany);
        iScoreFruit = FindScore(strLine,strArrayFruit);
        strResult = Decide(iScoreCompany,iScoreFruit);
        //cout<<"C:"<<iScoreCompany<<";F:" <<iScoreFruit<<endl;
        cout<<strResult<<endl;
    }
    return 0;
}
