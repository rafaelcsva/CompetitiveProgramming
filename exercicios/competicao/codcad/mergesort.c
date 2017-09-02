#include <stdio.h>

#define TAMANHO_VETOR	100010

void MergeSort(int v[], int n){
	if(n <= 1){
		return;
	}
	else{
		int vl[n/2+1], vr[n/2+1];
	
		for(int i = 0 ; i < n/2 ; i++)
			vl[i] = v[i];

		for(int i = n/2 ; i < n ; i++)
			vr[i-n/2] = v[i];
	
		int taml = n/2;	
		int tamr = n-n/2;

		MergeSort(vl, taml);
		MergeSort(vr, tamr);

		int idxl = 0, idxr = 0;

		for(int i = 0 ; i < n ; i++){
			if(idxl < taml&&(vl[idxl] > vr[idxr]||idxr >= tamr)){
				v[i] = vl[idxl];
				idxl++;
			}else{
				v[i] = vr[idxr];
				idxr++;
			}
		}
	}
}

int main (){
	int n;
	int v[TAMANHO_VETOR];

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++)
		scanf("%d", &v[i]);

	MergeSort(v, n);

	for(int i = 0 ; i < n ; i++){
		printf("%d", v[i]);
		if(i!=n-1)
			printf(" ");
	}

	printf("\n");

	return 0;
}

	
