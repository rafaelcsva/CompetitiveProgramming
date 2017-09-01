#include <bits/stdc++.h>

using namespace std;

#define MAXIMO	100000
vector<int>grafo[MAXIMO];

int cor[MAXIMO];

void dfs(int x){
	for(int i = 0 ; i < grafo[x].size(); i++){
		if(cor[grafo[x][i]] == 0){
			cor[grafo[x][i]] = 1;
			dfs(grafo[x][i]);
		}
	}
}

int main (){
	int n, m;
	
	int indices = 0;

	while(scanf("%d%d", &n, &m)&&n&&m){
		indices++;
		for(int i = 0 ; i < m ; i++){
			int a, b;
		
			scanf("%d%d", &a, &b);
		
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}

		for(int i = 0 ; i < n ; i++)
			cor[i] = 0;
		
		int qtd = 0;
	
		for(int i =0 ; i < n ; i++){
			if(cor[i] == 0){
				cor[i] = 1;
				dfs(i);	
				qtd++;
			}
		}
	
		printf("Case %d: %d\n", indices, qtd);
		
		for(int i = 0 ; i < n ; i++)
			grafo[i].clear();
	}
}
