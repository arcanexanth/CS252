#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode{
	int weight;
  	int c;
	struct tnode* left;
	struct tnode* right;
	struct tnode* parent;
} tnode;

typedef struct node{
	tnode value;
	struct node* next;
} LinkedList;

LinkedList* llCreate();
void llAdd(LinkedList** ll, tnode node);
void llDisplay(LinkedList* ll);

