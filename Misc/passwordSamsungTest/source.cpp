#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<string> strvec;

void determineTheBestAndTheWorst(int n, int k, strvec passwords)
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
}

int main()
{
    int n;
    int k;
    strvec passwords;

    cin>>n;
    cin>>k;

    for(int i=0; i<=n; i++)
    {
        string strTemp;
        cin>>strTemp;
        passwords.push_back(n, k, strTemp);
    }

    determineTheBestAndTheWorst(passwords);
}