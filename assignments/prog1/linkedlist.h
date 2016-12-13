#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stringnode{
char c;
char* value;
struct stringnode* next;

} stringll;

typedef struct node{

int weight;
int c;

struct node* left;
struct node* right;
struct node* parent;

} tnode;


typedef struct llNode
{
    tnode value;
    struct llNode* next;
} LinkedList;

stringll* stringCreate();
void stringDisplay( stringll* ll );
stringll* stringRemove( stringll* head );
void stringAdd( stringll ** ll, char* value, char c );
LinkedList* llCreate();

void llDisplay( LinkedList* ll );

void lladd( LinkedList** ll, tnode );

LinkedList* llRemove( LinkedList* head );

char*  stringContains( stringll* ll, char c );
