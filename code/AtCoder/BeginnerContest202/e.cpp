#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int sz[N];
int color[N];
vector< int > adj[N];
vector< pair< int, int > > qu[N];
int ans[N];
vector< int > vec[N];
int cnt[N];

void dfs_size(int v, int p, int deep) {
	sz[v] = 1;
    color[v] = deep;
	for (auto u : adj[v]) {
		if (u != p) {
			dfs_size(u, v, deep + 1);
			sz[v] += sz[u];
		}
	}
}

void dfs(int v, int p, bool keep) {
	int Max = -1, bigchild = -1;
	for (auto u : adj[v]) {
		if (u != p && Max < sz[u]) {
			Max = sz[u];
			bigchild = u;
		}
	}
	for (auto u : adj[v]) {
		if (u != p && u != bigchild) {
			dfs(u, v, 0);
		}
	}
	if (bigchild != -1) {
		dfs(bigchild, v, 1);
		swap(vec[v], vec[bigchild]);
	}
	vec[v].push_back(v);
	cnt[color[v]]++;
	for (auto u : adj[v]) {
		if (u != p && u != bigchild) {
			for (auto x : vec[u]) {
				cnt[color[x]]++;
				vec[v].push_back(x);
			}
		}
	}

    for(auto e: qu[v]){
        ans[e.second] += cnt[e.first];
    }

	// there are cnt[c] vertex in subtree v color with c
	if (keep == 0) {
		for (auto u : vec[v]) {
			cnt[color[u]]--;
		}
	}
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 2 ; i <= n ; i++){
        int pi;

        scanf("%d", &pi);
        adj[i].push_back(pi);
        adj[pi].push_back(i);
    }

    int q;

    scanf("%d", &q);

    for(int i = 1 ; i <= q;  i++){
        int ui, di;

        scanf("%d %d", &ui, &di);

        qu[ui].push_back({di, i});
    }

    dfs_size(1, 1, 0);

    dfs(1, 1, 0);

    for(int i = 1 ; i <= q ; i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}