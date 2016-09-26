#include <stdio.h>
#include "list.h"

List* allocateList()
{
    return (List*) malloc(sizeof(List));
}

void freeList( List* list )
{
    if( list == NULL )
        return;

    freeList(list->tail);

    free(list);
}

void setHead( List* list, int value )
{
    list->head = value;
}

void setTail( List* list, List* tail )
{
    list->tail = tail;
}

List* createList( int head, List* tail )
{
    List* list = allocateList();
    setHead(list, head);
    setTail(list, tail);
    return list;
}

int listSize( List* list )
{
    int size = 0;
    while( list != NULL )
    {
        size++;
        list = list->tail;
    }
    return size;
}

void printList( List* list )
{
    // refactor en boucle
    while(list != NULL)
    {
        printf("%d ", list->head);
        list = list->tail;
    }
    printf("\r\n");
}
