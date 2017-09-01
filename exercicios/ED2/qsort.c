#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR	1000000

void swap(int v[], int a, int b){
	int aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

int partition(int v[], int p, int r){
	int idx = rand()%(r-p)+p;
	swap(v, idx, r);
	
	int pivo = v[r];
	
	int i = p-1;
	
	
	for(int j = p ; j < r ; j++){
		if(v[j] <= pivo){
			swap(v, j, ++i);
		}
	}
	swap(v, r, ++i);
	
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
		v[i] = i;
	
	qsortDuRafael(v, 0, TAMANHO_VETOR - 1);
	
	for(int i = 0 ; i < TAMANHO_VETOR  ; i++)
		printf("%d ", v[i]);
		
	printf("\n");
	
	return 0;	
}
