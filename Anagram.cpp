#include <bits/stdc++.h>

using namespace std;
string strAToZ = "abcdefghijklmnopqrstuvwxyz";
char* cArrayaToz = (char*)strAToZ.c_str();

int CountSubString(string strString, string strSubString){
    int iCount = 0;
    size_t iPos = -1;
    while((iPos = strString.find(strSubString))!=strString.npos){
        iCount++;
        strString = strString.substr(iPos+1);
    }
    return iCount;
}

void strToLower(string &strIn)
{
    char* ctemp = (char*)strIn.c_str();
    while(*ctemp!=0)
    {
        //cout<<*ctemp<<endl;
        if(*ctemp >= 'A' && *ctemp <= 'Z')
        {
            *ctemp = *ctemp - 'A' + 'a';
        }
        ctemp++;
    }

}

int GetDifference(int iX, int iY){
    if(iY>iX){
        iX = iX + iY;
        iY = iX - iY;
        iX = iX - iY;
    }
    return (iX - iY);
}

int makeAnagram(string a, string b) {
    strToLower(a);
    strToLower(b);
    int iCountA;
    int icountB;
    int iResult = 0;
    for(int i=0;i<26;i++){
        iCountA = CountSubString(a,cArrayaToz[i]);
        iCountB = CountSubString(b,cArrayaToz[i]);
        
        iResult += GetDifference(iCountA,iCountB);
        
    }
    return iResult;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
