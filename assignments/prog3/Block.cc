#include "Block.h"
#include <iostream>
using namespace std;

Block::Block(int bSize){
   blockSize = bSize;
   valid = 0;
   dirty = 0;
   tag = -1;
}

int Block::getValid(){
   return valid;
}

int Block::getDirty(){
   return dirty;
}

int Block::getHour(){
   return timestamp.hour;
}

int Block::getMin(){
   return timestamp.min;
}

int Block::getSec(){
   return timestamp.sec;
}

long int Block::getUSec(){
   return timestamp.usec;
}

unsigned int Block::getTag(){
   return tag;
}

void Block::makeDirty(int d){
   dirty = d;
}

void Block::makeValid(int v){
   valid = v;
}

void Block::setTag(unsigned int t){
   tag = t;
}

void Block::setTimeStamp(int h, int m, int s, long us){
   //cout << "setting time stamp." << endl;

   timestamp.hour = h;
   timestamp.min = m;
   timestamp.sec = s;
   timestamp.usec = us;
   
   //cout << "Finished setting time stamp." << endl;
}
