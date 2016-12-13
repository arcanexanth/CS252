////wooooo I do nothing right now;
//
//

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
    char* contains = " not found";
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



    if( *ll != NULL )
    {
        LinkedList* p = *ll;
        while( p->next != NULL ){
        p = p->next;
        }
        
        p->next = nn;
    }else{
        *ll = nn;
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
/*
int main(){
    stringll* ll = stringCreate();
    
   stringAdd( &ll,"mit" , 'c' );
   stringAdd( &ll, "work", '4' );
   stringAdd( &ll, "ng", '3' );
   stringAdd( &ll, "alue is 01010101 ", 'a' );

   printf( "e is %s\n", ll->next->next->next->value );
   stringDisplay(ll);

    ll  =    stringRemove( ll );

   stringDisplay( ll );

   printf( "string contians 'a' %s\n", stringContains( ll, 'a' ) ); 
}
*/
