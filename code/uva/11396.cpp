#include <bits/stdc++.h>

using namespace std;

const int N = 310;
vector<int>graph[N];
int cor[N];

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
	int n;
	
	while(scanf("%d", &n) && n){
		int u, v;
		
		memset(cor, -1, sizeof cor);
		
		while(scanf("%d%d", &u, &v) && u && v){
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		bool ok = true;		
		for(int i = 1 ; i <= n ; i++){
			if(cor[i] == -1){
			
				if(!dfs(i, 0)){
					ok = false;
				}
			}
		}
		
		printf("%s\n", !ok ? "NO" : "YES");
		
		for(int i = 1 ; i <= n ; i++){
			graph[i].clear();
		}
	}

	return 0;
}
