#include<algorithm>
#include<string>
#include<sstream>

string intToString(int a){
    stringstream ss;
    ss<<a;
    return ss.str();
}

string removeLeadingZeroes(string strTemp){
    istringstream iss(strTemp);
    stringstream ss;
    int n;
    iss>>n;
    ss<<n;
    return ss.str();
}

bool compareFunction(const int& a, const int& b){
    stringstream ssa, ssb;
    int aFirst = -1, bFirst = -1;
    
    ssa<<a<<b;
    ssb<<b<<a;
    
    istringstream issa(ssa.str());
    istringstream issb(ssb.str());
    
    issa>>aFirst;
    issb>>bFirst;
    
    if(aFirst >= bFirst) return true;
    return false;
}

string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return "";
    
    if(n == 1) return intToString(A[0]);
    
    vector<int> arr;
    for(int i=0; i<n; i++){
        arr.push_back(A[i]);
    }
    
    sort(arr.begin(), arr.end(), compareFunction);
    //bool b = compareFunction(1,2);
    
    string strResult = intToString(arr[0]);
    for(int i=1; i<n; i++){
        strResult = strResult + intToString(arr[i]);
    }
    if(strResult.substr(0,1) == "0") strResult = removeLeadingZeroes(strResult);
    return strResult;
}
