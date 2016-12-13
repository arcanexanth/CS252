/*** Hcmpress.c program by Jeisah Hubing and George Hamlin
 *
 */

#include "linkedlist.h"

int loops = 128;//just used to say it's looking for 128 characters ( all of the ascii characters )

tnode* createHistogram(); //finds the frequencies of the numbers
void freqFinder( tnode* table, char x );//adds frequences
void readScores( tnode* table, FILE* in);//inputs the decind.txt file and finds the frequncies
void printTable( tnode* table ); //for debugging more than anything
void sortTable( tnode* table );//sorts the nodes into ascending order
LinkedList* populateList( tnode* table );//creates a linked list of the nodes in order
tnode* buildTree(LinkedList* head  );//builds the tree
void traverse( tnode* root, char*  code, stringll** codeOutput );//traverses the tree assigning  0 or 1 every time it goes left or right in the tree, creates a table of codes
void encode( stringll* codes, FILE* in, FILE* out);// uses the code table to encode the inputed file "decind.txt"
void decode( FILE* in, tnode* table, stringll* codeOutput, FILE* out);//uses the tree made from "decind.txt" to decode the texte ( didn't get to it );

int main( int argc, char* argv[] )
{
	if(argc != 3){
		printf("Error: The correct format is \"hcompress -e filename\" or \"hcompress -d filename.huf\"\n"); fflush(stdout);	 
        exit(1);}
	FILE* in = fopen(argv[2], "r");
	FILE* out = fopen("decind.huf", "w");
	
	tnode* table;
	table = createHistogram();
	readScores(table, in);
	sortTable( table );
	LinkedList* head;
	head = populateList( table );
	char code[ loops * 5];
	table = buildTree( head );
	stringll* codeOutput = stringCreate();
	traverse( table, code, &codeOutput );
	//encode
	if(strcmp(argv[1], "-e") == 0){
		encode(codeOutput, in, out);
	}else{ //decode
		decode(in, table, codeOutput, out);
	}
	fclose(in);
	fclose(out);
return 0;
}




//goes through the table and gerneates the 0's and 1's code
void traverse( tnode* root, char*  code, stringll** codeOutput)
{   
        
    if( root->left != NULL )
    { 
        strcat( code, "0" );
        traverse( root->left , code, codeOutput); 
    }
    if( root->right != NULL )
    {
        strcat( code, "1" );
        traverse( root->right, code, codeOutput );
    }

    if( root->left == NULL && root->right == NULL )
    {
          stringAdd( codeOutput, code, root->c );
    }

}

tnode* buildTree( LinkedList *head )
{ 
    tnode* end;
    while( head->next != NULL )
    {
          tnode temp;  
          temp.right = &head->value ;
          temp.left = &head->next->value;
          temp.weight = head->value.weight + head->next->value.weight;
        
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
            if( table[i].weight >  table[j].weight )
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

void encode(stringll* codes, FILE* in, FILE* out )
{
     
    char arr;
    char input = fgetc( in );
    
    while( input != EOF )
    {
     fputs( stringContains( codes, arr ), out );
     arr =  input = fgetc( in );
    }
    printf("got to end of encode");
}


void readScores( tnode* table, FILE* in)
{
    char arr;
    in = fopen( "decind.txt", "r" );

    char input = fgetc(in);
    arr = input;
    while( input != EOF )
    {   
             
        freqFinder( table, arr );
     arr = input = fgetc( in  ); 
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

void decode(FILE* in, tnode* table, stringll* codeOutput, FILE* out){
	
}
