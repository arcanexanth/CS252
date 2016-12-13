#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct freq{
	char * value;
	int freq;
} Histogram;

char ** readScores(int* count);
void displayScores(char **ar, int count);
int calcHistogram(char **ar, Histogram *h, int count);
void displayHistogram(Histogram *h, int calcCount);
void sortHistogram(Histogram *h, int calcCount);

int main (){

int count = 0;
char **ar; 
Histogram *h;
int calcCount  = 0;

ar = readScores(&count);
displayScores(ar, count);
calcCount = calcHistogram(ar, h, count);
displayHistogram(h, calcCount);
sortHistogram(h, calcCount);
//displayHistogram(h, calcCount);
free(ar);
free(h);
}

char ** readScores(int* i){
	int stop = 0;
	int iter = 0;
	char ** string = malloc(50 * sizeof(char*)); 
	for(int j = 0; j < 50; j++){
		string[j] =(char*) malloc(10*sizeof(char));
	}
	while (stop != EOF){
		stop = scanf("%s", string[iter]);
		//printf("%s\n", string+iter);
		++iter;	
	}
	*i = iter-1;	
	return string;	
}

void displayScores(char **ar, int count){
	
	for(int i = 0; i < count; i++){
		printf("Score %d: %s\n", i+1, ar[i]);
	}
	printf("\n");
}

int calcHistogram(char **ar, Histogram *h, int count){
	char * aVal;
	Histogram *hist = (Histogram*)malloc(100 * sizeof(Histogram));
	int  *cCount = malloc(sizeof(int));
	//printf("Count is: %d\n", count);
	
	
	for(int i = 0; i < count; i++){
		int j = 0;
		aVal = ar[i];
		
		printf("aVal is:%s\n", aVal);
		//printf("ar is:%s\n", ar+i);

		while((j<*cCount) && strcmp(hist[j].value, aVal)!=0){
			//hist[j].value == aVal;
			//printf("hist.vaule is: %s\n", hist[j].value);
			j++;
		}
		if(j<*cCount){
			hist[j].freq++;
		}else{
			hist[j].value = aVal;
			hist[j].freq = 1;
			(*cCount)++;
			
		}
		
		h[j] = hist[j];
	}
		
	return *cCount;

}

void displayHistogram(Histogram *f, int cCount){
	printf("::Histogram::\n");	
	for(int b = 0; b < cCount; b++){
		printf("Value: %sFreq: %d\n", f[b].value, f[b].freq);
	}
	printf("\n");
}

void sortHistogram(Histogram *f, int cCount){

	for(int i =0; i < cCount; i++){
		for(int j = i+1; j <cCount; j++){
			if (f[i].freq < f[j].freq){
				Histogram temp = f[i];
				f[i] = f[j];
				f[j] = temp;
			}		
		}

	}	
}
