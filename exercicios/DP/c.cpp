#include <bits/stdc++.h>

using namespace std;

#define MAXIMO	1000

int main (){
	int i = 0;
	int valores[MAXIMO];
	int tamanho[1000];
	int predecessor[1000];
	int indM=0;

	while(scanf("%d", &valores[i++])!=EOF){


		for(int j = i-1 ; j >= 0 ; j--){
			predecessor[j] = -1;
			tamanho[j] = 1;
			int aux = -1;
			for(int x = i-1; x > j ; x--){
				if(valores[j] < valores[x]){
					if(tamanho[x]+1 > tamanho[j]){
						tamanho[j] = tamanho[x]+1;
					}
					aux = x;
				}
			}
			if(aux!=-1){
				predecessor[j] = aux;
			}
			if(tamanho[j] > tamanho[indM])
				indM = j;
		}
	}
	printf("%d\n", tamanho[indM]);
	printf("-\n");

	for(int i = indM ; i != -1 ;i = predecessor[i]){
		printf("%d\n", i);
	}	

	return 0;
}
