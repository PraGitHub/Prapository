#include<iostream>
using namespace std;

long int* fibSeries(int n = 1)
{
	long int* arr = new long int[n];
	if(n == 1)
	{
		arr[0] = 0;
		return arr;
	}
	
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i < n; i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}
	return arr;
	
}

int main()
{
	cout << "main :: begin" << endl;
	int n;
	cout << "Enter n : " << endl;
	cin >> n;
	if(n <= 0)
	{
		cout << "n should be greater than or equal to 1"<<endl;
		return 0;
	}
	long int* fibArr = fibSeries(n);
	if(fibArr)
	{
		cout << "Fibonicci series : n = " << n << endl;
		for(int i = 0; i < n; i++)
		{
			cout << fibArr[i] << endl;
		}
	}
	else
	{
		cout << "Something's strange !" << endl;
	}
	cout << "main :: end" << endl;
	return 0;
}
