#include <bits/stdc++.h>

#define MAXIMO	100100

using namespace std;

vector<int>graph[MAXIMO];
int cor[MAXIMO];
int comprimento[MAXIMO];

bool dfs(int x, int *t){
	cor[x] = 1;
	int r = 0;
	int aux = -1;

	for(int i = 0 ; i < graph[x].size() ; i++){
		if(!cor[graph[x][i]]){
			
			r = 1;

			comprimento[graph[x][i]] = comprimento[x] + 1;

			if(!dfs(graph[x][i], &r)){
				return false;
			}
			
			if(aux == -1){
				aux = r;}
			else{
				if(aux!=r)
					return false;
			}
		}
	}
	
	(*t) += r;

	return true;
}

int main (){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		int a, b;

		scanf("%d%d", &a, &b);

		graph[b].push_back(a);
	}

	int t = 0;

	
	if(dfs(0, &t))
		printf("bem\n");
	else
		printf("mal\n");

	return 0;
}
