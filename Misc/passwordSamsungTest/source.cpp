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
    string password = passwords[n];
    /*
    Algorithm:
    Sort passwords based on length => passwords
    LEN => length of actual password
    N1 => number of passwords with their lengths less than LEN
    N2 => number of passwords with their lengths equal to LEN
    BestCaseTime = (N1- (floor(N1/K))) + (floor(N1/K))*5 + 1
    N3 = N1+N2-1
    WorstCasetime = (N3- (floor(N3/K))) + (floor(N3/K))*5 + 1
    */
    sort(passwords.begin(), (passwords.begin() + n), compareElements);
    printStrVec(passwords);
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

    printStrVec(passwords);

    determineTheBestAndTheWorst(n, k, passwords);
}
