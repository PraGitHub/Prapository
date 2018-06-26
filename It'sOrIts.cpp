#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

string strArrayPreposition[]={
    "in",
    "so",
    //"ing",
    "at",
    "there",
    "a",
    "an",
    "the",
    "not",
    "to",
    "too",
    "never",
    "with",
    "for",
    "above",
    "from",
    "another",
    "EOA"
};//This can be extended further

bool IsPreposition(string strIn){
    int i=0;
    //cout<<strIn<<endl;
    if(strIn.find("ing")!=strIn.npos||
       strIn.find("ly")!=strIn.npos
      ){
            return true;
        }
    while(true){
        if(strArrayPreposition[i]=="EOA"){
            break;
        }
        //if(strIn.find(strArrayPreposition[i])!=strIn.npos){
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
    //cout<<iPos;
    *iPosQuestionMark = iPos;
    if(iPos == 0){
        return "It's";
    }

    string strTemp = strLine.substr(iPos+4);
    //cout<<strTemp<<";";
    size_t iTempPos = -1; 
    if((iTempPos = strTemp.find(" "))!=strTemp.npos){
        strTemp = strTemp.substr(0,iTempPos);
        //cout<<strTemp<<";";
    }
    
    else{
        strTemp = strTemp.substr(0,strTemp.length()-1);
    }
    //cout<<strTemp<<";";
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
        //cout<<" "<<strIts<<endl;
        strLine.replace(iPos,3,strIts);
        cout<<strLine<<endl;
    }
    return 0;
}
