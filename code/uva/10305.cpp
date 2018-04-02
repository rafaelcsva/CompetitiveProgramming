#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int cor[N];
vector<int>graph[N], ord;

void dfs(int x){
	cor[x] = 1;
	
	for(int i = 0 ; i < graph[x].size() ; i++){
		int v = graph[x][i];
		
		if(cor[v] == 0){
			dfs(v);
		}
	}
	
	ord.push_back(x);
}

int main (){
	int n, m;
	
	while(scanf("%d%d", &n, &m) != EOF){
		if(n == 0){
			break;
		}
		
		for(int i = 1; i <= n ; i++){
			cor[i] = 0;
		}
		
		while(m--){
			int u, v;
			
			scanf("%d%d", &u, &v);
			
			graph[u].push_back(v);
		}
		
		for(int i = 1 ; i <= n ; i++){
			if(cor[i] == 0){
				dfs(i);
			}
		}
		
		for(int i = n - 1 ; i >= 0 ; i--){
			char c = i == 0 ? '\n' : ' ';
			
			printf("%d%c", ord[i], c);
		}
		
		ord.clear();
		for(int i = 1 ; i <= n ; i++){
			graph[i].clear();
		}
	}
	
	return 0;
}
