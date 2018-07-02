#include <bits/stdc++.h>

using namespace std;

int main(){
    int iNumWordsInMagazine;
    int iNumWordsInRansomNote;
    cin>>iNumWordsInMagazine>>iNumWordsInRansomNote;
    string strArrayMagazine[iNumWordsInMagazine];
    for(int i=0;i<iNumWordsInMagazine;i++){
        cin>>strArrayMagazine[i];
    }
    for(int i=0;i<iNumWordsInRansomNote;i++){
        string strTemp;
        cin>>strTemp;
        bool bIsThere = false;
        for(int j=0;j<iNumWordsInMagazine;j++){
            if(strTemp == strArrayMagazine[j]){
                strArrayMagazine[j] = "";
                bIsThere = true;
                continue;
            }
        }
        if(bIsThere == false){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
