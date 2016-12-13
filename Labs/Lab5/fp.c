#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef union fi{
   unsigned int i;
   float f;
}fi;

void displayFloat(float f);
float makeFloat(char* f);

int main(){
   fi fl;
    fl.f = makeFloat("-101.1101");
   printf("This is float the float: %f\n", fl.f);
   displayFloat(fl.f);
}

void displayFloat(float num){
   int i;
   fi fl;
   fl.f = num;
   for(i = 31; i >= 0; i--){
      printf("%d", (fl.i >> i) & 1);
      
      if(i == 31){
	printf(" ");
      }

      if(i == 23){
        printf(" ");
	
      }
   }
}

float makeFloat(char* f){
	int i =0;
	int place = 23;
	fi in;
	in.f = 0;
	in.i = 0;
	int res;
	int exponent;

    if(f[0] == '-'){
	in.i |= 1<< 31;
    }
    while(f[i] != '.'){
	i++;
    }if(f[i] == '.'){
	exponent = 127+ (i - 2);
	while(exponent > 0){
	   res = exponent/2;
		printf("exponent mod is:%d\n", exponent%2);
	   in.i |=  (exponent% 2) << place;
	 
	   exponent = res;
	   place++;
	}
    }
    i = strlen(f);
    place = 22;
    while(i > 0){
	 if( f[i] == '1'){
	   
	   in.i |= 1 << place;
	   place--;
	}else{
	  in.i &= ~(1 << place);
	  place--;
	}
	i--;
    }
	return in.f;
}
