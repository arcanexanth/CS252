#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int binToDec(char* bin);
char* decToBin(int num);
int baseToDec(int base, char* cNum);
char* decToBase(int base, int num);

int main (){
char* bin = "11001";
int num = 11001;
char* cNum = "F8";
int base = 16;

int dec = binToDec(bin);
char* bi = decToBin(num);
int rDec = baseToDec(base, cNum);
char* cDec = decToBase(base, num);

}

int binToDec(char* bin){
	int x =0;

	for(int i = 0; i < strlen(bin); i++){
		int y =0;
		int e = 0;
		int b = bin[i]-'0';
		
		if(b>0&&b<2){
			y=(1 <<((strlen(bin)-1-i))*b);
		}else{
			y=0;
		}
		
		x+=y;		
	}
	printf("binToDec x is:%d\n",x);
	return x;

}
char* decToBin(int num){
	int rem = 0;
	int res = 0;
	int base = 2;
	int iter = 0;
	char* x = malloc(100 * sizeof(char));
		
	while(num > 0){
		res = num/base;
		rem = num % base;
		num = res;
		x[iter]= rem;
		iter++;
	}
	
	for(int i = iter-1; i >= 0; i--){
		printf("%d", x[i]);
	}
	printf("\n");
	return x;
}

int baseToDec(int base, char* cNum){
	int x =0;

	for(int i = 0; i < strlen(cNum); i++){
		long int y =0;
		int e = 0;
		int b = cNum[i]-'0';
		if(base == 16){
			y = strtol (cNum, NULL, base);
			x =  y; 	
		}else{		
			y = (pow(base, strlen(cNum)-1-i))* b;
		
		x+=y;		
		}
	}
	printf("baseToDec x is:%d\n",x);
	printf("\n");
	return x;


}

char* decToBase(int base, int num){
	int rem = 0;
	int res = 0;
	int iter = 0;
	char hex[6] = {'A','B','C','D','E','F'};
	char* x = malloc(50* sizeof(char));
		
	while(num > 0){

		res = num / base;
		rem = num % base;
		num = res;
		
	 	if(rem >9){
			x[iter] = hex[rem-10];
			//printf("x[%d] is: %c\n", iter, x[iter]);
		} else{
			x[iter] = rem + '0';
			//printf("x[%d] is: %d\n", iter, x[iter]);
		}

		iter++;		
	}
	for(int i = strlen(x)-1; i >= 0; i--){
	printf("decToBase is: %c\n", x[i]);
	}
	return x;

}
