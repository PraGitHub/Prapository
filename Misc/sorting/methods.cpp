#pragma once
#include "methods.h"
using namespace std;

void swap(int& a, int& b){
  int temp = a; // to avoid loss of data incase if sum of a and b is beyond the limits of selectionSort
  a = b;
  b = temp;
  return;
}

void displayArray(vector<int>& arr, string message){
  int n = arr.size();
  cout<<"-----------------------------------------------------------------------"<<endl;
  cout<<message<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<"-----------------------------------------------------------------------"<<endl;
  return;
}

void copyArray(vector<int>& copyTo, vector<int>& copy){
  int n = copy.size();
  copyTo.clear();
  for(int i=0; i<n; i++){
    copyTo.push_back(copy[i]);
  }
  return;
}

void selectionSort(vector<int>& arr){
  //first element of a sorted array is always gonna be the smallest
  int n = arr.size();
  if(n <= 1) return;

  for(int i=0; i<n-1; i++){
    int smallestIndex = i;
    for(int j=i+1; j<n; j++){
      if(arr[j]<arr[smallestIndex]){
        smallestIndex = j;
      }
    }
    swap(arr[i], arr[smallestIndex]);
  }
  //displayArray(arr, "selectionSort :: array after sorting : ");
  return;
}

void bubbleSort(vector<int>& arr){
  //keep on swapping adjacent elements of left element is greater than right elements
  int n = arr.size();
  if(n <= 1) return;

  for(int i=0; i<n-1; i++){
    for(int j=1; j<n-i; j++){
      if(arr[j-1] > arr[j]){
        swap(arr[j-1], arr[j]);
      }
    }
  }

  return;
}

void insertionSort(vector<int>& arr){
  //insert element one by one in a new array and make sure that it is sorted everytime a new element is inserted
  int n = arr.size();
  if(n <= 1) return;

  int end = 0; // end is the index of last element of new array. here we are sorting on place, so the new array is the given array itself
  for(int i=1; i<n; i++){
    end = i-1;
    if(arr[i] >= arr[end]){
      continue;
    }
    end--;
    while(end >= -1){
      if(arr[end] <= arr[i] || end == -1){
        int temp = arr[end+1];
        arr[end+1] = arr[i];
        end++;
        while(end < i){
          int temp1 = arr[end+1];
          arr[end+1] = temp;
          temp = temp1;
          end++;
        }
        break;
      }
      end--;
    }
  }

  return;
}

vector<int> merge(vector<int> a, vector<int> b){
  vector<int> arr;
  int aSize = a.size();
  int bSize = b.size();

  if(aSize == 0) return b;
  if(bSize == 0) return a;

  int aStart = 0;
  int bStart = 0;

  while(aStart<aSize || bStart<bSize){
    if(aStart == aSize){
      for(int i=bStart; i<bSize; i++){
        arr.push_back(b[i]);
      }
      break;
    }

    if(bStart == bSize){
      for(int i=aStart; i<aSize; i++){
        arr.push_back(a[i]);
      }
      break;
    }

    if(a[aStart] <= b[bStart]){
      arr.push_back(a[aStart]);
      aStart++;
    }else{
      arr.push_back(b[bStart]);
      bStart++;
    }
  }

  /*
  cout<<"Merge :: "<<endl;
  displayArray(a, "a : ");
  displayArray(b, "b : ");
  displayArray(arr, "arr : ");
  */

  return arr;
}

vector<int> merge_sort(vector<int>& arr, int start, int end){
  if(start == end) return vector<int>(1,arr[start]);

  int mid = start + (end-start)/2;

  vector<int> left = merge_sort(arr, start, mid);

  vector<int> right = merge_sort(arr, mid+1, end);

  return merge(left, right);
}

void mergeSort(vector<int>& arr){
  //keep splitting the array till they become elementary. Then start merging them. merging can be done with linear time complexity
  int n = arr.size();
  if(n <= 1) return;

  vector<int> mergeSortedArr = merge_sort(arr, 0, n-1);
  copyArray(arr, mergeSortedArr);

  return;
}

int partition(vector<int>& arr, int start, int end){
  int pivot = arr[(end+start)/2];
  int partitionIndex = start;
  for(int i=start; i<=end; i++){
    
  }
}

void quick_sort(vector<int>& arr, int start, int end){
  if(start == end) return;

  int partitionIndex = partition(arr, start, end);

  quick_sort(arr, start, partitionIndex-1);

  quick_sort(arr, partitionIndex+1, end);

  return;
}

void quickSort(vector<int>& arr){
  //select some random element => pivot and partition the array such that elements less than pivot should be towards its left and the elements greater than it should be towards its right
  int n = arr.size();
  if(n <= 1) return;

  quick_sort(arr, 0, n-1);

  return;
}
