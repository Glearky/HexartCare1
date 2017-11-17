#include "donnees.h"
#include "menu.c"

// Fonction qui lit le fichier source et qui stocke les différentes données dans le tableau de structure
int  LectureFichier()
{
    FILE* fichier = NULL;


    fichier = fopen("test.csv", "r"); // Nom du fichier a ouvrir
    int car;
    int i; // variable qui permet de parcourir les tableaux

    if (fichier != NULL)
    {
        for (i = 0; i!=SIZE; i++)//tant que i est différent de size
        {
        fscanf(fichier,"%f;%f; \n", &cardiac[i].temps,&cardiac[i].pouls);//on vas stocker les info dans la structure
        temps[i]=cardiac[i].temps;// je remplis mes tableaux
        pouls[i]= cardiac[i].pouls;
        }

        fclose(fichier);//on ferme le fichier
    }

    return 0;
}

//Fonction qui lis le fichier source et calcul le nombre de ligne contenue dans ce fichier
int  LectureFichierlongueur()
{
    FILE* fichier = NULL;


    fichier = fopen("test.txt", "r"); // Nom du fichier a ouvrir
    int car;
    int compteur = 0;
    while (!feof(fichier))
        {
        car =fgetc(fichier);// on lit chaque caractere du fichier
        if(car == ';') compteur++;//on incrémente le compteur quand on trouve un point-virgule
        }
    printf(" %d", compteur/2);// on le divise par 2 car il y en a 2 dans chaque ligne pour obtenir le nombre de ligne
    fseek( fichier , 0 , SEEK_SET );

    if (fichier != NULL)
    {
        fclose(fichier);// on ferme le fichier
    }

    return 0;
}
