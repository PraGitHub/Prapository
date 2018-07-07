#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class PositiveList{
    public:
    double* dSet;
    PositiveList* next;
};

class NegativeList{
    public:
    double* dSet;
    NegativeList* next;
};

double StringToDouble(string strData){
    size_t iSize;
    double dData = stod(strData,&iSize);
    return dData;
}


double FindCorrelation(double* dSetX, double* dSetY, int iLen, bool bIgnoreEqualData){
    double dSumX = 0;
    double dSumY = 0;
    double dSumXY = 0;
    double dSumXSquare = 0;
    double dSumYSquare = 0;
    double dNumerator = 0;
    double dDenominator = 0;
    double dCorrelation = 0;
    int iEqualDataCount = 0;
    
    for(int i=0;i<iLen;i++){
        double x = dSetX[i];
        double y = dSetY[i];
        //cout<<"x:"<<x<<"y:"<<y;
        if(bIgnoreEqualData){
            if(x == y){
                iEqualDataCount++;
                continue;
            }
        }
        dSumX += x;
        dSumY += y;
        dSumXY += x*y;
        dSumXSquare += x*x;
        dSumYSquare += y*y;
    }
    //cout<<endl;
    iLen = iLen - iEqualDataCount;
    dNumerator = (iLen * dSumXY) - (dSumX * dSumY);
    dDenominator = sqrt((iLen*dSumXSquare - dSumX*dSumX)*(iLen*dSumYSquare - dSumY*dSumY));
    
    dCorrelation = dNumerator / dDenominator ;
    
    //cout<<dNumerator<<" "<<dDenominator<<" "<<dCorrelation<<",";
    
    return dCorrelation;
  
}

double FindEffectiveCorrelation(PositiveList* head, double* dSet, int iLen){
    PositiveList* temp = head;
    int iN = 0;
    double dCorrelationSum = 0;
    while(temp){
        iN++;
        dCorrelationSum += FindCorrelation(temp->dSet,dSet,iLen,true);
        temp = temp->next;
    }
    //cout<<iN<<endl;
    //cout<<dCorrelationSum<<endl;
    double dEffectiveCorrelation = dCorrelationSum/iN;
    //cout<<dEffectiveCorrelation<<endl;
    return dEffectiveCorrelation;
}

double FindEffectiveCorrelation(NegativeList* head, double* dSet, int iLen){
    NegativeList* temp = head;
    int iN = 0;
    double dCorrelationSum = 0;
    while(temp){
        iN++;
        dCorrelationSum  += FindCorrelation(temp->dSet,dSet,iLen,true);
        temp = temp->next;
    }
    //cout<<iN<<endl;
    //cout<<dCorrelationSum<<endl;
    double dEffectiveCorrelation = dCorrelationSum/iN;
    //cout<<dEffectiveCorrelation<<endl;
    return dEffectiveCorrelation;
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
        //cout<<strType<<" ";
        //double dSet[iM];
        //cout<<&dSet<<endl;
        double* dSet = new double[iM];
        //cout<<dSet<<endl;
        for(int j=0;j<iM;j++){
            string strData;
            cin>>strData;
            size_t iPos = strData.find(":");
            strData = strData.substr(iPos+1);
            //cout<<strData<<endl;
            dSet[j] = StringToDouble(strData);
            //cout<<dSet[j]<<endl;
        }
        if(strType == "+1"){
            PositiveList* pTemp = new PositiveList();
            pTemp->dSet = dSet;
            pTemp->next = NULL;
            if(pHead == NULL){
                pHead = pTemp;
                pCurrent = pTemp;
                continue;
            }
            pCurrent->next = pTemp;
            pCurrent = pTemp;
        }
        if(strType == "-1"){
            NegativeList* nTemp = new NegativeList();
            nTemp->dSet = dSet;
            nTemp->next = NULL;
            if(nHead == NULL){
                nHead = nTemp;
                nCurrent = nTemp;
            }
            nCurrent->next = nTemp;
            nCurrent = nTemp;
        }
    }
    int iQ;
    cin>>iQ;
    //cout<<iQ;
    for(int i=0;i<iQ;i++){
        string strID;
        cin>>strID;
        //double dSet[iM];
        //cout<<"Query-"<<&dSet<<endl;
        double* dSet = new double[iM];
        //cout<<"Query-"<<dSet<<endl;
        for(int j=0;j<iM;j++){
            string strData;
            cin>>strData;
            size_t iPos = strData.find(":");
            strData = strData.substr(iPos+1);
            dSet[j] = StringToDouble(strData);
            //cout<<dSet[j]<<" ";
        }
        double dCorrelationOfPositiveQuery = 0;
        double dCorrelationOfNegativeQuery = 0;
        
        dCorrelationOfPositiveQuery = FindEffectiveCorrelation(pHead,dSet,iM);
        dCorrelationOfNegativeQuery = FindEffectiveCorrelation(nHead,dSet,iM);
        
        //cout<<dCorrelationOfPositiveQuery<<" "<<dCorrelationOfNegativeQuery<<endl;
        
        if(dCorrelationOfPositiveQuery>dCorrelationOfNegativeQuery){
            cout<<strID<<" +1"<<endl;
        }
        else{
            cout<<strID<<" -1"<<endl;
        }
    }
    return 0;
}
