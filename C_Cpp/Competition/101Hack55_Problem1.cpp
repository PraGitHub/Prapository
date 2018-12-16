#include <bits/stdc++.h>

using namespace std;
/*
https://www.hackerrank.com/contests/101hack55/challenges/swapping-in-an-array
*/
int main(){
    int iN;
    int iPos = -1;
    int iCount = 0;
    cin>>iN;
    int a[iN];
    for(int i=0;i<iN;i++){
        cin>>a[i];
    }
    for(int i=0;i<iN-1;i++){
        if(a[i]>a[i+1]){
            iCount++;
            if(iCount == 1){
                iPos = i;
            }
        }
        if(iCount>1){
            if(iPos>0){
                if(a[iPos-1]<=a[iPos+1] && a[iPos+1]<=a[i+1]){
                    iCount--;
                    continue;
                }
            }
            else{
                if(a[iPos+1]<=a[i+1]){
                    iCount--;
                    continue;
                }
            }
            cout<<-1;
            return 0;
        }
    }
    cout<<iCount;
    return 0;
}
