#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int int64 ;



bool IsPerfectSquare(int64 liNumber){
    int iLastDigit = liNumber%10;
    if(iLastDigit == 3 || iLastDigit == 7 || iLastDigit == 2 || 8){
        return false;
    }
    int64 liRoot = sqrt(liNumber);
    if(liRoot*liRoot == liNumber){
        return true;
    }
    return false;
}

int64 FindPower(int iN, int iM){
    int64 liResult = 1;
    for(int i=0;i<iM;i++){
        liResult = liResult*iN;
    }
    return liResult;
}


void FindRangeOfPossibleRoots(int* iDigitArray, int iLen, int64* liArrayRange){
    int64 liMinSquare = 0;
    int64 liMaxSquare = 0;
    for(int i=iLen-1;i>=0;i--){
        liMinSquare += iDigitArray[i]*FindPower(10,2*(iLen-1-i));
        liMaxSquare += iDigitArray[i]*FindPower(10,2*(iLen-1-i));
        if(i!=0){
            liMaxSquare += 9*FindPower(10,(2*(iLen-1-i)+1));
        }
    }
    liArrayRange[0] = sqrt(liMinSquare);
    liArrayRange[1] = sqrt(liMaxSquare);
}


bool IsPatternOK(int64 liSquareNum, int* iDigitArray, int iLen){
    for(int i=0;i<iLen;i++){
        int iDigit = (liSquareNum/FindPower(10,2*i))%10;
        if(iDigit != iDigitArray[iLen-i-1]){
            return false;
        }
    }
    return true;
}

bool ConsiderNumber(int64 liNumber, int iLastDigitOfSquare){
    int iLastDigitOfNumber = liNumber%10;
    switch(iLastDigitOfSquare){
        case 0:{
            if(iLastDigitOfNumber == 0){
                return true;
            }
            return false;
        }
        case 5:{
            if(iLastDigitOfNumber == 5){
                return true;
            }
            return false;
        }
        case 9:{
            if(iLastDigitOfNumber == 3){
                return true;
            }
            return false;
        }
        case 4:{
            if(iLastDigitOfNumber == 2 || iLastDigitOfNumber == 8){
                return true;
            }
            return false;
        }
        case 6:{
            if(iLastDigitOfNumber == 4 || iLastDigitOfNumber == 6){
                return true;
            }
            return false;
        }
        case 1:{
            if(iLastDigitOfNumber == 9 || iLastDigitOfNumber == 1){
                return true;
            }
            return false;
        }
    }
    return true;//To Satisfy the compiler
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iN;
    cin>>iN;
    int iDigitArray[iN];
    for(int i=0;i<iN;i++){
        cin>>iDigitArray[i];
    }
    
    int64 liArrayRange[2];
    FindRangeOfPossibleRoots(iDigitArray,iN,liArrayRange);
    //cout<<liArrayRange[0]<<" "<<liArrayRange[1]<<endl;
    for(int64 li=liArrayRange[0];li<=liArrayRange[1];li++){
        //cout<<"li = "<<li<<endl;
        bool bConsiderNumber = ConsiderNumber(li,iDigitArray[iN-1]);
        if(bConsiderNumber == true){
            //cout<<"li considered = "<<li<<" "<<li*li<<endl;
            bool bIsPatternOK = IsPatternOK(li*li,iDigitArray,iN);
            if(bIsPatternOK == true){
                cout<<li<<endl;
                return 0;
            }
        }
    }
    return 0;
}
