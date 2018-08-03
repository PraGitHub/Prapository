#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


string strArrayOfQueries[] = {
    "axe deo",
    "best-seller books",
    "calvin klein",
    "camcorder",
    "camera",
    "chemistry",
    "chromebook",
    "c programming",
    "data structures algorithms",
    "dell laptops",
    "dslr canon",
    "mathematics",
    "nike-deodrant",
    "physics",
    "sony cybershot",
    "spoken english",
    "timex watch",
    "titan watch",
    "tommy watch",
    "written english",
    "EOA"
};


string GetTheBestMatch(string strLine){
    string strOutput = "";
    int i=0;
    int iCount = 0;
    string strBestQuery = "";
    while(true){
        string strQuery = strArrayOfQueries[i];
        if(strQuery == "EOA"){
            break;
        }
        //need to add th4e logic here
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int iN;
    cin>>iN;
    for(int i=0;i<=iN;i++){
        string strLine;
        getline(cin,strLine);
        if(i==0){
            continue;
        }
        //cout<<strLine<<endl;
    }
    return 0;
}
