////wooooo I do nothing right now;
//
//this has changed^ it does stuff now

#include "linkedlist.h"

stringll* stringCreate()
{
    return NULL;
}

LinkedList* llCreate(){
    return NULL;
}

void stringDisplay( stringll* ll )
{ 
    stringll* p = ll;
    printf( "[" );
    if( p != NULL ){
    while( p->next != NULL ){
        printf( "next string is: %s ", p->value );
        p = p->next;
    }
    printf( "last string is: %s ", p->value);
    
}

    printf( "]\n" );
}


char*  stringContains( stringll* ll, char c )
{
    char* contains = "";
    int lookingfor = c;
    stringll* p = ll;
    int compare;
     
    
 
     while( p != NULL )
    {
        compare = p->c;
        if( lookingfor == compare )
            return p->value;
        else
            p = p->next;
    }
   
        

    return contains;



}
void llDisplay( LinkedList * ll )
{
    LinkedList* p = ll;

    printf( "[" );

    if( p != NULL ) {


    while( p->next != NULL ){
    printf( "the character is:  %c, ", p->value.c );
    printf( "the weight is:  %d, \n", p->value.weight );
        p = p->next;
    }

    printf( "%c, ", p->value.c );
    printf( "%d, ", p->value.weight);
   }

   printf( "]\n");


}

void stringAdd( stringll** ll, char* val, char c)
{ 
    stringll* nn = (stringll*) malloc( sizeof( stringll ) );
    nn->value = val;
    nn-> next = NULL;
    nn->c = c;
    if( *ll != NULL ){
        stringll* p = *ll;
        while( p->next != NULL )
        {
           p = p->next;
        }
        p->next = nn;
    }
    else{
        *ll = nn;
    }
   
   
}



void lladd( LinkedList** ll, tnode val )
{
    LinkedList* nn = (LinkedList*)malloc( sizeof( LinkedList ) );
    nn->value = val;
    nn->next = NULL;
    LinkedList* prev;
    
    LinkedList* p = *ll;
     
    if( *ll == NULL || p->value.weight >= val.weight )
    {   
        nn->next = *ll; 
        *ll = nn;
    }else{
	 while( p->next != NULL && p->next->value.weight <= val.weight ){
            prev = p;
            p = p->next;
        }
        nn->next = p->next;
        p->next = nn;
       
       // prev->next = nn;

    }


}


stringll* stringRemove( stringll* head )
{
    if( head->next != NULL )
    {
       head = head->next;   
    }
    else{
        head = stringCreate();
    }
    return head;

}
LinkedList*  llRemove( LinkedList* head )
{

    if( head->next != NULL )
    {
        head = head->next;
    }
    else 
    {
        head = llCreate();   
    } 

    return head;
}
