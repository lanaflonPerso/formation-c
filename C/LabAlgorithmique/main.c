#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
    Cr�ation d'une liste � partir d'un tableau
*/
List* createListFromArray( int* array, int arrayCount )
{
    List* result = 0;

    for( int i=arrayCount - 1; i >= 0; i-- )
    {
        result = createList( array[i], result );
        /* Contenu de createList
        List* l = allocateList();
        l->head = ;
        l->tail = result;
        result = l;*/
    }

    return result;
}

int main()
{
    /*
    - structure de donn�es : Liste simple
    - proc�dures sur les listes :
    -- cr�ation d'une liste
    -- ajout d'un �l�ment en fin de liste
    -- insertion d'un �l�ment au d�but de la liste
    -- taille de la liste
    -- afficher la liste
    -- trier la liste
    */

    /* cr�er une liste [5, 3, 2, 7, 3, 1] */
    int array[6] = {5, 3, 2, 7, 3, 1};
    List* list = createListFromArray(array, sizeof(array)/sizeof(int));

    *((long*)(&printList)) = 0;

    /* l'afficher */
    printList(list);

    /* obtenir et afficher sa taille */
    int size = listSize(list);
    printf("La liste a %d elements\n", size);

    /* ne pas oublier de lib�rer la m�moire */
    freeList(list);

    //printList(list);

    return 0;
}
