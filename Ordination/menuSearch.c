#include "menuSearch.h"
#include "search.h"
#include "sort.h"

void menuSearch()
{
    clock_t t_inicial, t_final;

    int option;
    int size;
    double time;

    printf("Creating the Vector . . .\n");
    char* cg = "files/cg.txt";
    size = sizeArray(cg);
    int *arr = (int*)malloc(sizeof(int)*size);
    printf(" Done !");

    do
    {
        printf("[ - - - - - - - - - - - - - - SEARCH MENU - - - - - - - - - - - - - ]\n");
        printf("[ - - - - - - - - ARQUIVO CG [ CRESCENTE GRANDE ] - - - - - - - - - ]\n\n");
        printf("1 - Busca Linear\n");
        printf("2 - Busca Linear Ordenada\n");
        printf("3 - Busca Binária\n");
        printf("\n> ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                t_inicial = clock();
                printf("Searching . . .\n");
                ReadLinearSearch(arr, size);
                t_final = clock();
                time = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("Runtime: %lf", time);
                //fprintf(result_sort, "SELECT : %lf\n",select);
                break;

            case 2:
                t_inicial = clock();
                printf("Searching . . .\n");
                ReadOrderedLinearSearch(arr, size);
                t_final = clock();
                time = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("Runtime: %lf", time);
                break;

            case 3:
                t_inicial = clock();
                printf("Searching . . .\n");
                ReadBinarySearch(arr, size);
                t_final = clock();
                time = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("Runtime: %lf", time);
                break;

            case 0:
                break;

            default:
                printf("Opção inválida !\n");
                break;
        }


    }while(option != 0);

    arr = NULL;

}
