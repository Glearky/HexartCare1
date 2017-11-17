#include "menu.h"

void menu()
{
    int choix = 0;

    printf("\t********** MENU **********\n\n");
    printf("\t 1.  Afficher le fichier \n");
    printf("\t 2.  Affichage croissant pouls\n");
    printf("\t 3.  Affichage croissant temps\n");
    printf("\t 4.  Afficher decroissant pouls \n");
    printf("\t 5.  Affichage decroissant temps \n");
    printf("\t 6.  Affichage du pouls max \n");
    printf("\t 7.  Affichage du pouls min \n");
    printf("\t 8.  Affichage du nombre de ligne en memoire \n");
    printf("\t 9.  Rechercher les donnees pour certain temps \n");
    printf("\t 10. Rechercher une moyenne sur une plage de temps \n");
    printf("\t 11. Quitter le programme \n");
    printf("\n\n Veuillez choisir une option:\n\n");

    scanf("%d",&choix);//On entre le choix
//Les switch servent a se rendre sur la fonction choisis par l'utilisateur
    switch (choix)
    {
        case 1:
            affichage();
        break;
        case 2:
            croissant_pouls();
        break;
        case 3:
            croissant_temps();
            break;
        case 4:
            decroissant_pouls();
            break;
        case 5:
            decroissant_temps();
            break;
        case 6:
            max_pouls();
        break;
        case 7:
            min_pouls();
        break;
        case 8:
            nb_ligne();
            break;
        case 9:
            recherche_tps();
            break;
        case 10:
            moyenne();
            break;
        case 11:
            break;
        default:
        break;

    }

}
