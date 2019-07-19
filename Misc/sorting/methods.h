#pragma once
#include<iostream>
#include<vector>
using namespace std;


void swap(int&a, int& b);
void displayArray(vector<int>& arr, string message = "arr : ");
void copyArray(vector<int>& copyTo, vector<int>& copy);

void selectionSort(vector<int>& arr);
void selectionSort2(vector<int>& arr);
void bubbleSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void mergeSort(vector<int>& arr);
void quickSort(vector<int>& arr);
