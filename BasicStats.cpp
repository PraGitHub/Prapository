#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

double FindSD(double* dArraySet,double dMean,int iN){
    double dSumOfSquare = 0;
    double dSD = 0;
    for(int i=0;i<iN;i++){
        dSumOfSquare += (dArraySet[i]-dMean)*(dArraySet[i]-dMean);
    }
    dSD = sqrt(dSumOfSquare);
    return dSD;
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
        
        if(iN%2 == 1 && i==iN/2){
            dMedian += dTemp;
        }
        
        if(iN%2 == 0){
            if(i==iN/2 || i==iN/2-1){
                dMedian += dTemp;
            }
        }
        
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
    if(iN%2==0){
        dMedian = dMedian/2.0;
    }
    dMean = dSum/(1.0*iN);
    dSD = FindSD(dArraySet,dMean,iN);
    return 0;
}
