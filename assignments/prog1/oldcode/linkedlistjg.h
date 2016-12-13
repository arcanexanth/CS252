#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

LinkedList* llCreate();

void llDisplay( LinkedList* ll );

void llAdd( LinkedList** ll, tnode );

LinkedList* llRemove( LinkedList* head );
