#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 100;
int n;
vector<int>graph[N];
int cor[N], f[N], comp[N];
int cl;

int dfs(int x, int ft){
	cor[x] = cl;
	int t = 1;
	f[x] = ft;
	
	for(int i = 0 ; i < graph[x].size() ; i++){
		int v = graph[x][i];
		
		if(cor[v] != cl){
			t += dfs(v, ft);
		}
	}
	
	return t;
	
}
int main (){
	int t;
	int test = 1;
	
	scanf("%d", &t);
	
	while(t--){
		
		scanf("%d", &n);
		
		for(int i = 0 ; i < n ; i++){
			int u, v;
			
			scanf("%d%d", &u, &v);
			
			graph[u].push_back(v);
		}
		
		int c = 0, ans = 0;
		
		for(int i = 1 ; i <= n ; i++){
			if(cor[i] == 0){
				cl++;
				
				int w = dfs(i, i);
				comp[i] = w;
				
				if(w > ans){
					c = i;
					ans = w;
				}
			}
		}
		
		printf("Case %d: %d\n", test++, c);
		
		for(int i = 1 ; i <= n ; i++){
			cor[i] = 0;
			graph[i].clear();
			comp[i] = 0;
		}
	}
	
	return 0;
}
