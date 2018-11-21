#include "menuSort.h"
#include "sort.h"
#include "search.h"

void sortMenu()
{
    clock_t t_inicial, t_final;

    int size;
    int choice;

    double select, bubble, insertion, merge, quick;

    do{
        printf("[ - - - - - - - - - - - - - - SORT MENU - - - - - - - - - - - - - ]\n");
        printf("[ SelectSort - BubbleSort - InsertionSort - MergeSort - QuickSort ]\n\n");
        printf("1 - AP (Aleatorio Pequeno)\n");
        printf("2 - AM (Aleatorio Medio)\n");
        printf("3 - AG (Aleatorio Grande)\n");

        printf("4 - CP (Crescente Pequeno)\n");
        printf("5 - CM (Crescente Medio)\n");
        printf("6 - CG (Crescente Grande)\n");

        printf("7 - DP (Decrescente Pequeno)\n");
        printf("8 - DM (Decrescente Medio)\n");
        printf("9 - DG (Decrescente Grande)\n >");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                size = sizeArray("files/ap.txt");

                int *arr = (int*)malloc(sizeof(int)*size);

                t_inicial = clock();

                readFile(arr, "files/ap.txt");
                selectionSort(arr, size);

                t_final = clock();
                select = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                t_inicial = clock();

                readFile(arr, "files/ap.txt");
                bubbleSort(arr, size);

                t_final = clock();
                bubble = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                t_inicial = clock();

                readFile(arr, "files/ap.txt");
                insertionSort(arr, size);

                t_final = clock();
                insertion = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                t_inicial = clock();

                readFile(arr, "files/ap.txt");
                mergeSort(arr, 0, size -1);

                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                t_inicial = clock();

                readFile(arr, "files/ap.txt");
                quickSort(arr, 0, size-1);

                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                printf("\nRuntime :\nSelectSort: %lf\nBubbleSort: %lf\nInsertionSort: %lf\nMergeSort: %lf\nQuickSort: %lf\n",select ,bubble, insertion, merge, quick);

                arr = NULL;
                //printArray(arr, size);
                break;

                case 2:

                size = sizeArray("files/am.txt");
                printf("size : %d\n",size);
                system("pause");

                int *arr2 = (int*)malloc(sizeof(int)*size);

                t_inicial = clock();

                readFile(arr2, "files/am.txt");
                printf("\nSelectionSort . . . ");
                selectionSort(arr2, size);
                printf("  Done\n");

                t_final = clock();
                select = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                t_inicial = clock();

                readFile(arr2, "files/am.txt");
                bubbleSort(arr2, size);

                t_final = clock();
                bubble = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("time: %lf\n",bubble);

                t_inicial = clock();

                readFile(arr2, "files/am.txt");
                insertionSort(arr2, size);

                t_final = clock();
                insertion = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("time: %lf\n",insertion);


                t_inicial = clock();

                readFile(arr2, "files/am.txt");
                mergeSort(arr2, 0, size - 1);

                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;


                t_inicial = clock();

                readFile(arr2, "files/am.txt");
                quickSort(arr2, 0, size-1);

                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                printf("time: %lf",quick);

               printf("\nRuntime :\nSelectSort: %lf\nBubbleSort: %lf\nInsertionSort: %lf\nMergeSort: %lf\nQuickSort: %lf\n",select ,bubble, insertion, merge, quick);

                break;



        }



    }while(choice != 0);
}
