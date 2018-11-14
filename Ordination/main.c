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
    for (j = low; j <= high- 1; j++)
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

    int op;

    do{
            printf("1 - READ - Selection Sort\n");
            printf("2 - PRINT - Selection Sort\n");
            printf("3 - READ - Quick Sort\n");
            printf("4 - PRINT - Quick Sort\n");
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
                    quickSort(arr2, 0, size-1);

                    t_final = clock();
                    tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                    printf("Time: %lf \n",tempo);
                    break;

                case 4:
                    printf("Sorted array: \n");
                    printArray(arr2, size);
                    break;


            }

    }while(op!=0);

    return 0;
}
