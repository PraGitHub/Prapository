#pragma once
#include "methods.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

void callAllSortingAlgorithms(vector<int>& arr){
  int n = arr.size();
  auto start = high_resolution_clock::now();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);

  vector<int> arrOriginal;
  copyArray(arrOriginal, arr);

  //selection sort
  displayArray(arr, "Given array : ");
  cout<<"Before selectionSort"<<endl;
  start = high_resolution_clock::now();
  selectionSort(arr);
  stop = high_resolution_clock::now();
  cout<<"After selectionSort"<<endl;
  displayArray(arr, "Array after selection sort : ");
  duration = duration_cast<nanoseconds>(stop - start);
  cout << "Time taken by selectionSort: " << duration.count() << " nanoseconds" << endl<<endl;

  copyArray(arr, arrOriginal);

  //selection sort 2
  displayArray(arr, "Given array : ");
  cout<<"Before selectionSort2"<<endl;
  start = high_resolution_clock::now();
  selectionSort2(arr);
  stop = high_resolution_clock::now();
  cout<<"After selectionSort2"<<endl;
  displayArray(arr, "Array after selection sort 2 : ");
  duration = duration_cast<nanoseconds>(stop - start);
  cout << "Time taken by selectionSort2: " << duration.count() << " nanoseconds" << endl<<endl;

  copyArray(arr, arrOriginal);

  //bubble sort
  displayArray(arr, "Given array : ");
  cout<<"Before bubbleSort"<<endl;
  start = high_resolution_clock::now();
  bubbleSort(arr);
  stop = high_resolution_clock::now();
  cout<<"After bubbleSort"<<endl;
  displayArray(arr, "Array after bubble sort : ");
  duration = duration_cast<nanoseconds>(stop - start);
  cout << "Time taken by bubbleSort: " << duration.count() << " nanoseconds" << endl<<endl;

  copyArray(arr, arrOriginal);

  //insertion sort
  displayArray(arr, "Given array : ");
  cout<<"Before insertionSort"<<endl;
  start = high_resolution_clock::now();
  insertionSort(arr);
  stop = high_resolution_clock::now();
  cout<<"After insertionSort"<<endl;
  displayArray(arr, "Array after insertion sort : ");
  duration = duration_cast<nanoseconds>(stop - start);
  cout << "Time taken by insertionSort: " << duration.count() << " nanoseconds" << endl<<endl;

  copyArray(arr, arrOriginal);

  //merge sort
  displayArray(arr, "Given array : ");
  cout<<"Before mergeSort"<<endl;
  start = high_resolution_clock::now();
  mergeSort(arr);
  stop = high_resolution_clock::now();
  cout<<"After mergeSort"<<endl;
  displayArray(arr, "Array after merge sort : ");
  duration = duration_cast<nanoseconds>(stop - start);
  cout << "Time taken by mergeSort: " << duration.count() << " nanoseconds" << endl<<endl;

  copyArray(arr, arrOriginal);

  //quick sort
  displayArray(arr, "Given array : ");
  cout<<"Before quickSort"<<endl;
  start = high_resolution_clock::now();
  quickSort(arr);
  stop = high_resolution_clock::now();
  cout<<"After quickSort"<<endl;
  displayArray(arr, "Array after quick sort : ");
  duration = duration_cast<nanoseconds>(stop - start);
  cout << "Time taken by quickSort: " << duration.count() << " nanoseconds" << endl<<endl;

  return;
}

/*
int main(){
  int n;
  vector<int> arr;
  cout<<"first line : n"<<endl;
  cout<<"'n' space separated numbers to sort"<<endl;
  cin>>n;
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  callAllSortingAlgorithms(arr);
  return 0;
}
*/

int main(int NARG, char** ARGS){
  vector<int> arr;

  int num = -1;

  int gkArr[10] = {'i', 'l', 'r', 'a', 'w', 'j', 'o', 'a', 'g', 'k'};

  int n;

  cout<<"Enter n : "<<endl;
  cin>>n;

  cout<<"Generating "<<n<<" random numbers ..."<<endl;

  int count = n/2;
  for(int i=0; i<=n/2; i++){
    int gk = gkArr[i%10];
    num = gk + (i+gkArr[(i*i*gk)%10])*gkArr[(i*gk*gk)%10] + count--;
    arr.push_back(num);
  }

  for(int i=-n/2; i<0; i++){
    int gk = gkArr[i%10];
    num = gk + (i+gkArr[(i*i*gk)%10])*gkArr[(i*gk*gk)%10] + count--;
    arr.push_back(num);
  }

  cout<<"Done generating random numbers."<<endl;

  cout<<"Calling all types of sorting algorithms ..."<<endl;
  callAllSortingAlgorithms(arr);
  cout<<"Done."<<endl;

  return 0;
}
