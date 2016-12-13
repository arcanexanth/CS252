#include <iostream>
#include "Set.h"
#include <sys/time.h>

using namespace std;

//constructor//
Set::Set(int bSize, int nBlocks){
   blockSize = bSize;
   numBlocks = nBlocks;

   int i;
   for(i = 0; i < numBlocks; i++){
      blocks.push_back(new Block(blockSize));
   }
}

//Destructor//
Set::~Set(){
   int i;
   for(i = 0; i < numBlocks; i++){
      delete blocks[i];
   }
}

//read//
int Set::read(unsigned int tag){
   //cout << "Inside of Set::read." << endl;
   
   int rVal;
   int i;
   struct timeval tv;
   struct timezone tz;
   struct tm *tm;
   
   //check if found//
   if((i =checkSet(tag)) != -1){
      //cout << "Value is in block." <<  endl;
      //Was hit//
      rVal = 0;

      gettimeofday(&tv, &tz);
      tm = localtime(&tv.tv_sec);
      int hour = tm->tm_hour;
      int min = tm->tm_min;
      int sec = tm->tm_sec;
      long usec = tv.tv_usec;
      //cout << "Setting time stamp." << endl;
      //set time stamp//
      blocks[i]->setTimeStamp(hour, min, sec, usec);
      
   }else{
      //cout << "Value Isn't in block." << endl;
      //cout << "Checking for empty blocks" << endl;
      rVal = 1;

      i=0;
      while((i < numBlocks) && (blocks[i]->getValid()==1)){
         i++;
      }

      if (i == numBlocks){
         i = getLastUsed();
         if (blocks[i]->getDirty() == 1){
            rVal = 2;
         }
      }

      blocks[i]->setTag(tag);
      blocks[i]->makeValid(1);
      blocks[i]->makeDirty(0);

      gettimeofday(&tv, &tz);
      tm = localtime(&tv.tv_sec);
      int hour = tm->tm_hour;
      int min = tm->tm_min;
      int sec = tm->tm_sec;
      long usec = tv.tv_usec;

      //set time stamp//
      blocks[i]->setTimeStamp(hour, min, sec, usec);
   }
   return rVal;
}

//check//
int Set::checkSet(unsigned int tag){
   int i;
   for(i = 0; i < numBlocks; i++){
      if((blocks[i]->getTag() == tag) && (blocks[i]->getValid() == 1)){
         return i;
      }
   }
   return -1;
}

int Set::write(unsigned int tag){
   //cout << "Inside of Set::write." << endl;
   //cout << "Tag is: " << tag << endl;
   int rVal;
   int i;
   struct timeval tv;
   struct timezone tz;
   struct tm *tm;
   
   //check if found//
   if((i =checkSet(tag)) != -1){
      //cout << "Tag found"<< endl;
      //Was hit//
      rVal = 0;

      gettimeofday(&tv, &tz);
      tm = localtime(&tv.tv_sec);
      int hour = tm->tm_hour;
      int min = tm->tm_min;
      int sec = tm->tm_sec;
      long usec = tv.tv_usec;

      //make dirty & set time stamp//
            //cout << "Setting time Stamp" << endl;
      blocks[i]->setTimeStamp(hour, min, sec, usec);
      blocks[i]->makeDirty(1);

   }else{
      //cout << "Tag not found" << endl;
      rVal = 1;

      i=0;
      while((i < numBlocks) && (blocks[i]->getValid()==1)){
         i++;
      }

      if (i == numBlocks){
         i = getLastUsed();
         if (blocks[i]->getDirty() == 1){
            rVal = 2;
         }
      }

      blocks[i]->setTag(tag);
      blocks[i]->makeValid(1);
      blocks[i]->makeDirty(1);

      gettimeofday(&tv, &tz);
      tm = localtime(&tv.tv_sec);
      int hour = tm->tm_hour;
      int min = tm->tm_min;
      int sec = tm->tm_sec;
      long usec = tv.tv_usec;

      //set time stamp//
      blocks[i]->setTimeStamp(hour, min, sec, usec);
   }
   return rVal;
}
int Set::getLastUsed(){
   int lui = 0;
   int luBHour = blocks[lui]->getHour();
   int luBMin = blocks[lui]->getMin();
   int luBSec = blocks[lui]->getSec();
   int luBUSec = blocks[lui]->getUSec();
   
   int current = 1;
   while(current < numBlocks){
      
      int currBHour = blocks[current]->getHour();
      int currBMin = blocks[current]->getMin();
      int currBSec = blocks[current]->getSec();
      int currBUSec = blocks[current]->getUSec();
      
      if(currBHour < luBHour){
         lui = current;
         int luBHour = blocks[lui]->getHour();
         int luBMin = blocks[lui]->getMin();
         int luBSec = blocks[lui]->getSec();
         int prevBUSec = blocks[lui]->getUSec();
      }else if(currBHour == luBHour){
         if(currBMin < luBMin){
            lui = current;
            int luBHour = blocks[lui]->getHour();
            int luBMin = blocks[lui]->getMin();
            int luBSec = blocks[lui]->getSec();
            int prevBUSec = blocks[lui]->getUSec();
         }else if(currBMin == luBMin){
            if(currBSec < luBSec){
               lui = current;
               int luBHour = blocks[lui]->getHour();
               int luBMin = blocks[lui]->getMin();
               int luBSec = blocks[lui]->getSec();
               int prevBUSec = blocks[lui]->getUSec();              
            }else if(currBSec == luBSec){
               if(currBUSec < luBUSec){
                  lui = current;
                  int luBHour = blocks[lui]->getHour();
                  int luBMin = blocks[lui]->getMin();
                  int luBSec = blocks[lui]->getSec();
                  int prevBUSec = blocks[lui]->getUSec();                 
               }
            }
         }
      }
      current = current+1;
   }
   return lui;
}
//display//
void Set::display(){
   //cout << "Inside of Set::display." << endl;
   int i;
   int hour;
   int min;
   int sec;
   long usec;

   cout << ".:Set Information:." << endl;
   for(i= 0; i < numBlocks; i++){
      if(blocks[i]->getValid() ==1){
         cout << " Valid| ";
      }else{
         cout << " Invalid| ";
      }
      
      if(blocks[i]->getDirty()==1){
         cout << " Dirty| ";
      }else{
         cout << " Not Dirty| ";
      }

      if(long(blocks[i]->getTag()) != -1){
         cout << "Tag is " << blocks[i]->getTag() << endl;
      }else{
         cout << "No Tag" << endl;
      }

      hour = blocks[i]->getHour();
      min = blocks[i]->getMin();
      sec = blocks[i]->getSec();
      usec = blocks[i]->getUSec();
      
      cout << "Last Accessed at h: " << hour << " m: " << min << " s: " << sec<< " us: " << usec << endl;
      cout << " " << endl;
   }
}

int Set::totalDirtyBlocks(){
   int totalDirty = 0;
   int i;
   for(i =0; i < numBlocks; i++){
      if(blocks[i]->getDirty() == 1){
         totalDirty = totalDirty+1;
      }
   }
   return totalDirty;
}
