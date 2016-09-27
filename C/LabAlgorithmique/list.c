#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*void freeList( List* list )
{
    if( list == NULL )
        return;

    freeList( list->tail );

    free( list );
}*/

void freeList( List* list )
{
    while( list != NULL )
    {
        List* tail = list->tail;

        free( list );

        list = tail;
    }
}

List* createList( int head, List* tail )
{
    List* list = allocateList();

    setHead( list, head );
    setTail( list, tail );

    return list;
}

void setHead( List* list, int value )
{
    list->head = value;
}

void setTail( List* list, List* tail )
{
    list->tail = tail;
}

List* allocateList()
{
    return (List*) malloc(sizeof(List));
}

void printList( List* list )
{
    while( list != NULL )
    {
        printf( "%d ", list->head );
        list = list->tail;
    }

    printf("\n");
}

int listSize(List* list)
{
    if( list == NULL )
        return 0;

    return 1 + listSize( list->tail );
}

/*int listSize(List* list)
{
    int result = 0;

    while( list != NULL )
    {
        result++;
        list = list->tail;
    }

    return result;
}*/
