#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<string> STRVEC;

void printStrVec(STRVEC strvec)
{
    for(STRVEC::iterator iter = strvec.begin(); iter != strvec.end(); ++iter)
    {
        cout<<*iter<<endl;
    }
}

bool compareElements(string a, string b) //bool compareElements(const string& a, const string& b) // this also works
{
    return (a.length() < b.length());
}

void determineTheBestAndTheWorst(int n, int k, STRVEC passwords)
{
/*
    Algorithm:
    Sort passwords based on length => passwords // sorting is not required
    LEN => length of actual password
    N1 => number of passwords with their lengths less than LEN
    N2 => number of passwords with their lengths equal to LEN
    BestCaseTime = (N1- (floor(N1/K))) + (floor(N1/K))*5 + 1
    N3 = N1+N2-1
    WorstCasetime = (N3- (floor(N3/K))) + (floor(N3/K))*5 + 1
*/
    string password = passwords[n];
    int len = password.length();
    int n1 = 0, n2 = 0, n3 = 0;
    int timeBest = -1, timeWorst = -1;
    //sort(passwords.begin(), (passwords.begin() + n), compareElements); // sorting is not required
    //printStrVec(passwords);
    for(int i = 0; i<n; i++)
    {
        int thisLen = passwords[i].length();
        if(thisLen < len)
        {
            n1++;
        }
        else if(thisLen == len)
        {
            n2++;
        }
        else;
    }
    timeBest = (n1- (n1/k)) + (n1/k)*5 + 1;
    n3 = n1 + n2 - 1;
    timeWorst = (n3- (n3/k)) + (n3/k)*5 + 1;
    
    cout<<"Best Case Time = "<<timeBest<<endl;
    cout<<"Worst Case Time = "<<timeWorst<<endl;
}

int main()
{
    int n;
    int k;
    STRVEC passwords;

    cin>>n;
    cin>>k;

    for(int i=0; i<=n; i++)
    {
        string strTemp;
        cin>>strTemp;
        passwords.push_back(strTemp);
    }

    //printStrVec(passwords);

    determineTheBestAndTheWorst(n, k, passwords);
}
