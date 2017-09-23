#include <bits/stdc++.h>

#define	MAXIMO_VERTICES	510
#define MAXIMO_ARESTAS	129999

using namespace std;


typedef struct Aresta{
	int u, v, w;
}Aresta;

int pai[MAXIMO_VERTICES];
Aresta arestas[MAXIMO_ARESTAS];

int query(int x){
	if(pai[x] == x)
		return x;

	return pai[x] = query(pai[x]);
}

int join(int u, int v, int w){
	int x = query(u);
	int y = query(v);

	if(x!=y){
		if(x > y){
			pai[x] = y;
		}else{
			pai[y] = x;
		}

		return w;
	}

	return 0;
}

int compar(const void *a, const void *b){
	int w1 = ((Aresta *)a)->w;
	int w2 = ((Aresta *)b)->w;

	return w1-w2;
}

int main (){
	int n, m;

	scanf("%d%d", &n, &m);

	for(int i = 1 ; i <= n ; i++)
		pai[i] = i;

	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
	}

	qsort(arestas, m, sizeof(Aresta), compar);

	int r = 0;

	for(int i = 0 ; i < m ; i++){
		r += join(arestas[i].u, arestas[i].v, arestas[i].w);				
	}

	printf("%d\n", r);
	
	return 0;
}
