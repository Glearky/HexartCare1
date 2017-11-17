#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SIZE 1000

//Structure coeur
typedef struct
    {
	float temps;
	float pouls;
	}coeur;

coeur cardiac[SIZE];
//j'initialise mes tableaux
double temps[SIZE];
double pouls[SIZE];
long *ndx_ptr=NULL;

