#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;

const int N = int(1e5 + 100);
vector< pii > adj[N];
int color[N];

void dfs(int u, int val, int ft){
	color[u] = val;

	for(int i = 0 ;i < adj[u].size() ; i++){
		int v = adj[u][i].first;
		int w = adj[u][i].second;

		if(v != ft){
			dfs(v, (val + w) & 1, u);
		}
	}
}

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 1 ; i < n ; i++){
		int ui, vi, wi;

		scanf("%d %d %d", &ui, &vi, &wi);
		wi &= 1;

		adj[ui].push_back({vi, wi});
		adj[vi].push_back({ui, wi});
	}

	dfs(1, 1, 0);

	for(int i = 1 ; i <= n ; i++){
		printf("%d\n", color[i]);
	}

	return 0;
}