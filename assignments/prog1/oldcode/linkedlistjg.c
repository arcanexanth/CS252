////wooooo I do nothing right now;
//
//

#include "linkedlistjg.h"

LinkedList* llCreate(){
    return NULL;
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



void lladd( LinkedList** ll, tnode val )
{
    LinkedList* nn = (LinkedList*)malloc( sizeof( LinkedList ) );
    nn->value = val;
    nn->next = NULL;
    printf("tnode is val: %d\n", val.weight);
    
    if( *ll != NULL ){
        LinkedList* p = *ll;
        while( p->next != NULL ){
        p = p->next;
        }
        
        p->next = nn;
    }else{
        *ll = nn;
    }


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
    LinkedList* ll = llCreate();
    
    tnode temp;
    tnode batman; 
    tnode end;
    batman.c = 'b';
    batman.weight= 200;
    temp.c = 'a'; 
    
    temp.weight = 22;   
    lladd(&ll, temp);
    end.c = 'z';
    end.weight = 666;
    lladd( &ll, batman);
    lladd( &ll, end );
    llDisplay(ll);

    ll  =    llRemove( ll );

    llDisplay( ll );
}
*/

