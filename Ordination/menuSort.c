#include "menuSort.h"
#include "sort.h"
#include "search.h"

void sortMenu()
{
    clock_t t_inicial, t_final;

    int size;
    int choice;

    FILE *result_sort;

    //char* file = "";


    double select, bubble, insertion, merge, quick;

    do{
        printf("[ - - - - - - - - - - - - - - SORT MENU - - - - - - - - - - - - - ]\n");
        printf("[ SelectSort - BubbleSort - InsertionSort - MergeSort - QuickSort ]\n\n");
        printf("1 - AP [Aleatorio Pequeno]\n");
        printf("2 - AM [Aleatorio Medio]\n");
        printf("3 - AG [Aleatorio Grande]\n");

        printf("4 - CP [Crescente Pequeno]\n");
        printf("5 - CM [Crescente Medio]\n");
        printf("6 - CG [Crescente Grande]\n");

        printf("7 - DP [Decrescente Pequeno]\n");
        printf("8 - DM [Decrescente Medio]\n");
        printf("9 - DG [Decrescente Grande]\n >");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                result_sort = fopen("result_sort.txt", "a");
                printf("SORT - AP\n");
                char* ap = "files/ap.txt";
                //file = "file/ap.txt";

                fprintf(result_sort, "SORT - AP\n");
                size = sizeArray(ap);


                int *arr = (int*)malloc(sizeof(int)*size);


                readFile(arr, ap);

                t_inicial = clock();

                selectionSort(arr, size);
                t_final = clock();
                select = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "SELECT : %lf\n",select);


                readFile(arr, ap);
                t_inicial = clock();
                bubbleSort(arr, size);
                t_final = clock();
                bubble = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "BUBBLE : %lf\n",bubble);


                readFile(arr, ap);
                t_inicial = clock();
                insertionSort(arr, size);
                t_final = clock();
                insertion = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "INSERTION : %lf\n",insertion);


                readFile(arr, ap);
                 t_inicial = clock();
                mergesort(arr, size);
                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "MERGE : %lf\n",merge);


                readFile(arr, ap);
                t_inicial = clock();
                quickSort(arr, 0, size-1);
                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "QUICK : %lf\n",quick);

                fclose(result_sort);

                printf("\nRuntime :\nSelectSort: %lf\nBubbleSort: %lf\nInsertionSort: %lf\nMergeSort: %lf\nQuickSort: %lf\n",select ,bubble, insertion, merge, quick);

                arr = NULL;
                break;


                case 2:
                result_sort = fopen("result_sort.txt", "a");

                char* am = "files/am.txt";
               // file = "file/am.txt";
                printf("SORT - AM\n");

                fprintf(result_sort, "\nSORT - AM\n");
                size = sizeArray(am);

                int *arr2 = (int*)malloc(sizeof(int)*size);


                readFile(arr2, am);
                t_inicial = clock();
                selectionSort(arr2, size);
                t_final = clock();
                select = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "SELECT : %lf\n",select);


                readFile(arr2, am);
                t_inicial = clock();
                bubbleSort(arr2, size);
                t_final = clock();
                bubble = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "BUBBLE : %lf\n",bubble);


                readFile(arr2, am);
                t_inicial = clock();
                insertionSort(arr2, size);
                t_final = clock();
                insertion = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "INSERTION : %lf\n",insertion);


                readFile(arr2, am);
                t_inicial = clock();
                mergesort(arr2, size);
                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "MERGE : %lf\n",merge);


                readFile(arr2, am);
                quickSort(arr2, 0,size-1);
                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "QUICK : %lf\n",quick);

                fclose(result_sort);

                printf("\nRuntime :\nSelectSort: %lf\nBubbleSort: %lf\nInsertionSort: %lf\nMergeSort: %lf\nQuickSort: %lf\n",select ,bubble, insertion, merge, quick);

                break;

                case 3:
                result_sort = fopen("result_sort.txt", "a");

                char* ag = "files/ag.txt";
                //file = "file/ag.txt";

                fprintf(result_sort, "\nSORT - AG\n");
                size = sizeArray(ag);

                printf("SORT - AG\n");

                int *arr3 = (int*)malloc(sizeof(int)*size);


                readFile(arr3, ag);
                t_inicial = clock();
                mergesort(arr3, size);
                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "MERGE : %lf\n",merge);


                readFile(arr3, ag);
                t_inicial = clock();
                QuickSortMedian(arr3, 0, size-1);
                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "QUICK : %lf\n",quick);

                fclose(result_sort);

                printf("\nRuntime : \nMergeSort: %lf\nQuickSort: %lf\n", merge, quick);

                break;

                case 4:
                result_sort = fopen("result_sort.txt", "a");

                char* cp = "files/cp.txt";
                //file = "file/cp.txt";

                fprintf(result_sort, "\nSORT - CP\n");
                size = sizeArray(cp);


                int *arr4 = (int*)malloc(sizeof(int)*size);


                readFile(arr4, cp);
                t_inicial = clock();
                selectionSort(arr4, size);
                t_final = clock();
                select = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "SELECT : %lf\n",select);


                readFile(arr4, cp);
                t_inicial = clock();
                bubbleSort(arr4, size);
                t_final = clock();
                bubble = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "BUBBLE : %lf\n",bubble);


                readFile(arr4, cp);
                t_inicial = clock();
                insertionSort(arr4, size);
                t_final = clock();
                insertion = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "INSERTION : %lf\n",insertion);


                readFile(arr4, cp);
                t_inicial = clock();
                mergesort(arr4, size);
                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "MERGE : %lf\n",merge);


                readFile(arr4, cp);
                t_inicial = clock();
                QuickSortMedian(arr4, 0, size);
                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "QUICK : %lf\n",quick);

                fclose(result_sort);

                printf("\nRuntime :\nSelectSort: %lf\nBubbleSort: %lf\nInsertionSort: %lf\nMergeSort: %lf\nQuickSort: %lf\n",select ,bubble, insertion, merge, quick);

                arr4 = NULL;
                break;



                case 5:
                result_sort = fopen("result_sort.txt", "a");

                char* cm = "files/cm.txt";
                //file = "file/cm.txt";

                fprintf(result_sort, "\nSORT - CM\n");
                size = sizeArray(cm);

                int *arr5 = (int*)malloc(sizeof(int)*size);


                readFile(arr5, cm);
                t_inicial = clock();
                selectionSort(arr5, size);
                t_final = clock();
                select = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "SELECT : %lf\n",select);
                //printf("aqui 1\n");


                readFile(arr5, cm);
                t_inicial = clock();
                bubbleSort(arr5, size);
                t_final = clock();
                bubble = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "BUBBLE : %lf\n",bubble);
                //printf("aqui 2\n");


                readFile(arr5, cm);
                t_inicial = clock();
                insertionSort(arr5, size);
                t_final = clock();
                insertion = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "INSERTION : %lf\n",insertion);
               // printf("aqui 3\n");


                readFile(arr5, cm);
                t_inicial = clock();
                mergesort(arr5, size);
                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "MERGE : %lf\n",merge);
              //  printf("aqui 4\n");


               // printf("quick \n");
                readFile(arr5, cm);
                t_inicial = clock();
                QuickSortMedian(arr5, 0, size);
                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "QUICK : %lf\n",quick);
               // printf("aqui 5\n");

                fclose(result_sort);

                printf("\nRuntime :\nSelectSort: %lf\nBubbleSort: %lf\nInsertionSort: %lf\nMergeSort: %lf\nQuickSort: %lf\n",select ,bubble, insertion, merge, quick);

                arr5 = NULL;
                break;

                case 6:
                result_sort = fopen("result_sort.txt", "a");

                char* cg = "files/cg.txt";
                //file = "file/cg.txt";
                fprintf(result_sort, "\nSORT - CG\n");
                size = sizeArray(cg);

                int *arr6 = (int*)malloc(sizeof(int)*size);


                readFile(arr6, cg);
                t_inicial = clock();
                mergesort(arr6,  size);
                //printf("aqui 1\n");
                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "MERGE : %lf\n",merge);


                readFile(arr6, cg);
                t_inicial = clock();
                QuickSortMedian(arr6, 0, size-1);
               // printf("aqui 2");
                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "QUICK : %lf\n",quick);

                fclose(result_sort);

                printf("\nRuntime : \nMergeSort: %lf\nQuickSort: %lf\n", merge, quick);
                arr6 = NULL;
                break;

                case 7:
                result_sort = fopen("result_sort.txt", "a");

                char* dp = "files/dp.txt";
                //file = "file/dp.txt";

                fprintf(result_sort, "\nSORT - DP\n");
                size = sizeArray(dp);

                int *arr7 = (int*)malloc(sizeof(int)*size);


                readFile(arr7, dp);
                t_inicial = clock();
                selectionSort(arr7, size);
                t_final = clock();
                select = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "SELECT : %lf\n",select);

                readFile(arr7, dp);
                t_inicial = clock();
                bubbleSort(arr7, size);
                t_final = clock();
                bubble = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "BUBBLE : %lf\n",bubble);


                readFile(arr7, dp);
                t_inicial = clock();
                insertionSort(arr7, size);
                t_final = clock();
                insertion = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "INSERTION : %lf\n",insertion);


                readFile(arr7, dp);
                t_inicial = clock();
                mergesort(arr7, size);
                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "MERGE : %lf\n",merge);


                readFile(arr7, dp);
                t_inicial = clock();
                QuickSortMedian(arr7, 0, size-1);
                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "QUICK : %lf\n",quick);

                fclose(result_sort);

                printf("\nRuntime :\nSelectSort: %lf\nBubbleSort: %lf\nInsertionSort: %lf\nMergeSort: %lf\nQuickSort: %lf\n",select ,bubble, insertion, merge, quick);

                arr7 = NULL;
                break;

                case 8:
                result_sort = fopen("result_sort.txt", "a");

                char* dm = "files/dm.txt";
                //file = "file/dm.txt";

                fprintf(result_sort, "\nSORT - DM\n");
                size = sizeArray(dm);

                int *arr8 = (int*)malloc(sizeof(int)*size);


                readFile(arr8, dm);
                t_inicial = clock();
                selectionSort(arr8, size);
                t_final = clock();
                select = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "SELECT : %lf\n",select);


                readFile(arr8, dm);
                t_inicial = clock();
                bubbleSort(arr8, size);
                t_final = clock();
                bubble = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "BUBBLE : %lf\n",bubble);


                readFile(arr8, dm);
                t_inicial = clock();
                insertionSort(arr8, size);
                t_final = clock();
                insertion = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "INSERTION : %lf\n",insertion);


                readFile(arr8, dm);
                t_inicial = clock();
                mergesort(arr8, size - 1);
                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "MERGE : %lf\n",merge);


                readFile(arr8, dm);
                t_inicial = clock();
                QuickSortMedian(arr8, 0, size);
                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "QUICK : %lf\n",quick);

                fclose(result_sort);

                printf("\nRuntime :\nSelectSort: %lf\nBubbleSort: %lf\nInsertionSort: %lf\nMergeSort: %lf\nQuickSort: %lf\n",select ,bubble, insertion, merge, quick);

                arr8 = NULL;
                break;

                case 9:
                result_sort = fopen("result_sort.txt", "a");

                char* dg = "files/dg.txt";
                //file = "file/dg.txt";

                fprintf(result_sort, "\nSORT - DG\n");
                size = sizeArray(dg);

                int *arr9 = (int*)malloc(sizeof(int)*size);


                readFile(arr9, dg);
                t_inicial = clock();
                mergesort(arr9, size);
                t_final = clock();
                merge = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "MERGE : %lf\n",merge);


                readFile(arr9, dg);
                t_inicial = clock();
                QuickSortMedian(arr9, 0, size-1);
                t_final = clock();
                quick = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                fprintf(result_sort, "QUICK : %lf\n",quick);

                fclose(result_sort);

                printf("\nRuntime : \nMergeSort: %lf\nQuickSort: %lf\n", merge, quick);
                arr9 = NULL;

                break;

                case 0:
                    break;

                default:
                    printf("Opção inválida !\n");
                    break;
        }

    }while(choice != 0);
}
