#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"

void coeur(void)
{
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n");
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 0\n");
    fprintf(fichier, "#define INIT 0\n");
    fprintf(fichier, "#define PAS 1\n\n");

    fprintf(fichier, "#endif");

    fclose(fichier);
    printf("Votre fichier param.h est généré.");
}
void coeur2(void)
{
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n");
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 0\n");
    fprintf(fichier, "#define INIT 0\n");
    fprintf(fichier, "#define PAS 2\n\n");

    fprintf(fichier, "#endif");

    fclose(fichier);
    printf("Votre fichier param.h est généré.");
}
void coeur3(void)
{
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n");
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 0\n");
    fprintf(fichier, "#define INIT 0\n");
    fprintf(fichier, "#define PAS 3\n\n");

    fprintf(fichier, "#endif");

    fclose(fichier);
    printf("Votre fichier param.h est généré.");
}
void coeur4(void)
{
    int pin = 0;
    printf("Choisissez la LED unique a allumer, de 1 a 10 : ");
    scanf("%d",&pin);
    while ((pin>10)||(pin<1))
    {
        printf("Choisissez la LED unique a allumer, de 1 a 10 : ");
        scanf("%d",&pin);
    }
    pin -= 1;
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n");
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 0\n");
    fprintf(fichier, "#define INIT %d\n",pin);
    fprintf(fichier, "#define PAS 0\n\n");

    fprintf(fichier, "#endif");

    fclose(fichier);
    printf("Votre fichier param.h est généré.");
}
void coeur5(void)
{
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n");
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 1\n");
    fprintf(fichier, "#define INIT 0\n");
    fprintf(fichier, "#define PAS 1\n\n");

    fprintf(fichier, "#endif\n");

    fclose(fichier);
    printf("Votre fichier param.h est généré.");
}
