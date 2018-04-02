#include <bits/stdc++.h>

using namespace std;

const int N = 400;
char s[N][N];
int n;
int cnt;
vector<int>graph[N];
bool isArticulation[N];
int dfs_low[N], dfs_num[N];
int root, son;

void dfs(int x, int f){
	dfs_low[x] = dfs_num[x] = cnt++;
	
	for(int i = 0 ; i < graph[x].size() ; i++){
		int v = graph[x][i];
		
		if(dfs_num[v] == -1){
			dfs(v, x);
			
			if(x == root){
				son++;
			}
			
			if(dfs_low[v] >= dfs_num[x]){
				isArticulation[x] = true;
			}
			
			dfs_low[x] = min(dfs_low[v], dfs_low[x]);
			
		}else if(f != v){
			dfs_low[x] = min(dfs_low[x], dfs_num[v]);
		}
	}
}

int main (){
	while(scanf("%d", &n) && n){
		
		memset(dfs_low, -1, sizeof dfs_low);
		memset(dfs_num, -1, sizeof dfs_num);
		memset(isArticulation, 0, sizeof isArticulation);
				
		int i = 0;
		cnt = 0;
		
		while(scanf("\n%[^\n]s", s[i++])){
			if(s[i - 1][0] == '0'){
				break;
			}
			
			int pot = 1;
			int v = 0;
			int ini = 0;
			
			while(s[i - 1][ini] != ' '){
				v = pot * v + (s[i - 1][ini] - '0');
				pot *= 10;
				ini++;
			}
			
			for(int j = ini + 1 ; j < strlen(s[i - 1]) ; j++){
				int u = 0;
				pot = 1;
				
				while(j < strlen(s[i - 1]) && s[i - 1][j] != ' '){
					u = pot * u + s[i - 1][j] - '0';
					pot *= 10;
					j++;
				}
						
				graph[v].push_back(u);
				graph[u].push_back(v);
			}
			
		}
		
		for(int i = 1 ; i <= n ; i++){
			if(dfs_low[i] == -1){
				root = i;
				son = 0;
				
				dfs(i, i);
				
				isArticulation[i] = son > 1;
			}
		}
		
		int tot = 0;
		
		for(int i = 1 ; i <= n ; i++){
			tot += isArticulation[i];
			
			if(isArticulation[i]){
				//printf("v: %d\n", i);
			}
		}
		
		printf("%d\n", tot);
		
		for(int i = 1 ; i <= n ; i++){
			graph[i].clear();
		}
		
	}
	
	return 0;
}
