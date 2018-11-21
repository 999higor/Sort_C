#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#include "sort.h"
#include "search.h"
#include "menuSort.h"

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*int sizeArray(char* vrau)
{
    int numero, i=0;

    FILE* file = fopen (vrau, "r");

    while (!feof(file)){

        fscanf(file, "%d", &numero);
        i++;
    }
    fclose(file);
    return i;
}

void readFile(int arr[])
{
    int numero, i=0;

    FILE* file = fopen ("values.txt", "r");

    while (!feof(file)){

        fscanf(file, "%d", &numero);

        arr[i] = numero;
        i++;
    }
    fclose(file);
}*/

int main()
{
    clock_t t_inicial, t_final;
    double tempo=0;

    int size;

    sortMenu();

    size = sizeArray("values.txt");

    int *arr = (int*)malloc(sizeof(int)*size); ///array selection
    int *arr2 = (int*)malloc(sizeof(int)*size); ///array quick
    int *arr3 = (int*)malloc(sizeof(int)*size); ///array mergeSort

    int op;

    do{
            printf("1 - READ - Selection Sort\n");
            printf("2 - PRINT - Selection Sort\n");
            printf("3 - READ - Quick Sort\n");
            printf("4 - PRINT - Quick Sort\n");
            printf("5 - READ - Merge Sort\n");
            printf("6 - PRINT - Merge Sort\n");
            printf(">\n");
            scanf("%d",&op);

            switch(op)
            {
                case 1:
                    t_inicial = clock();

                  //  readFile(arr);
                  //  selectionSort(arr, size);

                    t_final = clock();
                    tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                    printf("Time: %lf \n",tempo);
                    break;

                case 2:
                    printf("Sorted array: \n");
                    printArray(arr ,size);
                    break;

                case 3:
                    t_inicial = clock();

                   // readFile(arr2);
                    quickSort(arr2, 0, size - 1);

                    t_final = clock();
                    tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                    printf("Time: %lf \n",tempo);
                    break;

                case 4:
                    printf("Sorted array: \n");
                    printArray(arr2, size);
                    break;

                 case 5:
                    t_inicial = clock();

               //     readFile(arr3);
                    //quickSort(arr2, 0, size-1);
                    mergeSort(arr3, 0, size - 1);

                    t_final = clock();
                    tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                    printf("Time: %lf \n",tempo);
                    break;

                case 6:
                    printf("Sorted array: \n");
                    printArray(arr3, size);
                    break;


            }

    }while(op!=0);

    return 0;
}
