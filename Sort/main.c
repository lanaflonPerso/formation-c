#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void swap( int* tableau, int a, int b );
void triNaif( int* tableau, int nb );
void triDichotomique( int* tableau, int start, int nb );
void printTableau( int* tableau, int nb );
int* creerTableau( int nb );
int checkTableau( int* tableau, int nb );
void assemblerTableaux( int* tableau, int leftStart, int leftNb, int rightStart, int rightNb );

int main()
{
    srand(0);

    for( int i=0; i<100; i++ )
    {
        int taille = 10 + i * 2000;

        int* tableau = creerTableau(taille);

        //printf("Tableau non trie : ");
        //printTableau(tableau, taille);

        triNaif(tableau, taille);
        //triDichotomique( tableau, 0, taille );

        //printf("Tableau     trie : ");
        //printTableau( tableau, taille );

        if( ! checkTableau( tableau, taille ) )
            printTableau( tableau, taille );

        free(tableau);
    }
    return 0;
}

int* creerTableau( int nb )
{
    int* tableau = (int*) malloc(nb*sizeof(int));

    for( int i=0; i<nb; i++ )
        tableau[i] = rand();

    return tableau;
}

void printTableau( int* tableau, int nb )
{
    for( int i=0; i<nb; i++ )
    {
        if( i > 0 )
            printf(", ");
        printf("%d", tableau[i]);
    }
    printf("\n");
}

int checkTableau( int* tableau, int nb )
{
    int result = 1;

    for( int i=1; i<nb; i++ )
    {
        if( tableau[i] < tableau[i-1])
        {
            printf("***********ERREUR index %d *************\n", i);
            result = 0;
        }
    }

    return result;
}

void triDichotomique( int* tableau, int start, int nb )
{
    // condition d'arrêt : le tableau est vide ou n'a qu'un seul élément
    if( nb <= 1 )
        return;

    // couper le tableau en deux
    int indexCesure = start + nb / 2;

    // trier chacun des deux tableaux
    int leftStart = start;
    int leftNb = indexCesure-start;

    int rightStart = indexCesure;
    int rightNb = nb-indexCesure+start;

    //printf("%d %d > %d %d | %d %d\n", start, nb, leftStart, leftNb, rightStart, rightNb );

    triDichotomique( tableau, leftStart, leftNb );
    triDichotomique( tableau, rightStart, rightNb );

    // assembler les deux tableaux
    assemblerTableaux( tableau, leftStart, leftNb, rightStart, rightNb );
}

void triNaif( int* tableau, int nb )
{
    // start l'index de début du parcours du tableau
    for( int start=0; start<nb; start++ )
    {
        // invariant : le tableau est trié entre 0 et start
        int minIndex = start;

        // chercher le minima
        for( int i=start+1; i<nb; i++ )
        {
            if( tableau[i] < tableau[minIndex] )
                minIndex = i;
        }

        // tableau[minIndex] est la valeur minimale dans le tableau entre start et nb
        if( minIndex != start )
            swap( tableau, start, minIndex );
    }
}

void swap( int* tableau, int a, int b )
{
    if( a == b )
        return;

    int tmp = tableau[a];

    tableau[a] = tableau[b];

    tableau[b] = tmp;
}


void assemblerTableaux( int* tableau, int leftStart, int leftNb, int rightStart, int rightNb )
{
    assert( leftStart + leftNb == rightStart );

    int a = leftStart;
    int b = rightStart;

    int* tmp = (int*) malloc(sizeof(int)*(leftNb+rightNb));
    int i = 0;

    while( i < leftNb + rightNb )
    {
        if( a >= leftStart + leftNb )
        {
            // il n'y a plus rien dans le tableau de gauche
            tmp[i] = tableau[b];
            b++;
        }
        else if( b >= rightStart + rightNb )
        {
            // il n'y a plus rien dans le tableau de droite
            tmp[i] = tableau[a];
            a++;
        }
        else
        {
            if( tableau[a] < tableau[b] )
            {
                tmp[i] = tableau[a];
                a++;
            }
            else
            {
                tmp[i] = tableau[b];
                b++;
            }
        }

        i++;
    }

    // recopier le tmp dans tableau
    // copie tmp dans tableau, à partir de leftStart
    for( int i=0; i<leftNb+rightNb; i++ )
        tableau[leftStart+i] = tmp[i];
    //memcpy( tableau + leftStart, tmp, sizeof(int) * (leftNb + rightNb));

    // on libère la mémoire allouée pour le tableau temporaire
    free( tmp );
}



















