#include <bits/stdc++.h>

using namespace std;

const int N = 210;
int cor[N];
vector<int>graph[N];

bool dfs(int x, int color){
	cor[x] = color;
	
	for(int i = 0 ; i < graph[x].size() ; i++){
		int v = graph[x][i];
		
		if(cor[v] == -1){
		
			if(!dfs(v, !color)){
				return false;
			}
			
		}else if(cor[v] == cor[x]){
			return false;
		}
	}
	
	return true;
}

int main (){
	int n, l;
	
	while(scanf("%d", &n) && n){
		scanf("%d", &l);
		
		memset(cor, -1, sizeof cor);
		
		for(int i = 0 ; i < l ; i++){
			int u, v;
			
			scanf("%d%d", &u, &v);
			
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		if(!dfs(0, 0)){
			printf("NOT ");
		}
		
		printf("BICOLORABLE.\n");
		
		for(int i = 0 ; i < n ; i++){
			graph[i].clear();
		}
	}
	
	return 0;
}
