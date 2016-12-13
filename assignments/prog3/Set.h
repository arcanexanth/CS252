#include <vector>
#include "Block.h"
//#include <iostream>

class Set{

   private:
      int blockSize;
      int numBlocks;
      int getLastUsed();
     
      std::vector<Block*> blocks;
      int numDirtyBlocks;
   public:
      Set(int bSize, int nBlocks);
      ~Set();
      int read(unsigned int tag);
      int write(unsigned int tag);
      void display();
      int checkSet(unsigned int tag);
      int totalDirtyBlocks();
};
