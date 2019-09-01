#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 10);
int dis[N];
vector< int > con[N], adj[N];
int n, m, u, l, k;
queue< int > q;

void bfs(int u){
	memset(dis, -1, sizeof(int) * (n + 2));

	dis[u] = 0;

	q.push(u);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v: adj[u]){
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	int t;

	freopen("path.in", "r", stdin);

	scanf("%d", &t);

	while(t--){
		scanf("%d %d %d %d %d", &n, &m, &u, &l, &k);

		for(int i = 0 ; i < m ; i++){
			int u, v, w;

			scanf("%d %d %d", &u, &v, &w);

			adj[u].push_back(v);
			adj[v].push_back(u);

			con[u].push_back(w);
			con[v].push_back(w);
		}

		bfs(u);

		int ans = 0;

		for(int i = 1 ; i <= n ; i++){
			if(dis[i] < k){
				for(int w: con[i]){
					ans = max(ans, w);
				}
			}
		}

		printf("%d\n", ans);

		for(int i = 1 ; i <= n ; i++){
			con[i].clear(), adj[i].clear();
		}
	}

	return 0;
}
