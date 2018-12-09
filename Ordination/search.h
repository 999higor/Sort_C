#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<locale.h>

int orderedLinearSearch( int arr[], int size , int num);

int binarySearch( int arr[], int size, int num);

int linearSearch( int arr[], int size , int num);

void ReadOrderedLinearSearch( int arr[], int size);

void ReadLinearSearch( int arr[], int size);

void ReadBinarySearch( int arr[], int size);




#endif // SEARCH_H_INCLUDED
