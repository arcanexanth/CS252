#include <vector>
#include "Set.h"
#include <cmath>
#include <iostream>

class Cache {
   private:
      
      //Incoming variables//
      int mAddressBits;
      int mCacheSize;
      int mBlockSize;
      int mNumBlocks;
      
      //Bit & Set variables//
      int mNumSets;
      int mSetBits;
      int mBlockBits;
      int mTagBits;

      //Vector of Set//
      std::vector<Set*> mSets;

   public:
      Cache(int address, int cacheSize, int blockSize, int numBlocks);
      ~Cache();
      int read(unsigned long address);
      int write(unsigned long address);
      void display();
      int totalDirtyBlocks();
};
