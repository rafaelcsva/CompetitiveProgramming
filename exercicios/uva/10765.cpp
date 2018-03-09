#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int art[N], dfs_num[N], dfs_low[N], ind[N];
vector<int>graph[N];
int cnt = 0, son = 0, root;

void dfs(int x, int f){
	dfs_num[x] = dfs_low[x] = cnt++;
	
	for(int i = 0 ; i < graph[x].size() ; i++){
		int v = graph[x][i];
		
		if(dfs_num[v] == -1){
			dfs(v, x);
			
			if(x == root){
				son++;
			}		
			
			if(dfs_low[v] >= dfs_num[x]){
				art[x]++;
			}
			
			dfs_low[x] = min(dfs_low[x], dfs_low[v]);
		}else if(f != v){
			dfs_low[x] = min(dfs_num[v], dfs_low[x]);
		}
	}	
}

bool compar(int i, int j){
	if(art[i] > art[j]){
		return true;
	}
	
	if(art[i] < art[j]){
		return false;
	}
	
	return i < j;
}

int main (){
	int n, m;
	
	while(scanf("%d%d", &n, &m) && n && m){
		int u, v;
		
		cnt = 0;
		memset(dfs_num, -1, sizeof dfs_num);
		memset(dfs_low, -1, sizeof dfs_low);
		
		for(int i = 0 ; i < n ; i++){
			art[i] = 1;
			ind[i] = i;
		}
		
		while(scanf("%d%d", &u, &v) != EOF){
			if(u == -1 && v == -1){
				break;
			}
			
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		for(int i = 0 ; i < n ; i++){
			if(dfs_num[i] == -1){
				root = i;
				son = 0;
				
				dfs(i, i);
				
				art[root] = son;
			}
		}
		
		sort(ind, ind + n, compar);
		
		for(int i = 0 ; i < m ; i++){
			printf("%d %d\n", ind[i], art[ind[i]]);
		}
		
		printf("\n");
		
		for(int i = 0 ; i < n ; i++){
			graph[i].clear();
		}
	}
	
	return 0;
}
