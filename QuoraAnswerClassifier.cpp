#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct PositiveList{
    double* dSet;
    PositiveList* next;
}

struct NegativeList{
    double* dSet;
    NegativeList* next;
}

double StringToDouble(string strData){
    size_t iSize;
    double dData = stod(strData,&iSize);
    return dData;
}


double FindCorrelation(double* dSetX, double* dSetY, int iLen){
    double dSumX = 0;
    double dSumY = 0;
    double dSumXY = 0;
    double dSumXSquare = 0;
    double dSumYSquare = 0;
    double dNumerator = 0;
    double dDenominator = 0;
    double dCorrelation = 0;
    
    for(int i=0;i<iLen;i++){
        double x = dSetX[i];
        double y = dSety[i];
        dSumX += x;
        dSumY += y;
        dSumXY += x*y;
        dSumXSquare += x*x;
        dSumYSquare += y*y;
    }
    dNumerator = (iLen * dSumXY) - (dSumX * dSumY);
    dDenominator = sqrt((iLen*dSumXSquare - dSumX*dSumX)*(iLen*dSumYSquare - dSumY*dSumY));
    
    dCorrelation = dNumerator / dDenominator ;
    
    return dCorrelation;
  
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iM;
    int iN;
    cin>>iN>>iM;
    PositiveList* pHead = NULL;
    NegativeList* nHead = NULL;
    PositiveList* pCurrent = NULL;
    NegativeList* nCurrent = NULL;
    
    for(int i=0;i<iN;i++){
        string strID;
        string strType;
        cin>>strID>>strType;
        double* dSet = new double(iM);
        for(int j=0;j<iM;j++){
            string strData;
            cin>>strData;
            strData = strData.substr(2);
            dSet[j] = StringToDouble(strData);
        }
        if(strType == "+1"){
            if(pHead == NULL){
                pHead = new PositiveList();
                pHead->dSet = dSet;
                pHead->next = NULL;
                pCurrent = pHead;
                continue;
            }
            PositiveList* pTemp = new PositiveList();
            pTemp->dSet = dSet;
            pTemp->next = NULL;
            pCurrent->next = pTemp;
        }
        if(strType == "-1"){
            if(nHead == NULL){
                nHead = new NegativeList();
                nHead->dSet = dSet;
                nHead->next = NULL;
                nCurrent = nHead;
                continue;
            }
            NegativeList* nTemp = new NegativeList();
            nTemp->dSet = dSet;
            nTemp->next = NULL;
            nCurrent->next = nTemp;
        }
    }
    return 0;
}
