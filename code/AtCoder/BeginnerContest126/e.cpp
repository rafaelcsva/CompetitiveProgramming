#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 10);
vector< int > adj[N];
int marked[N];

void dfs(int u){
	marked[u] = 1;

	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i];

		if(!marked[v]){
			dfs(v);
		}
	}
}

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0 ; i < m ; i++){
		int ui, vi, wi;

		scanf("%d %d %d", &ui, &vi, &wi);

		adj[ui].push_back(vi);
		adj[vi].push_back(ui);
	}

	int ask = 0;

	for(int i = 1 ; i <= n ; i++){
		if(!marked[i]){
			ask++;
			dfs(i);
		}
	}

	cout << ask << endl;
	
	return 0;
}