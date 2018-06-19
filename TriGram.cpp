#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<map>
using namespace std;

void splitRawData(vector <string> &strListOfSentences, string strRawIn, string strBase)
{
    int ipos;
    string strTemp = "";
    ipos = strRawIn.find(strBase);
    while(ipos != std::string::npos)
    {
        strTemp = strRawIn.substr(0,ipos);
        //cout<<strTemp<<endl;
        if(strTemp.substr(0,1)==" ")
        {
            strTemp = strTemp.substr(1);
        }
        strListOfSentences.push_back(strTemp);
        strRawIn = strRawIn.substr(ipos+1);
        ipos = strRawIn.find(".");
    }
}

int findNumSpaces(string strTemp)
{
    int i=0;
    int pos = strTemp.find(" ");
    while(pos!=std::string::npos)
    {
        i++;
        strTemp = strTemp.substr(pos+1);
        pos = strTemp.find(" ");
    }
    return i;
}

void getAllTrigrams(vector <string> &strListOfTrigrams, string strTemp)
{
    //vector <stirng> strListTemp;
    int nspace = findNumSpaces(strTemp);
    if(nspace<=1)
    {
        return;
    }
    if(nspace==2)
    {
        if(std::find(strListOfTrigrams.begin(),strListOfTrigrams.end(),strTemp)==strListOfTrigrams.end())
        {
            strListOfTrigrams.push_back(strTemp);
        }
        return;
    }
   /* 
    while(ntrigrams < (nspaces-1))
    {
        string temps = strTemp;
        int count = 0;
        int pos = temps.find(" ");
        while(pos!=std::string::npos)
        {
            temps = temps.substr(pos+1);
            count++;
        }
    }
    */
    strTemp = strTemp.substr(0,strTemp.rfind(" "));
    getAllTrigrams(strListOfTrigrams,strTemp);
}

/*
vector <string> removeExtra(vector <string> &strListOfTrigrams)
{
    vector <string> strListOfUniqueTrigrams;
    for(int i=0;i<(int)strListOfTrigrams.size();i++)
    {
        string strTemp = strListOfTrigrams.at(i);
        if(strListOfUniqueTrigrams.empty() == true ||           std::find(strListOfTrigrams.begin(),strListOfTrigrams.end(),strTemp)==strListOfTrigrams.end())
        {
            strListOfUniqueTrigrams.push_back(strTemp);
            //continue;
        }
    }
    strListOfTrigrams = strListOfUniqueTrigrams;
}
*/

string findTheMostOccuredTrigram(std::map<string,int> &TrigramCountMap)
{
    std::map<string,int>::iterator mit = TrigramCountMap.begin();
    string strMaxTrigram = mit->first;
    int iMaxCount = mit->second;
    //cout<<"Max = "<<strMaxTrigram<<" "<<iMaxCount<<endl;
    while(mit != TrigramCountMap.end())
    {
        string strThisTrigram = mit->first;
        int iThisCount = mit->second;
       // cout<<"Max = "<<strThisTrigram<<" "<<iThisCount<<endl;
        if(iThisCount>iMaxCount)
        {
            strMaxTrigram = strThisTrigram;
            iMaxCount = iThisCount;
            //cout<<"Max = "<<strMaxTrigram<<" "<<iMaxCount<<endl;
        }
        mit++;
    }
    return strMaxTrigram;
}

string findTheMostOccuredTrigram(vector<string> strListOfTrigrams, vector<int>iTrigramCountVec)
{
    int i = 0;
    string strMaxTrigram = strListOfTrigrams.at(i);
    int iMaxCount = iTrigramCountVec.at(i);
   // cout<<"Max = "<<strMaxTrigram<<" "<<iMaxCount<<endl;
    while(i<(int)iTrigramCountVec.size())
    {
        string strThisTrigram = strListOfTrigrams.at(i);
        int iThisCount = iTrigramCountVec.at(i);
        //cout<<"Max = "<<strThisTrigram<<" "<<iThisCount<<endl;
        if(iThisCount>iMaxCount)
        {
            strMaxTrigram = strThisTrigram;
            iMaxCount = iThisCount;
            //cout<<"Max = "<<strMaxTrigram<<" "<<iMaxCount<<endl;
        }
        i++;
    }
    return strMaxTrigram;
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
    //string strRet(ctemp);
    //return strRet;
   // cout<<ctemp<<endl;
    //return ctemp;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string strRawIn;
    vector <string> strListOfSentences;
    vector <string> strListOfTrigrams;
    vector <int> iTrigramCountVec;
    std::map <string, int> TrigramCountMap;
    string strResult;
    while(!getline(cin,strRawIn,'|').eof())
    {
       // cout<<strRawIn<<endl;
    }
    //cout<<strRawIn<<endl;
   /* while(1)
    {
        getline(cin,strRawIn);
        
        if(==-1)
            break;
    }*/
    //string strRawIn((const char*)std::cin.rdbuf());
   // cout<<strRawIn<<endl;
    splitRawData(strListOfSentences,strRawIn,".");
   /* 
    for(int i=0;i<strListOfSentences.size();i++){
        cout<<strListOfSentences[i]<<endl;
    }
    */
    for(int i=0;i<(int)strListOfSentences.size();i++)
    {
        string strTemp = strListOfSentences.at(i);
        int nspace = findNumSpaces(strTemp);
        int count = 0;
        while(count<(nspace-1))
        {
            getAllTrigrams(strListOfTrigrams,strTemp);
            count++;
            strTemp = strTemp.substr(strTemp.find(" ")+1);
        }
    }
    
    for(int i=0;i<(int)strListOfTrigrams.size();i++)
    {
       //cout<<strListOfTrigrams[i]<<endl;
        string strTrigram = strListOfTrigrams.at(i);
        int tcount = 0;
        for(int j=0;j<(int)strListOfSentences.size();j++)
        {
            string strSentence = strListOfSentences.at(j);
            if(strSentence.find(strTrigram)!=std::string::npos)
            {
                tcount++;
            }
        }
        TrigramCountMap.insert(std::pair<string,int>(strTrigram,tcount));
        iTrigramCountVec.push_back(tcount);
       // cout<<strTrigram<<" "<<tcount<<endl;
    }
    
    //strResult = findTheMostOccuredTrigram(TrigramCountMap);
    strResult = findTheMostOccuredTrigram(strListOfTrigrams,iTrigramCountVec);
   // cout<<strResult<<endl;
    strToLower(strResult);
    cout<<strResult<<endl;
    return 0;
}
