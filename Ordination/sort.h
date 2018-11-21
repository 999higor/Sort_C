#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include<stdbool.h>

void swap(int* a, int* b);

void selectionSort(int arr[], int n);   ///SELECTION SORT

int partition (int arr[], int low, int high);

void quickSort(int arr[], int low, int high) ;  ///QUICK SORT

void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r);    ///MERGE SORT

void bubbleSort(int arr[], int n);  ///BUBBLE SORT

void insertionSort(int arr[], int n); ///INSERTION SORT



#endif // SORT_H_INCLUDED