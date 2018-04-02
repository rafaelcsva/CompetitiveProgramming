#include <bits/stdc++.h>

#define MAXIMO	510

using namespace std;

int idades[MAXIMO];
vector<int>graph[MAXIMO];
int d = 1;
int cor[MAXIMO];
vector<int>idx(MAXIMO);

int dfs(int x){
	cor[x] = d;
	int min_idade = 101;

	for(int i = 0 ; i < graph[x].size() ; i++){
		if(cor[graph[x][i]] != d){
			min_idade = min(min_idade, min(idades[graph[x][i]], dfs(graph[x][i])));			
		}
	}
	
	return min_idade;
}

int main (){
	int n, m, I;

	while(scanf("%d%d%d", &n, &m, &I)!=EOF){

		
		for(int i = 1 ; i <= n ; i++){
			idx[i] = i;
			scanf("%d", &idades[i]);
		}
		
		for(int i = 0 ; i < m ; i++){
			int a, b;
			
			scanf("%d%d", &a, &b);

			graph[b].push_back(a);
		}

		for(int i = 0 ; i < I ; i++){
			char op;	
			int a, b;

			scanf("\n%c", &op);
			scanf("%d", &a);

			if(op == 'T'){
				scanf("%d", &b);

				swap(idades[idx[a]], idades[idx[b]]);
				swap(idx[a], idx[b]);

			}else{
				
				if(graph[idx[a]].size() == 0){
					printf("*\n");
				}else{
					printf("%d\n", dfs(idx[a]));
				}

				d++;			
			}
		}
	}

	return 0;

}
