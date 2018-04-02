#include <bits/stdc++.h>

#define TAM_GRAFO	210
#define N_CORES		40001

using namespace std;

int grafo[TAM_GRAFO][TAM_GRAFO];

int vx[] = {0, 1, 0, -1};
int vy[] = {1, 0, -1, 0};
int h, l;

void dfs(int i, int j, int *r, int cor){
	grafo[i][j] = -1;
	(*r)++;

	for(int x = 0 ; x < 4 ; x++){
		if(i+vx[x] >= 0 && i+vx[x] < h && j+vy[x] >= 0 && j+vy[x] < l){
			if(grafo[i+vx[x]][j+vy[x]] == cor){
				dfs(i+vx[x], j+vy[x], r, cor);
			}	
		}
	}	

}

int main (){
	scanf("%d%d", &h, &l);

	for(int i = 0 ; i < h ; i++)
		for(int j = 0 ; j < l ; j++){
			scanf("%d", &grafo[i][j]);
		}		

	
	int menor = N_CORES;

	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < l ; j++){
			if(grafo[i][j] != -1){
				int n = 0;

				dfs(i, j, &n, grafo[i][j]);

				menor = min(n, menor);
			}
		}
	}

	printf("%d\n", menor);

	return 0;
}
