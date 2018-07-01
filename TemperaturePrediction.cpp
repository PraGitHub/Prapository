#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

class MissingNode{
    public:
    int iPosition;
    double dX;
    bool bIsMax;
    MissingNode* next;
};


double StringToDouble(string strData){
    size_t iSize;
    //cout<<strData<<endl;
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

string DoubleToString(double dData){
    string strData = to_string(dData);
    return strData;
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

double MonthToDouble(string strMonth){
    strToLower(strMonth);
    double dValue = 0;
    /*switch(strMonth.c_str()){
        case "january":
            {
                dValue = (double)1.0/12.0;
                break;
            }
        case "february":
            {
                dValue = (double)2.0/12.0;
                break;
            }
        case "march":
            {
                dValue = (double)3.0/12.0;
                break;
            }
        case "april":
            {
                dValue = (double)4.0/12.0;
                break;
            }
        case "may":
            {
                dValue = (double)5.0/12.0;
                break;
            }
        case "june":
            {
                dValue = (double)6.0/12.0;
                break;
            }
        case "july":
            {
                dValue = (double)7.0/12.0;
                break;
            }
        case "august":
            {
                dValue = (double)8.0/12.0;
                break;
            }
        case "september":
            {
                dValue = (double)9.0/12.0;
                break;
            }
        case "october":
            {
                dValue = (double)10.0/12.0;
                break;
            }
        case "november":
            {
                dValue = (double)11.0/12.0;
                break;
            }
        case "december":
            {
                dValue = (double)1.0;
                break;
            }   
    }*/
    if(strMonth == "january"){
        dValue = (double)1.0/12.0;
    }
    else if(strMonth == "february"){
        dValue = (double)2.0/12.0;
    }
    else if(strMonth == "march"){
         dValue = (double)3.0/12.0;
    }
    else if(strMonth == "april"){
        dValue = (double)4.0/12.0;
    }
    else if(strMonth == "may"){
        dValue = (double)5.0/12.0;
    }
    else if(strMonth == "june"){
        dValue = (double)6.0/12.0;
    }
    else if(strMonth == "july"){
        dValue = (double)7.0/12.0;
    }
    else if(strMonth == "august"){
        dValue = (double)8.0/12.0;
    }
    else if(strMonth == "september"){
        dValue = (double)9.0/12.0;
    }
    else if(strMonth == "october"){
        dValue = (double)10.0/12.0;
    }
    else if(strMonth == "november"){
        dValue = (double)11.0/12.0;
    }
    else {
        dValue = (double)1.0;
    }
    
    return dValue;
}

/*
dM is the slope of straight
dC is i intercept
*/
void FindEquation(double* dXAxis, double* dYAxis, int iLen, double &dM, double &dC){
    double dSumX = 0;
    double dSumY = 0;
    double dSumXY = 0;
    double dSumXSquare = 0;
    double dSumYSquare = 0;
    double dMeanX = 0;
    double dMeanY = 0;
    double dSigmaDXSquare = 0;
    double dSigmaDYSquare = 0;
    double dSigmaDXDY = 0;
    
    for(int i=0;i<iLen;i++){
        double x = dXAxis[i];
        double y = dYAxis[i];
        dSumX += x;
        dSumY += y;
        dSumXY += x*y;
        dSumXSquare += x*x;
        dSumYSquare += y*y;
    }
    
    dMeanX = dSumX/iLen;
    dMeanY = dSumY/iLen;
    dSigmaDXSquare = dSumXSquare - (dSumX*dSumX/(1.0*iLen));
    //dSigmaDYSquare = dSumYSquare - (dSumY*dSumY/(1.0*iLen));
    dSigmaDXDY = dSumXY - (dSumX*dSumY/(1.0*iLen));
    dM = dSigmaDXDY/dSigmaDXSquare;
    dC = dMeanY - dMeanX*dM;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int iN;
    cin>>iN;
    double dArrayTempMax[iN]; // y axis
    double dArrayTempMaxRef[iN];//x axis
    double dArrayTempMin[iN];//y axis
    double dArrayTempMinRef[iN];//x axis
    double dMaxC;
    double dMaxM;
    double dMinC;
    double dMinM;
    int iMaxArrayLen = 0;
    int iMinArrayLen = 0;
    int iMissingCount = 0;

    MissingNode* head = NULL;
    MissingNode* current = NULL;
    
    for(int i=0;i<=iN;i++){
        string strYear;
        string strMonth;
        string strTempMax;
        string strTempMin;
        double dX;
        bool bSkipMax = false;
        bool bSkipMin = false;
       
        cin>>strYear;
        cin>>strMonth;
        cin>>strTempMax;
        cin>>strTempMin;
        //cout<<strTempMax<<";"<<strTempMin<<endl;
        if(i==0){
            continue;
        }
        dX = StringToDouble(strYear)+MonthToDouble(strMonth);
        if(strTempMax.find("Missing_")!=strTempMax.npos){
            MissingNode* temp = new MissingNode();
            temp->bIsMax = true;
            temp->iPosition = iMissingCount+1;
            //temp->dX = i;
            temp->dX = dX;
            temp->next = NULL;
            if(iMissingCount == 0){
                head = temp;
                current = head;
            }
            else{
                current->next = temp;
                current = temp;
            }
            bSkipMax = true;
            iMissingCount++;
        }
        if(strTempMin.find("Missing_")!=strTempMin.npos){
            MissingNode* temp = new MissingNode();
            temp->bIsMax = false;
            temp->iPosition = iMissingCount+1;
            //temp->dX = i;
            temp->dX = dX;
            temp->next = NULL;
            if(iMissingCount == 0){
                head = temp;
                current = temp;
            }
            else{
                current->next = temp;
                current = temp;
            }
            bSkipMin = true;
            iMissingCount++;
        }
        if(bSkipMax == false){
            dArrayTempMax[iMaxArrayLen] = StringToDouble(strTempMax);
            //dArrayTempMaxRef[iMaxArrayLen] = i;
            dArrayTempMaxRef[iMaxArrayLen] = dX;
            iMaxArrayLen++;
        }
        if(bSkipMin == false){
            dArrayTempMin[iMinArrayLen] = StringToDouble(strTempMin);
            //dArrayTempMinRef[iMinArrayLen] = i;
            dArrayTempMinRef[iMinArrayLen] = dX;
            iMinArrayLen++;
        }
    }
    FindEquation(dArrayTempMaxRef,dArrayTempMax,iMaxArrayLen,dMaxM,dMaxC);
    FindEquation(dArrayTempMinRef,dArrayTempMin,iMinArrayLen,dMinM,dMinC);
    //cout<<dMaxC<<" "<<dMaxM<<";"<<dMinC<<" "<<dMinM<<endl;
    //cout<<strMissingMax<<endl<<strMissingMin;
    cout<<fixed<<setprecision(1);
    MissingNode* tempnode = head;
    
    while(tempnode){
        double dPrediction = 0;
        if(tempnode->bIsMax){
            //cout<<"Max;";
            dPrediction = dMaxM*tempnode->dX + dMaxC;
        }
        else{
            //cout<<"Min;";
            dPrediction = dMinM*tempnode->dX + dMinC;
        }
        //cout<<temphead->iPosition<<";"<<temphead->iX<<endl;
        //cout<<fixed<<dPrediction<<setprecision(1)<<endl;
        //cout<<tempnode->iPosition<<endl;
        cout<<tempnode->dX<<endl;
        tempnode = tempnode->next;
    }
    return 0;
}
