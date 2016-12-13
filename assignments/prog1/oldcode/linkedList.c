#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedList.h"

void llDisplay(LinkedList* ll);
void llAdd(LinkedList** ll , tnode node);

LinkedList* llCreate() {
  return NULL;
}

void llDisplay(LinkedList* ll){
   LinkedList* p = ll;

   printf("[");

   if(p != NULL) {

      while(p->next != NULL){

        printf("Character is:%c, ", p->value.c);
	printf("weight is: %d,\n", p->value.weight);

        p = p->next;

      }

      //printf("Character is:%c ", p->value.c);
      //printf("weight is:%d\n", p->value.weight); 


   }

   printf("]\n");
}

void llAdd(LinkedList** ll, tnode node){
   LinkedList* nn = (LinkedList*)malloc( sizeof(LinkedList));
   nn->value = node;
   nn->next = NULL;

   if(*ll != NULL) {
      LinkedList* p = *ll;
      while(p->next != NULL){
      p = p->next;
      }

      p->next = nn;
   } else {
      *ll = nn;
     // llDisplay(ll);
   }


}
