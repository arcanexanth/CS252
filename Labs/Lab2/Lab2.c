#include <stdlib.h>
#include <stdio.h>

typedef struct freq{
	int value;
	int freq;
} freq;

void readScores(int *ar, int* count);
void displayScores(int *ar, int count);
void calcHistogram(int *ar, freq* a, int count, int* calcCount);

int main (){

int ar[100];
int count = 0;
int calcCount = 0;
freq a[10];


readScores(ar, &count);
displayScores(ar, count);
calcHistogram(ar, a, count, &calcCount); 

}

void readScores(int *ar, int* i){
	int stop = 0;
	int iter = 0;
	while (stop != EOF){
		stop=scanf("%d", ar+iter);
				
		++iter;					
	}
	*i = iter-1;
}
		
void displayScores(int *ar, int count){
	printf("::Display Scores::\n");
	for(int i = 0; i < count; i++){
		printf("Score %d : %d\n", i+1,  *(ar+i));
	}
}
		
void calcHistogram(int *a, freq *f, int count, int* cCount){
	int aVal = 0;

	for(int i = 0; i < count; i++){
		aVal = *(a + i);
		int j = 0;
		while((j<*cCount) && ((*(f+j)).value != aVal)){
			j++;
		}
		if(j<*cCount){
			(*(f+j)).freq++;
		}else{	
			(*(f+j)).value = aVal;
			(*(f+j)).freq = 1;
			(*cCount)++;
		}
	}

	for(int b = 0; b<10; b++){
		printf("Value: %d Freq: %d\n", f[b].value, f[b].freq);
	}
}
