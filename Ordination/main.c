#include <stdio.h>

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
   // return arr;
}

int main()
{
    int size;

    size = sizeArray();

    int arr[size];

    readFile(arr);

    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Sorted array: \n");

    printArray(arr, n);
    return 0;
}
