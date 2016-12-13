#include <stdlib.h>
#include <stdio.h>

typedef struct freq{
	int value;
	int freq;
} freq;

void readScores(int *ar, int* count);
void displayScores(int *ar, int count);
void calcHistogram(int *ar, freq* a, int count, int* calcCount);
void displayHistogram(freq* a, int calcCount);
void sortHistogram(freq* a, int calcCount);

int main (){

int ar[100];
int count = 0;
int calcCount = 0;
freq a[10];


readScores(ar, &count);
displayScores(ar, count);
calcHistogram(ar, a, count, &calcCount);
displayHistogram(a, calcCount);
sortHistogram(a, calcCount);
displayHistogram(a, calcCount);
}

void readScores(int *ar, int* i){
	int stop = 0;
	int iter = 0;
	while (stop != EOF){
		stop=scanf("%d", ar+iter);
		//printf("%d\n", ar[iter]);
		
		++iter;
		
	}
	//*ar=stop;
	*i = iter-1;
	//printf("%d",i);
}

void displayScores(int *ar, int count){
	printf("::Display Scores::\n");
	for(int i = 0; i < count; i++){
		printf("Score %d : %d\n", i+1,  *(ar+i));		
	}
	printf("\n");
}

void calcHistogram(int *a, freq *f, int count, int* cCount){
	int aVal = 0;
	
	//printf("Count is: %d\n", count);
	
	
	for(int i = 0; i < count; i++){
		int j = 0;
		aVal = *(a + i);
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
	

}

void displayHistogram(freq *f, int cCount){
	printf("::Histogram::\n");	
	for(int b = 0; b < cCount; b++){
		printf("Value: %d Freq: %d\n", f[b].value, f[b].freq);
	}
	printf("\n");
}

void sortHistogram(freq *f, int cCount){

	for(int i = 0; i < cCount; i++){
		
		for(int j = i+1; j < cCount; j++){
			if (f[i].freq < f[j].freq){
				freq temp = f[i];
				f[i] = f[j];
				f[j] = temp;
			}  
		}
	}
}
