#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool primeCheck(int num);
void primeFinder(int num, int range);
int main(){
  int num = 100;
  int range = 1;

  //primeCheck(num);
  clock_t start = clock(), diff;
  primeFinder(num, range);
  diff = clock() - start;
  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("Time taken %d seconds\n",msec/1000);
}

bool primeCheck(int num){
 
 int divisor = 2;
 float result;   
    
    while(divisor < num && (result = num%divisor) != 0){
	  divisor++;
    }if(result == 0){
	printf("%d is not prime.\n", num);
	return false;
    }else{
        printf("%d is prime.\n", num);
        return true;
    }
}	

void primeFinder(int num, int range){
  int i;
  int primeCount = 0;
  bool check = false;

   for(i=range; i <= num;){
      check = primeCheck(i);
      if(check == true){
         primeCount++;
	 i++;
      }else{
         i++;
      }
   }
   printf("Number of primes is: %d\n", primeCount);
}
