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

void quicksort25(int number[],int first,int last);

void QuickSortMedian(int a[],int start,int end); ///QUICK SORT FUNCIONAL

int MedianOfThreePartition(int a[],int p, int r);

//void merge(int arr[], int l, int m, int r);

//void mergeSort(int arr[], int l, int r);    ///MERGE SORT

void mergesort(int v[], int n);    ///MERGE SORT FUNCIONAL

void sort(int v[], int *c, int i, int f);

void merge(int v[], int *c, int i, int m, int f);


void bubbleSort(int arr[], int n);  ///BUBBLE SORT

void insertionSort(int arr[], int n); ///INSERTION SORT

int sizeArray(char* vrau);

void readFile(int arr[], char* vrau);



#endif // SORT_H_INCLUDED
