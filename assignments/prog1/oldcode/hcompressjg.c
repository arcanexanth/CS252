#include "linkedlistjg.h"

int loops = 128;

tnode* createHistogram();
void freqFinder( tnode* table, char x );
void readScores( tnode* table );
void printTable( tnode* table ); //for debugging more than anything
void sortTable( tnode* table );
LinkedList* populateList( tnode* table );
tnode* buildTree(LinkedList* head  );
void traverse( tnode* root, char*  code );
int main( int argc, char* argv[] )
{

tnode* table;

table = createHistogram();

readScores( table );
sortTable( table );
//printTable( table );

LinkedList* head;

head = populateList( table );
char code[ loops * 10];

//llDisplay( head );

table = buildTree( head );

//printf( "what is the table value %d\n ", table->weight );
//
//traverse( table, code );
}

void traverse( tnode* root, char*  code)
{   
        
    if( root->left != NULL )
    { 

        strcat( code, "0" );
        traverse( root->left , code); 
    }
    if( root->right != NULL )
    {   
        strcat( code, "1" );
        traverse( root->right, code );
    }

    if( root->left == NULL && root->right == NULL )
    {
         printf( "character is %c, code is %s\n", root->c, code );    
     //somehow return code value 10101010101010100101's 
    }

}

tnode* buildTree( LinkedList *head )
{ 
    tnode* end;
 
    while( head->next != NULL )
    {
      
       tnode temp;  
       temp.left = &head->value ;
       temp.right = &head->next->value;
       temp.weight = head->value.weight + head->next->value.weight;
     //  head->value.parent = &temp;
     //  head->next->value.parent = &temp;

      lladd( &head, temp );
      head = llRemove( head );
      head = llRemove( head );    
            
    }
  end = &head->value;
  return end; 
}

LinkedList* populateList( tnode* table )
{
    int i;
    LinkedList* temp = llCreate();
   
    for( i = 0; i < loops; i++ )
    {
        lladd( &temp, table[i] );         

    }

    return temp;

}

void sortTable( tnode * table )
{
    int i, j;
    tnode temp;
    for( i = 0; i < loops; i++ )
    {
        for( j = i + 1; j < loops; j++ )
        {
            if( table[i].weight < table[j].weight )
            {
            temp = table[i];
            table[i] = table[j];
            table[j] = temp;   
            }    
        }
    
    }


}

void printTable( tnode* table )
{
    int i; 

    for( i = 0; i < loops; i++ )
    {
        if( table[i].weight != 0  )
            printf( "%c is the character: %d is it's frequency\n", table[i].c, table[i].weight );

    }


}

void readScores( tnode* table )
{
    char arr;

    char input = scanf( "%c", &arr );

    while( input != EOF )
    {
        freqFinder( table, arr );
        input = scanf( "%c", &arr ); 
    }

}

void freqFinder( tnode * table, char x )
{
    int i;

    int tableValue = 0;
    int charValue = x;

    for( i = 0; i < loops; i++ )
    {
        tableValue = table[i].c;
        
        if( tableValue == charValue )
        {
            table[i].weight  = table[i].weight + 1;
        }
    }

}



tnode* createHistogram()
{
    tnode* table = (tnode*)malloc( loops * sizeof( tnode ) );

   int i;

   for( i = 0; i < loops; i++ )
   {
        table[i].c = i;
   }

   return table;

}
