#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	int n;
	int sum = 0;
	int mean = 0;
	int coin = 0;
	vector<int> coins;
	cin>>t;
	while(t != 0)
	{
	    t--;
	    cin>>n;
	    coins.resize(n,0);
	    sum = 0;
	    for(int i=0; i<n; i++)
	    {
	        cin>>coin;
	        coins[i] = coin;
	        sum += coin;
	    }
	    if(sum%n != 0)
	    {
	        cout<<"Impossible"<<endl;
	        continue;
	    }
	    mean = sum/n;
	    for(int i=0; i<n; i++)
	    {
	        if(coins[i] == mean)
	        {
	            cout<<i+1<<endl;
	            break;
	        }
	    }
	}
	return 0;
}
