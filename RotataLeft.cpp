#include <bits/stdc++.h>

using namespace std;


int main()
{
    int iN;
    int iR;
    cin>>iN>>iR;
    iR = iR%iN;
    int iSet[iN];
    for(int i=iN-iR;i<iN-iR+iN;i++){
        cin>>iSet[i%iN];
    }
    for(int i=0;i<iN;i++){
        cout<<iSet[i]<<" ";
    }
    return 0;
}

//Problem :
//https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
