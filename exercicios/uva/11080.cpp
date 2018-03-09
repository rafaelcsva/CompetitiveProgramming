#include <bits/stdc++.h>

using namespace std;

const int N = 210;
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
	int t;
	
	scanf("%d", &t);
	
	for(int i = 0; i < t ; i++){
		int n, m;
		
		scanf("%d %d", &n, &m);
		
		memset(cor, -1, sizeof cor);
		
		for(int j = 0 ; j < m ; j++){
			int u, v;
			
			scanf("%d %d", &u, &v);
			
			graph[u].push_back(v);
			graph[v].push_back(u);
		} 
		
		int mn = 0;
		bool ok = true;
		
		for(int j = 0 ; j < n ; j++){
			if(cor[j] == -1){
				if(dfs(j, 0)){
					int black = 0, white = 0;
					
					for(int k = 0 ; k < n ; k++){
						black += cor[k] == 1;
						white += cor[k] == 0;
						
						if(cor[k] != -1)
							cor[k] = 2;
					}
					
					if(white == 0){
						mn += black;
					}else if(black == 0){
						mn += white;
					}else{
						mn += min(black, white);
					}
				}else{
					ok = false;
					break;
				}
			}
		}
		
		if(ok){
			printf("%d\n", mn);
		}else{
			printf("-1\n");
		}
		
		for(int i = 0 ; i < n; i++){
			graph[i].clear();
		}
	}
	
	return 0;
}
