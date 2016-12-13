class Block {
   private:
      int blockSize;
      int valid;
      int dirty;
      unsigned int tag;
      struct timestamp{
         int hour;
         int min;
         int sec;
         long usec;
      };

      struct timestamp timestamp;

   public:
      Block( int bSize);
      int getValid();
      int getDirty();
      int getHour();
      int getMin();
      int getSec();
      long getUSec();
      unsigned int getTag();

      void makeDirty(int d);
      void makeValid(int v);
      void setTag(unsigned int t);
      void setTimeStamp(int h, int m, int s, long us);
};
