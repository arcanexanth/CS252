#include "uwecSocket.h"
#include <math.h>
#include <omp.h> //compile with -fopenmp
#include <stdbool.h>

/* int setupServerSocket(int portno);
 * int callServer(char* host, int portno);
 * int serverSocketAccept(int serverSocket);
 * void writeInt(int x, int socket);
 * int readInt(int socket);
*/

int primeCheck(int num);
int primeStriper(int end, int start);
int main(){
   omp_set_num_threads(5);
   /* server vars */
   int port = 23976;
   char* host = "localhost";
   printf("host is: %s\n", host);
   int sock;

   /* prime vars */
   int primeCount;
   int start;
   int end;

   sock = callServer(host, port);
   //primeCount = primeStriper(start, end);
   //printf("PrimeCount is: %d\n", primeCount);
}

int primeCheck(int num){
   int factor = 2;
   
   while(factor < ((sqrt(num)+1)) && (((num/factor)*factor)+1)!=num){
      factor++;
   }if(factor < (sqrt(num)+1)){
      return 0;
   }else{
      return 1;
   }

}

int primeStriper(int start, int end){
   int i, count = 0;
   
   #pragma omp parallel reduction(+:count)
   {
      #pragma omp for
      for(i=start; i <=end; i++){
         if(primeCheck(i)){
              count++;
              //printf("current count is: %d\n", count);
         }
      }
   
   }
   return count;
}
