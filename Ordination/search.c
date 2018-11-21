#include "search.h"

int orderedLinearSearch(long int arr[], int size , int num)
{
    int i;

    for(i=0; i<size; i++)
    {
        if(num == arr[i])
        {
            return arr[i];
        }else
            if (num < arr[i])
            {
                //printf("\nValue not found !\n");
                return -1;
            }
    }
    return -1;
}

int linearSearch(long int arr[], int size , int num)
{
    int i;

    for(i=0; i<size; i++)
    {
        if(num == arr[i])
        {
            return arr[i];
        }
    }
    return -1;
}

int binarySearch(long int arr[], int size, int num)
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
            return mid;
        }
    }
    //printf("Value not found !\n");
    return -1;
}

void ReadOrderedLinearSearch(long int arr[], int size)
{
    int number;

    FILE* busca = fopen("search.txt", "r");

    while(!feof(busca))
    {
        fscanf(busca, "%d", &number);
        orderedLinearSearch(arr, size, number);
    }
    fclose(busca);
}

void ReadLinearSearch(long int arr[], int size)
{
    int number;

    FILE* busca = fopen("search.txt", "r");

    while(!feof(busca))
    {
        fscanf(busca, "%d", &number);
        binarySearch(arr, size, number);
    }
    fclose(busca);
}
