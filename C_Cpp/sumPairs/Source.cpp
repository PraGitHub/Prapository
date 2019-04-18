#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<ctime>

using namespace std;

#define NumOfInt 1000

typedef vector<int> intvec;
typedef unordered_set<int> inthash; //unordered_set is actaully unordered_map which is basicaly a hash table. for unordered_set key and values are same

void findUsingVector(intvec &arr, int sum)
{
	int start = 0;
	int end = arr.size() - 1;
	sort(arr.begin(), arr.end());
	while (true)
	{
		if (start >= end)
		{
			break;
		}
		if ((arr[start] + arr[end]) < sum)
		{
			start++;
		}
		else if ((arr[start] + arr[end]) > sum)
		{
			end--;
		}
		else
		{
			cout << arr[start] << "\t" << arr[end] << endl;
		}
	}
}

void findUsingHash(intvec &arr, int sum)
{
	inthash hash;
	for (int i = 0; i < arr.size(); i++)
	{
		if (i == 0)
		{
			hash.insert(arr[i]);
			continue;
		}

		if (hash.find(sum - arr[i]) != hash.end())
		{
			cout << arr[i] << "\t" << sum - arr[i] << endl;
		}

		hash.insert(arr[i]);
	}
}

int main(int NARG, char** ARGS)
{
	intvec arr;
	int sum = rand();
	int num = NumOfInt;

	int temp[] = { -1,3,4,0,2,10,1,5,6,-3 };
	sum = 0;

	if (NARG == 2)
	{
		try
		{
			num = atoi(ARGS[1]);
		}
		catch (...)
		{
			cout << "argument should be a natural number | using default value " << NumOfInt << endl;
		}
	}

	cout << "num = " << num << endl;
	//exit(0);

	for (int i = 0; i < num; i++)
	{
		//arr.push_back(rand());
		arr.push_back(temp[i]);
	}

	cout << __TIMESTAMP__ << "before findUsingVector" << endl;
	findUsingVector(arr, sum);
	cout << __TIMESTAMP__ << "after findUsingVector" << endl;

	cout << __TIMESTAMP__ << "before findUsingHash" << endl;
	findUsingHash(arr, sum);
	cout << __TIMESTAMP__ << "after findUsingHash" << endl;
}