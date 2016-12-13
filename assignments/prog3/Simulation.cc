/*
 *CS252 Program 3
 *Authors: George Hamling & Gayatri Akula
 *Date: 05/11/16
*/
#include "Cache.h"
#include <iostream>

using namespace std;

int main(){
   
   //**** TEST 1 ****//
   cout << ".:Test 1:." << endl;
   int totalTime = 0;
   Cache* cache = new Cache(4, 8, 2, 1);
   
   for(int i = 0; i < 16; i ++){
      //cout << "I is: " << i << endl;
      totalTime += cache->read(i);
      //cout << " " << endl;
   }
   
   totalTime += cache->totalDirtyBlocks();

   //cache->display();
   cout << "Total time is: " << totalTime <<endl;
   //cout << endl;
   
   //**** TEST 2 ****//
   cout << ".:Test 2:." << endl;
   totalTime = 0;

   totalTime += cache->read(0);
   totalTime += cache->read(8);
   totalTime += cache->read(1);
   totalTime += cache->read(9);
   totalTime += cache->totalDirtyBlocks();
   
   //cache->display();
   cout << "Total time is: " << totalTime << endl;
   //cout << endl;
   delete cache;
   
   //**** TEST 3 ****//
   cout << ".:Test 3:." << endl;
   cache = new Cache(4, 8, 2, 2);
   totalTime = 0;

   for(int i = 0; i < 16; i ++){
      totalTime += cache->read(i);
      //cout << " " << endl;
   }
   totalTime += cache->totalDirtyBlocks();

   //cache->display();
   cout << "Total time is: " << totalTime <<endl;
   //cout << endl;
   
   
   //**** TEST 4 ****//
   cout << ".:Test 4:." << endl;
   totalTime = 0;

   totalTime += cache->read(0);
   totalTime += cache->read(8);
   totalTime += cache->read(1);
   totalTime += cache->read(9);
   totalTime += cache->totalDirtyBlocks();
   
   //cache->display();
   cout << "total Time is: " << totalTime << endl;
   cout << endl;
   delete cache;
   
   //**** TEST 5 ****//
   cout << ".:Test 5:." << endl;
   totalTime = 0;
   cache = new Cache(4, 8, 2, 2);

   totalTime += cache->read(0);
   totalTime += cache->read(4);
   totalTime += cache->read(8);
   totalTime += cache->read(0);
   totalTime += cache->totalDirtyBlocks();
   
   //cache->display();
   cout << "total Time is: " << totalTime << endl;
   //cout << endl;
   delete cache;

   //**** TEST 6 ****//
   cout << ".:Test 6:." << endl;
   totalTime = 0;
   cache = new Cache(4, 8, 2, 2);

   totalTime += cache->read(0);
   totalTime += cache->write(0);
   totalTime += cache->read(4);
   totalTime += cache->read(8);
   totalTime += cache->totalDirtyBlocks();
   
   //cache->display();
   cout << "total Time is: " << totalTime << endl;
   //cout << endl;
   delete cache;

   //**** TEST 7 ****//
   cout <<".:Test 7:." << endl;
   totalTime = 0;
   cache = new Cache(16, 256, 16, 4);
   
   for(int i = 0; i < 8192; i++){
      totalTime += cache->read(i);
      totalTime += cache->write(i);
   }
   totalTime += cache->totalDirtyBlocks();
   
   //cache->display();
   cout << "Total time is: " << totalTime << endl;
   //cout << endl;
   delete cache;

   //**** TEST 8 ****//
   cout <<".:Test 8:." << endl;
   totalTime = 0;
   cache = new Cache(16, 256, 16, 4);
   for(int i = 0; i < 8192; i = i+16){
      totalTime += cache->read(i);
      totalTime += cache->write(i);
   }
   totalTime += cache->totalDirtyBlocks();
   
   //cache->display();
   cout << "Total time is: " << totalTime << endl;
   delete cache;
}

