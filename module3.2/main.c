#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generationCode.h"

int main()
{   int a;
    affichage();
    scanf("%d", &a);
    printf("\n");

    switch(a)
    {
        case 1:coeur();
            break;

        case 2:coeur2();
            break;

        case 3:coeur3();
            break;

        case 4:coeur4();
            break;

        case 5:coeur5();
            break;

        default:
            printf("Choisir le mode d'allumage");
    }
    return 0;
}
