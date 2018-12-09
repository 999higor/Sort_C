#include "sort.h"

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int arr[], int n) ///SELECTION SORT
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
void quicksort25(int number[],int first,int last)
{
   int i, j, pivot, temp;

   if(first<last)
    {
      pivot=first;
      i=first;
      j=last;

      while(i<j)
        {
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort25(number,first,j-1);
      quicksort25(number,j+1,last);

   }
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
void quickSort(int arr[], int low, int high)    ///QUICK SORT
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

int count;
void QuickSortMedian(int a[],int start,int end)
{
    int q;
    count++;
    if (end-start<2) return;
    q=MedianOfThreePartition(a,start,end);
    QuickSortMedian(a,start,q);
    QuickSortMedian(a,q,end);
}

int MedianOfThreePartition(int a[],int p, int r)
{
    int x=a[p],y=a[(r-p)/2+p],z=a[r-1],i=p-1,j=r;
    if ((y>x && y<z) || (y>z && y<x) ) x=y;
    else if ((z>x && z<y) || (z>y && z<x) ) x=z;
    while (1) {
        do  {j--;count++;} while (a[j] > x);
        do  {i++;count++;} while (a[i] < x);
        if  (i < j) swap(&a[i],&a[j]);
        else return j+1;
    }
}


/*void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


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


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}*/

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
/*void mergeSort(int arr[], int l, int r)     ///MERGE SORT
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
}*/


void mergesort(int v[], int n)
{
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int v[], int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int v[], int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] < c[ic]) v[z++] = c[iv++];
    else /* if (c[iv] > c[ic]) */ v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}

void bubbleSort(int arr[], int n) ///BUBBLE SORT
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}

void insertionSort(int arr[], int n) ///INSERTION SORT
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int sizeArray(char* vrau)
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

void readFile(int arr[], char* vrau)
{
    int numero, i=0;

    //printf("string %s",vrau);

    FILE* file = fopen (vrau, "r");

    while (!feof(file)){

        fscanf(file, "%d", &numero);

        arr[i] = numero;
        i++;
    }
    fclose(file);
}
