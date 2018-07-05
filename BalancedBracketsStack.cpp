#include <bits/stdc++.h>

using namespace std;

bool IsPair(char a, char b){
    if(a == '{' && b == '}' || a == '}' && b == '{'){
        return true;
    }
    if(a == '(' && b == ')' || a == ')' && b == '('){
        return true;
    }
    if(a == '[' && b == ']' || a == ']' && b == '['){
        return true;
    }
    return false;
}

bool CheckIfBalanced(string strIn){
    char* cstrIn = (char*)strIn.c_str();
    int i = 0;
    char* cStack = new char(strIn.length());
    int iStackLen = 0;
    while(true){
        char cTemp = cstrIn[i];
        i++;
        //cout<<cTemp;
        if(cTemp == 0){
            break;
        }
        if(cTemp == '{'){
            cStack[iStackLen] = cTemp;
            iStackLen++;
            continue;
        }
        if(cTemp == '('){
            cStack[iStackLen] = cTemp;
            iStackLen++;
            continue;
        }
        if(cTemp == '['){
            cStack[iStackLen] = cTemp;
            iStackLen++;
            continue;
        }
        if(cTemp == '}'){
            if(IsPair(cTemp,cStack[iStackLen-1])){
                iStackLen--;
                continue;
            }
            return false;
        }
        if(cTemp == ')'){
           if(IsPair(cTemp,cStack[iStackLen-1])){
                iStackLen--;
                continue;
            }
            return false;
        } 
        if(cTemp == ']'){
           if(IsPair(cTemp,cStack[iStackLen-1])){
                iStackLen--;
                continue;
            }
            return false;
        }
    }
   return true;
}

int main()
{
    int iN;
    cin>>iN;
    for(int i=0;i<iN;i++){
        string strIn;
        cin>>strIn;
        //cout<<strIn;
        bool bIsBalanced = CheckIfBalanced(strIn);
        if(bIsBalanced){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
