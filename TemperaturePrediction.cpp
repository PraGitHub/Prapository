#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

class MissingNode{
    public:
    int iPosition;
    int iX;
    bool bIsMax;
    MissingNode* next;
};


double StringToDouble(string strData){
    size_t iSize;
    //cout<<strData<<endl;
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
    int iMissingCount = 0;

    MissingNode* head = NULL;
    MissingNode* current = NULL;
    
    for(int i=0;i<=iN;i++){
        string strYear;
        string strMonth;
        string strTempMax;
        string strTempMin;
        bool bSkipMax = false;
        bool bSkipMin = false;
       
        cin>>strYear;
        cin>>strMonth;
        cin>>strTempMax;
        cin>>strTempMin;
        //cout<<strTempMax<<";"<<strTempMin<<endl;
        if(i==0){
            continue;
        }
        if(strTempMax.find("Missing_")!=strTempMax.npos){
            MissingNode* temp = new MissingNode();
            temp->bIsMax = true;
            temp->iPosition = iMissingCount+1;
            temp->iX = i;
            temp->next = NULL;
            if(iMissingCount == 0){
                head = temp;
                current = head;
            }
            else{
                current->next = temp;
                current = temp;
            }
            bSkipMax = true;
            iMissingCount++;
        }
        if(strTempMin.find("Missing_")!=strTempMin.npos){
            MissingNode* temp = new MissingNode();
            temp->bIsMax = false;
            temp->iPosition = iMissingCount+1;
            temp->iX = i;
            temp->next = NULL;
            if(iMissingCount == 0){
                head = temp;
                current = temp;
            }
            else{
                current->next = temp;
                current = temp;
            }
            bSkipMin = true;
            iMissingCount++;
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
    FindEquation(dArrayTempMaxRef,dArrayTempMax,iMaxArrayLen,dMaxM,dMaxC);
    FindEquation(dArrayTempMinRef,dArrayTempMin,iMinArrayLen,dMinM,dMinC);
    //cout<<dMaxC<<" "<<dMaxM<<";"<<dMinC<<" "<<dMinM<<endl;
    //cout<<strMissingMax<<endl<<strMissingMin;
    MissingNode* tempnode = head;
    while(tempnode){
        double dPrediction = 0;
        if(tempnode->bIsMax){
            //cout<<"Max;";
            dPrediction = dMaxM*tempnode->iX + dMaxC;
        }
        else{
            //cout<<"Min;";
            dPrediction = dMinM*tempnode->iX + dMinC;
        }
        //cout<<temphead->iPosition<<";"<<temphead->iX<<endl;
        cout<<dPrediction<<endl;
        //;"<<tempnode->iX<<endl;
        tempnode = tempnode->next;
    }
    return 0;
}
