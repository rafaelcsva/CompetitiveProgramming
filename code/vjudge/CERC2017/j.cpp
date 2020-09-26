#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 10;
vector< int > adj[N];
int sz[N];
int n;
int father[N];
int cadj[N];
vector< int > nvl[N];
int deeps;

bool test(int k){
	for(int i = 1 ; i <= n ; i++){
		sz[i] = 1;
	}

	for(int i = deeps ; i >= 0 ; i--){
		for(int u: nvl[i]){
			if(sz[u] > k){
				return false;
			}

			if(sz[u] < k){
				if(father[u] == -1){
					return false;
				}

				sz[father[u]] += sz[u];
			}
		}
	}

	return true;
}

void dfs(int root, int dp = 0){
	deeps = max(dp, deeps);

	nvl[dp].push_back(root);
	// printf("%d on %d\n", root, dp);

	for(int u: adj[root]){
		if(father[u] == 0){
			father[u] = root;
			dfs(u, dp + 1);
		}
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 1 ; i < n ; i++){
			int u, v;

			scanf("%d %d", &u, &v);

			adj[u].push_back(v);
			adj[v].push_back(u);
		}


		if(n == 2){
			printf("%d\n", 1);
			return 0;
		}

		int root = 0;

		for(int i = 1 ; i <= n ; i++){
			if(adj[i].size() > 1){
				root = i;
				break;
			}
		}


		father[root] = -1;
		dfs(root);
		// test(4);return 0;

		set< int > poss;

		for(int i = 1 ; i * i <= n ; i++){
			if(n % i == 0){
				if(test(i)){
					poss.insert((n / i) - 1);
				}

				if(i != 1 && test(n / i)){
					poss.insert(i - 1);
				}
			}
		}

		for(int u: poss){
			printf("%d ", u);
		}

		printf("\n");

		for(int i = 1 ; i <= n ; i++){
			adj[i].clear();
			father[i] = 0;
			nvl[i].clear();
		}
	}

	return 0;
}