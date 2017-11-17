#include "actions.h"
#include "donnees.c"

//=================================================//
//Je détail cette fonction, on retrouvera des fonctions définies par analogie dans le suite du programme
//Fonction qui affiche le contenu du fichier source
int affichage()
{
    LectureFichier();//Appel de la fonction qui lit le fichier source

    int j;

    for (j= 0; j<SIZE; j++)//bouvle pour parcourir les tableau
    {
        if(cardiac[j].temps!= 0 || cardiac[j].pouls!=0)//si les DEUX tableaux sont vide , on affiche rien
            {
                printf("\t %f %f \n",cardiac[j].temps, cardiac[j].pouls);//C'est ici qu'on affiche
            }
    }

    return 0;
}

//=================================================//
//Fonction qui tri un tableau en conservant la concordance avec un deuxieme tableau
//Cette fonction est un quicksort
#define  SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void  sortQd( double *v , long *ndx , long left , long right )
{
long i;
long last;
long ntmp;
double tmp;

if ( left >= right )  return;

SWAP(v[left],v[(left+right)/2],tmp);

SWAP(ndx[left],ndx[(left+right)/2],ntmp);

last = left;

for ( i = left+1 ; i <= right ; i++ )
    {
    if ( v[i] < v[left] )
       {
       ++last;
       SWAP(v[last],v[i],tmp);
       SWAP(ndx[last],ndx[i],ntmp);
       }
    }

SWAP(v[left],v[last],tmp);
SWAP(ndx[left],ndx[last],ntmp);
sortQd( v , ndx , left , last-1 );
sortQd( v , ndx , last+1 , right );

return;
}



//=================================================//
long  *sortQndxdvect( double *v , long left , long right )
{
long i;
long n;
long last;
long*ndx=NULL;
double tmp;

n   = right-left+1;
ndx = (long *)malloc(n*sizeof(long));
for ( i = 0 ; i < n ; i++ ) ndx[i] = i;

sortQd( v , ndx , left , right );

return ndx;
}



//=================================================//
//Fonction qui tri les donnees de temps en ordre croissant
int croissant_temps()
{
   LectureFichier();//Appel de la fonction qui lit le fichier source

   int m;

   ndx_ptr=sortQndxdvect( temps , 0 , SIZE-1 );

   for (m= 0; m<SIZE; m++)
    {
        if(temps[m]!= 0 || pouls[ndx_ptr[m]]!=0)
            {
                printf("\t%lf ms   ", temps[m]);
                printf("%lf bpm\n", pouls[ndx_ptr[m]]);
            }
    }

    free(ndx_ptr);//Libere la memoire

     return 0;
}



//=================================================//
//Fonction qui tri les valeurs du pouls en odre croissant et affiche le temps correspondant
int croissant_pouls()
{
   LectureFichier();//Appel de la fonction qui lit le fichier source

   int m;

   ndx_ptr=sortQndxdvect( pouls , 0 , SIZE-1 );

   for (m= 0; m<SIZE; m++)
    {
                if(pouls[m]!= 0 || temps[ndx_ptr[m]]!=0)
            {
                printf("\t%lf bpm   ", pouls[m]);
                printf("%lf ms\n", temps[ndx_ptr[m]]);
            }
    }

    free(ndx_ptr);//Libere la memoire

     return 0;

}



//=================================================//
//Fonction qui tri les valeurs du pouls en odre decroissant et affiche le temps correspondant
int decroissant_pouls()
{
   LectureFichier();//Appel de la fonction qui lit le fichier source

   int m;
   int l;
   int x = SIZE;
   double montab1[SIZE];
   double montab2[SIZE];

   ndx_ptr=sortQndxdvect( pouls , 0 , SIZE-1 );

   for (m= 0; m<SIZE; m++)
    {
        montab1[m]= pouls[m];
        montab2[m] = temps[ndx_ptr[m]];
    }

    for(l=x-1 ; l> -1; l--)
        {
            if(montab1[l]!= 0 || montab2[l]!=0)
                {
                    printf("\t%lf bpm   ", montab1[l]);
                    printf("%lf ms\n", montab2[l]);
                }
        }

    free(ndx_ptr);//Libere la memoire

     return 0;
}



//=================================================//
//Fonction qui tri les valeurs du temps en odre croissant et affiche le pouls correspondant
int decroissant_temps()
{
   LectureFichier();//Appel de la fonction qui lit le fichier source

   int m;
   int l;
   int x = SIZE;
   double montab1[SIZE];
   double montab2[SIZE];

   ndx_ptr=sortQndxdvect( temps , 0 , SIZE-1 );

   for (m= 0; m<SIZE; m++)
    {
        montab1[m]= temps[m];
        montab2[m] = pouls[ndx_ptr[m]];
    }


    for(l=x-1 ; l> -1; l--)
        {
            if(montab1[l]!= 0 || montab2[l]!=0)
                {
                    printf("\t%lf ms   ", montab1[l]);
                    printf("%lf bpm\n", montab2[l]);
                }
        }

    free(ndx_ptr);//Libere la memoire

     return 0;
}



//=================================================//
//Fonction qui affiche la valeur maximal du pouls et les temps correspondants
int max_pouls()
{
   LectureFichier();//Appel de la fonction qui lit le fichier source

   float x;
   int m;
   int n;
   float thetab1[SIZE];
   float thetab2[SIZE];
   int i = 0;

   ndx_ptr=sortQndxdvect( pouls , 0 , SIZE-1 );

   for (m= 0; m<SIZE; m++)
    {
            if(pouls[m]!= 0 || temps[ndx_ptr[m]]!=0)
            {
                thetab1[i] = pouls[m];
                thetab2[i] = temps[ndx_ptr[m]];
                i++;
            }
    }


    x = thetab1[i-1]; //on recupere la valeur maximum du pouls


    for (n= 0; n<SIZE; n++)
    {
        if(thetab1[n]== x)// si cette valeur est présente une deuxieme fois dans les données alors on l'affiche avec sont temps
            {
                printf("\t%lf bpm   ", thetab1[n]);
                printf("%lf ms\n", thetab2[n]);
            }
    }


    free(ndx_ptr);//Libere la memoire

     return 0;
}


//=================================================//
//Fonction qui affiche la valeur minimal du pouls et les temps correspondants
int min_pouls()
{

   LectureFichier();//Appel de la fonction qui lit le fichier source

   float x;
   int m;
   int n;
   float thetab1[SIZE];
   float thetab2[SIZE];
   int i = 0;

   ndx_ptr=sortQndxdvect( pouls , 0 , SIZE-1 );
   for (m= 0; m<SIZE; m++)
    {
            if(pouls[m]!= 0 || temps[ndx_ptr[m]]!=0)
            {
                thetab1[i] = pouls[m];
                thetab2[i] = temps[ndx_ptr[m]];
                i++;
            }
    }

    x = thetab1[0]; //on recupere la valeur minimum du pouls

    for (n= 0; n<SIZE; n++)
    {
        if(thetab1[n]== x)// si cette valeur est présente une deuxieme fois dans les données alors on l'affiche avec sont temps
            {
                printf("\t%lf bpm   ", thetab1[n]);
                printf("%lf ms\n", thetab2[n]);
            }
    }

    free(ndx_ptr);//Libere la memoire

     return 0;
}



//=================================================//
//Fonction qui compte le nombre de ligne que contient le fichier source
int nb_ligne()
{
    printf("\tLe nombre de ligne en memoire est: ");

    LectureFichierlongueur();//Appel de la fonction qui compte le nombre de ligne dans le fichier source

    return 0;
}



//=================================================//
//Fonction qui recherche la valeur du pouls pour un temps choisis par l'utilisateur
int recherche_tps()
{
    LectureFichier();//Appel de la fonction qui lit le fichier source

    int j;
    double entree = 0;


    printf("\t Entre une valeur de temps a rechercher : \n");
    scanf("%lf",&entree);


    for (j= 0; j<SIZE; j++)
    {
        if(cardiac[j].temps!= 0 || cardiac[j].pouls!=0)
            {
               if(cardiac[j].temps == entree)
                {
                    printf("\t%f ms  %f bpm \n",cardiac[j].temps, cardiac[j].pouls);
                }
            }
    }

    return 0;
}



//=================================================//
//Fonction qui calcul la moyenne des BMP sur une plage de temps donnees par l'utilisateur
int moyenne()
{
    LectureFichier(); //Appel de la fonction qui lit le fichier source

    int j;
    float debut = 0;
    float fin = 0;
    float somme = 0;
    float cpt = 0;


    printf("\t Entre le debut de la plage temps : ");
    scanf("%f",&debut);


    printf("\t Entre la fin de la plage temps : ");
    scanf("%f",&fin);


    for (j= 0; j<SIZE; j++)
    {
        if(cardiac[j].temps!= 0 || cardiac[j].pouls!=0)
            {
                if(cardiac[j].temps >=debut && cardiac[j].temps <= fin)// si la valeur du pouls est compris entre les valeur max et min entree par l'utilisateur
                {
                    somme = somme + cardiac[j].pouls;// on somme les valeurs du pouls
                    cpt ++;// on incrémente de 1
                }
            }
    }

    printf("\n\t La moyenne des BPM sur la plage de temps est : %f bpm \n",somme/cpt);// on affiche la division de la somme des pouls par la somme du nombre de pouls

    return 0;
}



//=================================================//
/*int again()
{
    int test = 0;
    printf("\n\n");
    while(test != 1)
        {
            printf("Appuis sur 1 pour retourner au menu : ");
            scanf("%d",&test);
        }
    printf("\n\n\n\n\n");
    main();
}*/
