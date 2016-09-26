#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define NULL 0

/**
    Création d'une liste à partir d'un tableau
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
    - structure de données : Liste simple
    - procédures sur les listes :
    -- création d'une liste
    -- ajout d'un élément en fin de liste
    -- insertion d'un élément au début de la liste
    -- taille de la liste
    -- afficher la liste
    -- trier la liste
    */

    /* créer une liste [5, 3, 2, 7, 3, 1] */
    int array[6] = {5, 3, 2, 7, 3, 1};
    List* list = createListFromArray(array, sizeof(array)/sizeof(int));

    /* l'afficher */
    printList(list);

    /* obtenir et afficher sa taille */
    int size = listSize(list);
    printf("La liste a %d elements\r\n", size);

    /* trier la liste */

    /* afficher la liste triée */

    /* ne pas oublier de libérer la mémoire */
    freeList(list);

    //printList(list);

    return 0;
}
