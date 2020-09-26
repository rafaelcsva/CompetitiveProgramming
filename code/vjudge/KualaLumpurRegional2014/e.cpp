#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 5010;
vector< int > adj[N];
bitset< N > bst[N];
bitset< N > tt[N];
int test = 1;

int main(){
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j < i ; j++){
			tt[i][j] = 1;
		}
	}

	int t;
	// cout << (bst & 10LL) << endl;

	scanf("%d", &t);

	while(t--){
		int n, m;

		scanf("%d %d", &n, &m);

		for(int i = 0 ; i < m ; i++){
			int u, v;

			scanf("%d %d", &u, &v);

			adj[u].push_back(v);

			adj[v].push_back(u);
		}

		for(int i = 1 ; i <= n ; i++){
			sort(adj[i].begin(), adj[i].end());
		}

		for(int i = 1 ; i <= n ; i++){
			for(int u: adj[i]){
				if(u > i) break;

				bst[i][u] = 1;
			}
		}

		ll ans = 0LL;

		for(int i = 1 ; i <= n ; i++){
			int d = lower_bound(adj[i].begin(), adj[i].end(), i) - adj[i].begin();

			for(int j = d ; j < adj[i].size() ; j++){
				int cnt = ((tt[i] & bst[adj[i][j]]) | bst[i]).count();

				ans += ll(n - cnt - 2 - (j - d));
				// printf("%d-%d +%d\n", i, adj[i][j], n - cnt - 2 - (j - d));
			}
		}

		ll tn = n;
		ll tot = (n * (n - 1LL) * (n - 2LL)) / 6LL;

		printf("Case #%d: %lld\n", test++, tot - ans);

		for(int i = 1 ; i <= n ; i++){
			adj[i].clear();
			bst[i].reset();
		}
	}

	return 0;
}	