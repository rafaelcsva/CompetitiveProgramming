#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR	1000000

int partition(int v[], int p, int r){
	int pivo = v[r];
	int i = p-1;
	int aux;
	
	for(int j = p ; j < r ; j++){
		if(v[j] <= pivo){
			aux = v[j];
			v[j] = v[++i];
			v[i] = aux;
		}
	}
	aux = v[++i];
	v[i] = v[r];
	v[r] = aux;
	
	return i;
}

void qsortDuRafael(int v[], int p, int r){
	if(p < r){
		int q = partition(v, p, r);
		
		qsortDuRafael(v, p, q-1);
		qsortDuRafael(v, q+1, r);
	}
}

 
int main (){
	int tam = TAMANHO_VETOR;
	int v[TAMANHO_VETOR];
	srand(time(NULL));
	
	for(int i = 0 ; i < TAMANHO_VETOR ; i++)
		v[i] = rand()%10000;
	
	qsortDuRafael(v, 0, TAMANHO_VETOR - 1);
	
	for(int i = 0 ; i < TAMANHO_VETOR  ; i++)
		printf("%d ", v[i]);
		
	printf("\n");
	
	return 0;	
}
