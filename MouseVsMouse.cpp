#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<fstream>
#include <algorithm>
#include<string>
using namespace std;

string strArrayComputer[]={
    "computer",
    "device",
    "CPU",
    "control",
    "keyboard",
    "system",
    "sensor",
    "develop",
    "engineer",
    "ball",
    "laser",
    "3d",
    "optical",
    "gesture",
    "hardware",
    "microsoft",
    "software",
    "click",
    "scroll",
    "apple",
    "analog",
    "digital",
    "select",
    "wire",
    "bluetooth",
    "ibm",
    "dos",
    "button",
    "desktop",
    "laptop",
    "usb",
    "cordless",
    "windows",
    "mac",
    "linux",
    "unix",
    "EOA"//End of attributes
};

string strArrayAnimal[]={
    "rodent",
    "animal",
    "mammal",
    "mice",
    "family",
    "mus",
    "male",
    "female",
    "reproduc",
    "logy",
    "genus",
    "species",
    "food",
    "white",
    "diet",
    "cat",
    "EOA"//End of attributes
};

int FindScore(string strLine,string* strArray){
    int iScore = 0;
    for(int i=0;true;i++){
        //cout<<strArray[i]<<" ";
        string strLineTemp = strLine;
        if(strArray[i]=="EOA"){
            break;
        }
        size_t iPos = -1;
        while((iPos = strLineTemp.find(strArray[i]))!=strLineTemp.npos){
            iScore++;
            strLineTemp = strLineTemp.substr(iPos+1);
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
        return "computer-mouse";
    }
    if(iScoreFruit>iScoreCompany){
        return "animal";
    }
    return "animal";
    //return "computer-company";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iNumLines;
    cin>>iNumLines;
    for(int i=0;i<=iNumLines;i++){
        //cout<<i<<" : ";
        string strLine;
        string strResult;
        int iScoreComputer;
        int iScoreAnimal;
        getline(cin,strLine);
        if(i==0){
            continue;
        }
        //cout<<"Length Before Lower= "<<strLine.length();
        strToLower(strLine);
        //cout<<" ; Length After Lower = "<<strLine.length();
        iScoreComputer = FindScore(strLine,strArrayComputer);
        iScoreAnimal = FindScore(strLine,strArrayAnimal);
        strResult = Decide(iScoreComputer,iScoreAnimal);
        //cout<<"C:"<<iScoreCompany<<";F:" <<iScoreFruit<<endl;
        cout<<strResult<<endl;
    }
    return 0;
}
