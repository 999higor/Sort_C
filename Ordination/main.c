#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, minValue;

    for (i = 0; i < n-1; i++)
    {
        ///procura o menor elemento
        minValue = i;

        for (j = i+1; j < n; j++)
          if (arr[j] < arr[minValue])
            minValue = j;

        ///troca do menor elemento com o primeiro
        int temp = arr[minValue];
        arr[minValue] = arr[i];
        arr[i] = temp;
    }
}

/// swap de elementos
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    /// pivo

    int i = (low - 1);  /// menor elemento
    int j;
    for (j = low; j <= high - 1; j++)
    {
        /// se o elemento for menor ou igual ao pivo

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


/// arr[] --> Array to be sorted,
///  low  --> Starting index,
///  high  --> Ending index
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int sizeArray()
{
    int numero, i=0;

    FILE* file = fopen ("values.txt", "r");

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
}

int main()
{
    clock_t t_inicial, t_final;
    double tempo=0;

    int size;

    size = sizeArray();

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

                    readFile(arr);
                    selectionSort(arr, size);

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

                    readFile(arr2);
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

                    readFile(arr3);
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
