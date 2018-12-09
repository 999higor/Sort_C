#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#include "sort.h"
#include "search.h"
#include "menuSort.h"
#include "menuSearch.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");


    int op;

    do{
            printf("1 - Menu Sort\n");
            printf("2 - Menu Search\n");
            printf(">\n");
            scanf("%d",&op);

            switch(op)
            {
            case 1:
                sortMenu();
                break;

            case 2:
                menuSearch();

                break;

            default:
                printf("Opção inválida !\n");
                break;

            }

    }while(op!=0);

    return 0;
}
