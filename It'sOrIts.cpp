#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

string strArrayPreposition[]={
    "in",
    "at",
    "there",
    "the",
    "not",
    "never",
    "EOA"
};//This can be extended further

bool IsPreposition(string strIn){
    int i=0;
    while(true){
        if(strArrayPreposition[i]=="EOA"){
            break;
        }
        if(strIn==strArrayPreposition[i]){
            return true;
        }
        i++;
    }
    return false;
}

string DecideTheIts(string strLine, size_t* iPosQuestionMark){
    size_t iPos = -1;
    iPos = strLine.find("???");
    *iPosQuestionMark = iPos;
    if(iPos == 0){
        return "It's";
    }
    string strBehind1 = strLine.substr(iPos-1,1);
    string strBehind2 = strLine.substr(iPos-2,2);

    if(strBehind1=="."||
       strBehind1=="?"||
       strBehind1=="!"|| 
       strBehind2==". "||
       strBehind2=="? "||
       strBehind2=="! "){
        return "It's";
    }
    
    if(strBehind1==","||
    strBehind2==", "){
        return "it's";
    }
    
    string strTemp = strLine.substr(iPos+4);
    strTemp = strTemp.substr(0,strTemp.find(" "));
    if(IsPreposition(strTemp)==true){
        return "it's";
    }
    
    
    return "its";
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
        string strIts = "";
        size_t iPos = -1;
        strIts = DecideTheIts(strLine,&iPos);
        strLine.replace(iPos,3,strIts);
        cout<<strLine<<endl;
    }
    return 0;
}
