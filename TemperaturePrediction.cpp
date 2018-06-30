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
    for(int i=0;i<=iN;i++){
        for(int j=0;j<4;j++){
            if(i==0){
                continue;
            }
            stirng strYear;
        }
    }
    return 0;
}
