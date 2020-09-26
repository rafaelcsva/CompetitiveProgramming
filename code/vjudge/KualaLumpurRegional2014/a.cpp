#include <bits/stdc++.h>

using namespace std;

const int N = int(1e3 + 10);
int vis[N];
int test = 1;
vector< int > adj[N];
int d[N];
const int inf = 1000 * 1000 + 10;

struct edge{
	int a, b, cost;
};

vector< edge > edges;

void dfs(int u){
	vis[u] = test;

	for(int v: adj[u]){
		if(vis[v] == test) continue;

		dfs(v);
	}
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n, m;

		scanf("%d %d", &n, &m);

		for(int i = 0 ; i < m ; i++){
			int a, b, c;

			scanf("%d %d %d", &a, &b, &c);
			
			adj[b].push_back(a);

			edges.push_back({a, b, c});
		}

		dfs(0);

		for(int i = 1 ; i < n ; i++){
			d[i] = inf;
		}

		for(int i = 0 ; i < n - 1 ; i++){
			for(auto e: edges){
				if(d[e.a] < inf){
					d[e.b] = min(d[e.b], d[e.a] + e.cost);
				}
			}
		}

		bool ver = false;

		for(auto e: edges){
			if(d[e.a] < inf){
				// printf("%d %d %d\n", e.b, e.a, d[e.b]);

				if(d[e.b] > d[e.a] + e.cost){
					// printf("yeah\n");

					if(vis[e.b] == test){
						ver = true;
						break;
					}
				}
			}
		}

		printf("Case #%d: ", test++);

		if(ver){
			printf("possible\n");
		}else{
			printf("not possible\n");
		}

		for(int i = 0 ; i < n ; i++){
			adj[i].clear();
		}

		edges.clear();
	}

	return 0;
}