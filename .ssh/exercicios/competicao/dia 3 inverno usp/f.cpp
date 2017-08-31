#include <bits/stdc++.h>

#define INF 1000000
using namespace std;

typedef struct Aresta{
	int u, v;
	double w;
}Aresta;

int compar (const void* p1, const void* p2) {
	Aresta *a = (Aresta*)p1;
	Aresta *b = (Aresta*)p2;
	return (a->w > b->w);
}

int pai[10], peso[10], cor[10];
int pesoTotal;

int find(int a){
	if(pai[a] != a){
		return pai[a] = find(pai[a]);
	}

	return a;
}

int join(int a, int b){
	int x = find(a);
	int y = find(b);

	if(x!=y){		
		if(peso[x] < peso[y]){
			pai[x] = y;
		}
		else if(peso[x] > peso[y]){
			pai[y] = x;
		}
		else{
			pai[x] = y;
			peso[y]++;
		}
		
		return 1;
	}
	return 0;
}

double grafo[10][10];
vector<pair<int,int> >vertice;
double total;

void dfs(int x, int n){
	for(int i = 0 ; i < n ; i++){
		if(grafo[x][i] !=INF&&!cor[i]){
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", vertice[x].first, vertice[x].second, vertice[i].first, vertice[i].second, grafo[x][i]+16);
			
			total+=grafo[x][i]+16;
			cor[i] = 1;
			dfs(i, n);
		}
	}
}

int main (){
	int n;

	Aresta arestas[200];
	int indice = 0;

	while(scanf("%d", &n)&&n){
		indice++;
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				grafo[i][j] = INF;

		for(int i = 0 ; i < n ; i++){
			pai[i] = i;
			peso[i] = 0;
			cor[i] = 0;
		}

		for(int i = 0 ; i <  n ; i++){
			int a, b;

			scanf("%d%d", &a, &b);
			
			vertice.push_back(make_pair(a,b));			
		}
		
		int tam = 0;

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(j == i )
					continue;

				pair<int,int>ii = vertice[i];
				pair<int,int>iii = vertice[j];
	
				float dist = sqrt((ii.first-iii.first)*(ii.first-iii.first)+(ii.second-iii.second)*(ii.second-iii.second));//calculando as arestas
				arestas[tam].u = i;
				arestas[tam].v = j;
				arestas[tam].w = dist;
				tam++;
			}	
		}
		qsort(arestas, tam, sizeof(Aresta), compar);
	
		
		for(int i = 0 ; i < tam ; i++){
			if(join(arestas[i].u, arestas[i].v)){
				grafo[arestas[i].u][arestas[i].v] = grafo[arestas[i].v][arestas[i].u] = arestas[i].w;
			}
		}
		printf("Network #%d\n", indice);
		total = 0;

		vertice.clear();
		cor[0] = 1;
		dfs(0, n);
		
		printf("Number of feet of cable required is %.2f.\n", total);
		printf("**********************************************************\n");
	}
	return 0;
}
