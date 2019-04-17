#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
#include<cstdlib>

using namespace std;

#define NumOfInt 1000

typedef vector<int> intvec;
typedef set<int> intset;
typedef unordered_set<int> inthash; //unordered_set is actaully unordered_map which is basicaly a hash table. for unordered_set key and values are same

void findUsingSet(intvec &arr, int sum)
{

}

void findUsingUnorderedSet(intvec &arr, int sum)
{

}

int main(int NARG, char** ARGS)
{
	intvec arr;
	int sum = rand();
	int num = NumOfInt;
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
	for (int i = 0; i < num; i++)
	{
		arr.push_back(rand());
	}
	findUsingSet(arr, sum);
	findUsingUnorderedSet(arr, sum);
}