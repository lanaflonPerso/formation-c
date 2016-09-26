
/*
    Structure de la liste
*/
struct List
{
    int head;
    struct List* tail;
};

typedef struct List List;
typedef List* PList;

List* allocateList();
void freeList( List* list );
void setHead( List* list, int value );
void setTail( List* list, List* tail );

List* createList( int head, List* tail );

void printList( List* list );
int listSize( List* list );
List* listSort( List* list );



//list* allocateList( int head, list* tail );
