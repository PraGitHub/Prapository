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

/*
dM is the slope of straight
dC is i intercept
*/
void FindEquation(double* dXAxis, double* dYAxis, int iLen, double &dM, double &dC){
    double dSumX = 0;
    double dSumY = 0;
    double dSumXY = 0;
    double dSumXSquare = 0;
    double dSumYSquare = 0;
    double dMeanX = 0;
    double dMeanY = 0;
    double dSigmaDXSquare = 0;
    double dSigmaDYSquare = 0;
    double dSigmaDXDY = 0;
    
    for(int i=0;i<iLen;i++){
        double x = dXAxis[i];
        double y = dYAxis[i];
        dSumX += x;
        dSumY += y;
        dSumXY += x*y;
        dSumXSquare += x*x;
        dSumYSquare += y*y;
    }
    dMeanX = dSumX/iLen;
    dMeanY = dSumY/iLen;
    dSigmaDXSquare = dSumXSquare - (dSumX*dSumX/(1.0*iLen));
    //dSigmaDYSquare = dSumYSquare - (dSumY*dSumY/(1.0*iLen));
    dSigmaDXDY = dSumXY - (dSumX*dSumY/(1.0*iLen));
    dM = dSigmaDXDY/dSigmaDXSquare;
    dC = dMeanY - dMeanX*dM;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int iN;
    cin>>iN;
    double dArrayTempMax[iN]; // y axis
    double dArrayTempMaxRef[iN];//x axis
    double dArrayTempMin[iN];//y axis
    double dArrayTempMinRef[iN];//x axis
    double dMaxC;
    double dMaxM;
    double dMinC;
    double dMinM;
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
