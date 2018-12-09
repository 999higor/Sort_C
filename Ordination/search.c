#include "search.h"

int orderedLinearSearch( int arr[], int size , int num)
{
    int i;

    for(i=0; i<size; i++)
    {
        if(num == arr[i])
        {
            //return arr[i];
            return 0;
        }else
            if (num < arr[i])
            {
                //printf("\nValue not found !\n");
                return 1;
            }
    }
    return 1;
}

int linearSearch( int arr[], int size , int num)
{
    int i;

    for(i=0; i<size; i++)
    {
        if(num == arr[i])
        {
            //return arr[i];
            return 0;
        }
    }
    return 1;
}

int binarySearch( int arr[], int size, int num)
{
    int begin, mid, end;
    begin = 0;

    end = size -1;

    //printf("size: %d\n" ,end);

    while(begin <= end)
    {
        mid = (begin + end)/2;
        if(num < arr[mid])
        {
            end = mid - 1;
        }
        else if(num > arr[mid])
        {
            begin = mid + 1;
        }else
        {
           // printf("\nValue found !\n ");
            return 0;
        }
    }
    //printf("Value not found !\n");
    return 1;
}

void ReadOrderedLinearSearch( int arr[], int size)
{
    int number;
    int value;

    FILE* search = fopen("search", "r");
    FILE* linearOrdered = fopen("LinearOrdered", "w");

    while(!feof(search))
    {
        fscanf(search, "%d", &number);
        value = orderedLinearSearch(arr, size, number);
        fprintf(linearOrdered, "%d",value);
    }
    fclose(search);
    fclose(linearOrdered);
}

void ReadLinearSearch( int arr[], int size)
{
    int number;
    int value;

    FILE* search = fopen("search", "r");
    FILE* linear = fopen("Linear", "w");

    while(!feof(search))
    {
        fscanf(search, "%d", &number);
        value = linearSearch(arr, size, number);
        fprintf(linear, "%d",value);
    }
    fclose(search);
    fclose(linear);
}

void ReadBinarySearch( int arr[], int size)
{
    int number;
    int value;
    FILE* binary = fopen("binary", "w");
    FILE* search = fopen("search", "r");

    while(!feof(search))
    {
        fscanf(search, "%d", &number);
        value = binarySearch(arr, size, number);
        fprintf(binary, "%d",value);
    }
    fclose(search);
    fclose(binary);
}
