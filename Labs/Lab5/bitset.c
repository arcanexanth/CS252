#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned short bitSet;

bitSet makeBitSet(); //Create new bitset
void displayBitSet(bitSet bs); //Displays the 16 bits of the bitset to the screen
void setBit(bitSet* bs, int index); //Sets bit 'index' of the bitset to 1
void clearBit(bitSet* bs, int index); //Sets bit 'index' of the bitset to 0
int bitValue(bitSet bs, int index); //Returns the value of the bit at 'index'

int main(){
   int bit;
   int index = 4;
   bitSet bs = makeBitSet();
   
   displayBitSet(bs);
   setBit(&bs, index);
   setBit(&bs, 5);
   displayBitSet(bs);
   clearBit(&bs, index);
   displayBitSet(bs);
   bit = bitValue(bs, 4);
   printf("The bit at index 4 is: %d\n", bit);
}

bitSet makeBitSet(){
    bitSet bs = 0;
    return bs;
}

void displayBitSet(bitSet bs){
    int i;
    for(i = 0; i < 16; i++){
	printf("%d ", (bs >> i) & 1);
    }
    printf("\n");
}

void setBit(bitSet* bs, int index){
    *bs |= 1 << index;
}

void clearBit(bitSet* bs, int index){
    *bs &= ~( 1<< index );
}

int bitValue(bitSet bs, int index){
   int bit = (bs >> index) & 1; 
   return bit;
}
