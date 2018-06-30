#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;


int FindCount(double* dArraySet,double dElement ,int iN){
    int iCount = 0;
    for(int i=0;i<iN;i++){
        if(dElement==dArraySet[i]){
            iCount++;
        }
    }
    return iCount;
}

void Swap(double &a, double &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void SortSet(double* dArraySet, int iN){
    /*int iSize = sizeof(dArraySet)/sizeof(dArraySet[0]);
    sort(dArraySet,dArraySet+iSize);*/
    for(int i=0;i<iN-1;i++){
        for(int j=i+1;j<iN;j++){
            if(dArraySet[i]>dArraySet[j]){
                Swap(dArraySet[i],dArraySet[j]);
            }
        }
    }
}

double FindSD(double* dArraySet,double dMean,int iN){
    double dSumOfSquare = 0;
    double dSD = 0;
    for(int i=0;i<iN;i++){
        dSumOfSquare += (dArraySet[i]-dMean)*(dArraySet[i]-dMean);
    }
    dSD = sqrt(dSumOfSquare/(1.0*iN));
    return dSD;
}

double FindMedian(double* dArraySet, int iN){
    if(iN%2 == 1){
        return dArraySet[iN/2];
    }
    return ((dArraySet[iN/2-1]+dArraySet[iN/2])/(2.0));
    
}

void PrintWithPrecision(double dData,int iPrecision){
    cout<</*setprecision(iPrecision)<<*/dData<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int iN;
    int iMaxCount = 1;
    double dSum = 0;
    double dMean = 0;
    double dMedian = 0;
    double dMode = 0;
    double dSD = 0;
    cin>>iN;
    double dArraySet[iN];
    for(int i=0;i<iN;i++){
        double dTemp;
        int iCount = 0;
        cin>>dTemp;
        dArraySet[i] = dTemp;
        dSum += dTemp;
        
        if(i==0){
            dMode = dTemp;
        }
        
        if(i>=1){
            iCount = FindCount(dArraySet,dTemp,i+1);
        }
        
        if(iCount>iMaxCount){
            iMaxCount = iCount;
            dMode = dTemp;
        }
        if(iCount == iMaxCount){
            if(dMode>dTemp){
                dMode = dTemp;
            }
        }
    }
    dMean = dSum/(1.0*iN);
    
    dSD = FindSD(dArraySet,dMean,iN);
    
    SortSet(dArraySet,iN);
    dMedian = FindMedian(dArraySet,iN);
    
    PrintWithPrecision(dMean,1);
    PrintWithPrecision(dMedian,1);
    PrintWithPrecision(dMode,1);
    PrintWithPrecision(dSD,1);
    
    return 0;
}
