#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<locale.h>

int orderedLinearSearch(long int arr[], int size , int num);

int binarySearch(long int arr[], int size, int num);

int linearSearch(long int arr[], int size , int num);

void ReadOrderedLinearSearch(long int arr[], int size);

void ReadLinearSearch(long int arr[], int size);




#endif // SEARCH_H_INCLUDED
