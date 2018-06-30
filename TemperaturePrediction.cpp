#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


double StringToDouble(string strData){
    size_t iSize;
    double dData = stod(strData,&iSize);
    return dData;
}

int StringToInt(string strData){
    size_t iSize;
    int iData = stoi(strData,&iSize);
    return iData;
}

string IntToString(int iData){
    string strData = to_string(iData);
    return strData;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int iN;
    cin>>iN;
    double dArrayTempMax[iN]; // y axis
    double dArrayTempMaxRef[iN];//x axis
    double dArrayTempMin[iN];//y axis
    double dArrayTempMinRef[iN];//x axis
    int iMaxArrayLen = 0;
    int iMinArrayLen = 0;
    string strMissingMax = "";
    string strMissingMin = "";
    for(int i=0;i<=iN;i++){
        for(int j=0;j<4;j++){
            if(i==0){
                continue;
            }
            stirng strYear;
            string strMonth;
            string strTempMax;
            string strTempMin;
            bool bSkipMax = false;
            bool bSkipMin = false;
            cin>>strYear;
            cin>>strMonth;
            cin>>strTempMax;
            cin>>strTempMin;
            if(strTempMax.find("Missing")!=strTempMax.npos){
                if(strMissingMax == ""){
                    strMissingMax = strMissingMax + strTempMax + IntToString(i); 
                }
                else{
                   strMissingMax = ","+strMissingMax + strTempMax + IntToString(i);   
                }
                bSkipMax = true;
            }
            if(strTempMin.find("Missing")!=strTempMin.npos){
                if(strMissingMin == ""){
                    strMissingMin = strMissingMin + strTempMin + IntToString(i); 
                }
                else{
                    strMissingMin = ","+strMissingMin + strTempMin + IntToString(i); 
                }
                bSkipMin = true;
            }
            if(bSkipMax == false){
                dArrayTempMax[iMaxArrayLen] = StringToDouble(strTempMax);
                dArrayTempMaxRef[iMaxArrayLen] = i;
                iMaxArrayLen++;
            }
            if(bSkipMin == false){
                dArrayTempMin[iMinArrayLen] = StringToDouble(strTempMin);
                dArrayTempMinRef[iMinArrayLen] = i;
                iMinArrayLen++;
            }
        }
    }
    return 0;
}
