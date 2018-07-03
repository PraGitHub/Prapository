#include <bits/stdc++.h>

using namespace std;

int main(){
    int iN;
    cin>>iN;
    int iSetA[iN];
    int iSetB[iN];
    int iTheSet[iN];
    for(int j=0;j<2;j++){
        for(int i=0;i<iN;i++){
            if(j==0){
                cin>>iSetA[i];
            }
            else{
                cin>>iSetB[i];
            }
        }
    }
    int i = 0;
    while(i<iN-1){
        if(iSetB[i]>=iSetA[i+1]){
            iTheSet[i] = iSetB[i];
            iTheSet[i+1] = iSetB[i];
            i++;
        }
        else{
            iTheSet[i] = -1;
        }
        i++;
    }
    //yet to continue
    return 0;
}
