#pragma once
#include "methods.h"
using namespace std;

void callAllSortingAlgorithms(vector<int>& arr){
  int n = arr.size();
  vector<int> arrOriginal;
  copyArray(arrOriginal, arr);

  //selection sort
  displayArray(arr, "Given array : ");
  selectionSort(arr);
  displayArray(arr, "Array after selection sort : ");

  copyArray(arr, arrOriginal);

  //bubble sort
  displayArray(arr, "Given array : ");
  bubbleSort(arr);
  displayArray(arr, "Array after bubble sort : ");

  copyArray(arr, arrOriginal);

  //insertion sort
  displayArray(arr, "Given array : ");
  insertionSort(arr);
  displayArray(arr, "Array after insertion sort : ");

  copyArray(arr, arrOriginal);

  //merge sort
  displayArray(arr, "Given array : ");
  mergeSort(arr);
  displayArray(arr, "Array after merge sort : ");
}

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
