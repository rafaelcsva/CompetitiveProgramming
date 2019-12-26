#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;
typedef long long	ll;
const int N = int(2e5 + 10);
int n; // number of nodes
vector< pii > adj[N]; // adjacency list of graph
int a, b;
vector<bool> visited;
vector<int> tin, low;
int timer;
int cor[N];
ll tmp;
bool found = false, found2 = false;
ll sum1, sum2;
bool is_cut[N];
const int M = int(5e5 + 10);
bool is_bridge[M];
int curr = 1;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (pii u : adj[v]) {
        int to = u.first;

        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                is_cut[v] = true;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        is_cut[v] = true;
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

void dfs1(int v, int p = -1){
	if(v == b){
		found = true;
		curr = 2;
	}

	tmp++;
	// printf("%d, %lld\n", v + 1, tmp);
	cor[v] = curr;

	for(pii u: adj[v]){
		int to = u.first;

		if(to == p) continue;
		
		if(!cor[to]){
			ll st = tmp;

			dfs1(to, v);

			if(v == a && is_cut[v] && !found){
				sum1 += tmp - st;
				// printf("aqui! + %lld\n", tmp - st);
			}else if(v == b && is_cut[v] && !found2){
				sum2 += tmp - st;
			}

			if(v == a){
				found = false;
				found2 = false;
			}

			if(v == b){
				found2 = false;
			}
		}else if(cor[to] == 1 && v != b && curr == 2){
			found2 = true;
		}
	}

	if(v == b){
		curr = 1;
	}
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int m;

		scanf("%d %d %d %d", &n, &m, &a, &b);

		for(int i = 0 ; i < m ; i++){
			int ui, vi;

			scanf("%d %d", &ui, &vi);

			ui--, vi--;

			adj[ui].push_back({vi, i});
			adj[vi].push_back({ui, i});
		}	

		find_cutpoints();	

		a--, b--;

		dfs1(a);

		printf("%lld\n", sum1 * sum2);
		sum1 = sum2 = 0LL;

		for(int i = 0 ; i < n ; i++){
			cor[i] = 0;
			adj[i].clear();
			is_cut[i] = false;
		}	

		found = found2 = false;
		curr = 1;
		// tmp = 0LL;
	}

	return 0;
}