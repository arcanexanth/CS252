#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct freq{
	char value;
	int  freq;
}freq;


freq* freqTable();
void readFreq(freq* table);
void calcFreq(freq* table, char letter);
void sortTable(freq* table);
void printTable(freq* table);
void totalPrint(freq* table);
tnode* tnodeAdd(freq* table);
LinkedList* lladd(tnode* nodes);

int main (){
	
	// Check to make sure the input parameters are correct
	/*if(argc != 3){
		printf("Error: The correct format is \"hcompress -e filename\" or \"hcompress -d filename.huf\"\n"); fflush(stdout);
	exit(1);
	}*/
	
	freq* table = freqTable();
	//printTable(table);
	totalPrint(table);
	tnode* nodes = tnodeAdd(table);
	LinkedList* ll = lladd(nodes);
	//llDisplay(ll);
	printf("finished\n");


	// Create the frequency table by reading the generic file
	//tnode* leafNodes = createFreqTable("decind.txt");

	// Create the huffman tree from the frequency table
	//tnode* treeRoot = createHuffmanTree(leafNodes);

	//encode
	//if(strcmp(argv[1], "-e") == 0) {
		//Pass the leafNodes since it will process bottom up
	//	encodeFile(argv[2], leafNodes);
	//	} else { //decode
		//Pass the tree root since it will process top down
	//	decodeFile(argv[2], treeRoot);
	//	}
	//	return 0;
	//}
	//printTable(table);
	//totalPrint(table);
}

freq* freqTable(){
	freq* table = malloc(128* sizeof(char));
	int i;
	for(i = 0; i < 128; i++){
		table[i].value = i;
	}
	table[128].value = ' ';
	readFreq(table);
	sortTable(table);

	return table;
}

void readFreq(freq* table){
	char letter;
	char stop = scanf("%c", &letter);
	while(stop != EOF){
		calcFreq( table , letter);
		stop = scanf("%c", &letter);
	}

}

void calcFreq(freq* table, char letter){
	letter = tolower(letter);	
	int tableValue = 0;
	int charValue = letter;
	int i;
	for(i = 0; i < 128; i++){
		tableValue = table[i].value;
		
		if( tableValue == charValue){
			table[i].freq = table[i].freq + 1;
		}
	}
}
void sortTable(freq* table){
	int i;
	int j;
	for(i = 0; i < 128; i++){
		for(j = i+1; j < 128; j++){
			if (table[i].freq < table[j].freq){
			freq temp = table[i];
			table[i] = table[j];
			table[j] = temp;
			}
		}
	}
	
}

void printTable(freq* table){
	int i;
	for(i = 0; i < 128; i++){
		printf("Character: %c Frequency: %d\n", table[i].value, table[i].freq);
	}
}

void totalPrint(freq* table){
	int i;
	int total = 0;
	for(i =0; i < 128; i++){
		total = total + table[i].freq;
	}
	printf("Total Characters is: %d\n", total);
}

tnode* tnodeAdd(freq* table){
	tnode* nodes = malloc(1 * sizeof(tnode));
	int i;
	for(i = 0; i < 128; i++){
	   nodes[i].c = table[i].value;
	   nodes[i].weight = table[i].freq;
	   printf("added :%d Weight is: %d\n", nodes[i].c, nodes[i].weight);
	}
	return nodes;
}

LinkedList* lladd(tnode* nodes){
    int i;
    LinkedList* ll = llCreate();
    for(i = 0; i < 128; i++){
    	llAdd(&ll, nodes[i]);
    }
    return ll;
}

