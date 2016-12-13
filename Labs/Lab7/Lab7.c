#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h> //compile with -fopenmp


/* Global Variables */
//int primeCount;
//int* primeArray;
int position;

/* Functions */
int primeCheck(int num);
int primeFinder(int end, int start);
int primeStriper(int end, int start);

int main(int argc, char** argv){
  //mallocing the array of primes
  //primeArray = malloc(80000 * sizeof(int));
  omp_set_num_threads(5);
  //printf("size of primeArray is %u\n", sizeof(primeArray));
  int primeCount;
  int start = atoi(argv[1]);
  int end = atoi(argv[2]);
  printf("start is: %d\n", start);
  printf("end is: %d\n", end);

  //primeFinder and clock start;
  clock_t startSecs = clock(), diff;
  primeCount = primeFinder(end, start);
  diff = clock() - startSecs;
  printf("PrimeCount is: %d\n", primeCount);
  int msec = diff * 1000 / CLOCKS_PER_SEC;

  //time in seconds
  printf("Time taken for blocking is %d seconds\n",msec/1000);
  
  primeCount = 0;
  position = 0;
  startSecs = clock();
  primeCount = primeStriper(end, start);
  diff = clock() - startSecs;
  printf("PrimeCount is: %d\n", primeCount);
  printf("Time taken for striping is %d seconds\n",msec/1000);
}

int primeCheck(int num){
 //primeArray = malloc(100 * sizeof(int));
 //position = 0;
 int factor = 2;  
    
    while(factor < ((sqrt(num)+1)) && (((num / factor) * factor) +1)  != num){
	  factor++;
    }if( factor < (sqrt(num) + 1)){
	//printf("%d is not prime.\n", num);
	return 0;
    }else{
        //primeArray[position] = num;
	//position+=1;
        //printf("%d is prime.\n", num);
        return 1;
    }
}	

int primeFinder(int num, int range){
   printf(".:Blocking:.\n");
   int i; 
   int count = 0; 
   int numPrimes = 0;
   float start = omp_get_wtime();
    #pragma omp parallel reduction(+:numPrimes)
    {
      float startTime = omp_get_wtime();
    #pragma omp for schedule(static, (num-range)/omp_get_num_threads()) nowait
      for(i=range; i <= num; i++){  	      
        //#pragma omp critical
	if(primeCheck(i)){
	   //#pragma omp atomic
	   numPrimes++;
           count++;
        }  
      }
      printf("Time for %d: %lf, i is %d\n", omp_get_thread_num(), (omp_get_wtime()-startTime), numPrimes);
    }
    printf("overall time: %lf with %d found\n", omp_get_wtime() - start, count);
  //return count;
}

int primeStriper(int num, int range){
   printf(".:Striping:.\n");
   int i, count = 0;
   //int tn = omp_get_thread_num();
   float start = omp_get_wtime();
   #pragma omp parallel reduction(+:count)
   {
     float startTime = omp_get_wtime();
     #pragma omp for schedule(static, 1)nowait
     for(i = range; i <= num; i++){
       //#pragma omp critcal
       if(primeCheck(i)){
        //#pragma omp atomic
          count++;
       }
     }
     printf("Time for %d: %lf, i is %d\n", omp_get_thread_num(), (omp_get_wtime()-startTime), count);
   }
   printf("overall time: %lf with %d found\n", omp_get_wtime() - start, count);
   //return count;
}

