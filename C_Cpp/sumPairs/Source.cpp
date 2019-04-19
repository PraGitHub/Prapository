#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<chrono>
#include<sstream>

using namespace std;

#define NumOfInt 1000

typedef vector<int> intvec;
typedef unordered_set<int> inthash; //unordered_set is actaully unordered_map which is basicaly a hash table. for unordered_set key and values are same

void printTime()
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();

	typedef std::chrono::duration<int, std::ratio_multiply<std::chrono::hours::period, std::ratio<8>>::type> Days; /* UTC: +8:00 */

	Days days = std::chrono::duration_cast<Days>(duration);
	duration -= days;
	auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
	duration -= hours;
	auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
	duration -= minutes;
	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
	duration -= seconds;
	auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
	duration -= milliseconds;
	auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);
	duration -= microseconds;
	auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

	std::cout << hours.count() << ":"
		<< minutes.count() << ":"
		<< seconds.count() << ":"
		<< milliseconds.count() << ":"
		<< microseconds.count() << ":"
		<< nanoseconds.count()<<"\t";
}

ostringstream* findUsingVector(intvec &arr, int sum)
{
	int start = 0;
	int end = arr.size() - 1;
	sort(arr.begin(), arr.end());
	ostringstream* poss = new ostringstream();
	*poss<<"";
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
			//cout << arr[start] << "\t" << arr[end] << endl;
			*poss << arr[start] << "\t" << arr[end] << endl;
			start++;
			end--;
		}
	}
	return poss;
}

ostringstream* findUsingHash(intvec &arr, int sum)
{
	inthash hash;
	ostringstream* poss = new ostringstream();
	*poss<<"";
	for (int i = 0; i < arr.size(); i++)
	{
		if (i == 0)
		{
			hash.insert(arr[i]);
			continue;
		}

		if (hash.find(sum - arr[i]) != hash.end())
		{
			//cout << arr[i] << "\t" << sum - arr[i] << endl;
			*poss << arr[i] << "\t" << sum - arr[i] << endl;
		}

		hash.insert(arr[i]);
	}
	return poss;
}

int main(int NARG, char** ARGS)
{
	intvec arr;
	int sum = rand();
	int num = NumOfInt;

	//int temp[] = { -1,3,4,0,2,10,1,5,6,-3,3,3,-4,1,2,1,2,0,0,0 };
	//sum = 0;

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
	cout << "sum = " << sum << endl;
	
	//exit(0);

	for (int i = 0; i < num; i++)
	{
		arr.push_back(rand());
		//arr.push_back(temp[i]);
	}

	printTime();
	cout << "before findUsingHash" << endl;
	ostringstream* poss1 = findUsingHash(arr, sum);
	printTime();
	cout << "after findUsingHash" << endl;
	cout<<"findUsingHash results : "<<endl;
	cout<<poss1->str()<<endl;

	printTime();
	cout << "before findUsingVector" << endl;
	ostringstream* poss2 = findUsingVector(arr, sum);
	printTime();
	cout << "after findUsingVector" << endl;
	cout<<"findUsingVector results : "<<endl;
	cout<<poss2->str()<<endl;
}
