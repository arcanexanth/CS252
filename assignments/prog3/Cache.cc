#include "Cache.h"
using namespace std;

Cache::Cache(int address, int cacheSize, int blockSize, int numBlocks){
   mAddressBits = address;
   mCacheSize = cacheSize;
   mBlockSize = blockSize;
   mNumBlocks = numBlocks;
   mNumSets = (mCacheSize /(mBlockSize * mNumBlocks));
   int i;
   for(i = 0; i < mNumSets; i++){
      mSets.push_back(new Set(mBlockSize, mNumBlocks));
   }

}

Cache::~Cache(){
   int i;
   for(i = 0; i < mNumSets; i++){
      delete mSets[i];
   }
}

int Cache::read(unsigned long address){
   //cout << "Inside Cache::read. Address is: " << address << endl;
   unsigned int index;
   int tag;
   mSetBits = log2(mNumSets);
   mBlockBits = log2(mBlockSize);
   mTagBits = mAddressBits - (mSetBits + mBlockBits);

   index = ((address << mTagBits) & ((unsigned int)pow(2, mAddressBits)-1))  >> (mTagBits + mBlockBits);
   //cout << "The set index for " << address << " is " << index <<"." << endl;
   tag = (address >> (mSetBits + mBlockBits));
  //cout << "The tag is: " << tag << endl;
   return mSets[index]->read(tag);

}

int Cache::write(unsigned long address){
   //cout << "Inside Cache::write." << endl;

   unsigned int index;
   int tag;
   mSetBits = log2(mNumSets);
   mBlockBits = log2(mBlockSize);
   mTagBits = mAddressBits - (mSetBits + mBlockBits);

   index = ((address << mTagBits) &((unsigned int)pow(2, mAddressBits)-1)) >> (mTagBits + mBlockBits);
   tag = (address >> (mSetBits + mBlockBits));
   //cout << "The set index for " << address << "is " << index <<"." << endl;
   
   return mSets[index]->write(tag);

}

void Cache::display(){
   int i;
   for(i = 0; i < mNumSets; i++){
      mSets[i]->display();
   }
}

int Cache::totalDirtyBlocks(){
   //cout << "Cache::totalDirtyBlocks" << endl;
   int total = 0;
   int i;
   for(i = 0; i < mNumSets; i++){
      total += mSets[i]->totalDirtyBlocks();
   }
   return total;
}
