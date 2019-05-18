#include <bits/stdc++.h>

using namespace std;

vector< int > topological_sort;

const int N = 30, M = int(1e5);
vector< int > adj[N], rev[N];
bool marked[N];
int component[N];
string ballot[M];

void dfs(int u, vector< int > adj[], int comp = 1){
	marked[u] = true;
	component[u] = comp;

	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i];

		if(!marked[v]){
			dfs(v, adj, comp + 1);
		}
	}
}

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0 ; i < n ; i++){
		scanf("%d %s", &points, ballot);

		for(int i = 0 ; i < strlen(ballot) ; i++){
			int u = ballot[i] - 'A';

			for(int j = i + 1 ; j < strlen(ballot) ; j++){
				int v = ballot[i]
			}
		}
	}

	return 0;
}