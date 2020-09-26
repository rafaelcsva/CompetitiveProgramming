#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(1e5) + 10;
vector< int > adj[N];
ll tot[N];
ll hap[N];
ll p[N];
ll h[N];

bool dfs(int u, int ft){
	tot[u] = hap[u] = 0;

	ll thap = 0;

	bool is_leaf = true;

	for(int v: adj[u]){
		if(v == ft) continue;

		is_leaf = false;

		if(!dfs(v, u)){
			return false;
		}

		tot[u] += tot[v];
		thap += hap[v];
	}

	ll sadv = tot[u] - thap;

	tot[u] += p[u];

	ll s = tot[u] + h[u];

	if(s & 1){
		// printf("u: %d %lld %lld %lld\n", u, tot[u], h[u], h[1]);
		return false;
	}

	hap[u] = s / 2;
	ll sadu = tot[u] - hap[u];

	if(is_leaf){
		if( hap[u] < 0 || sadu < 0){
			return false;
		}else{
			return true;
		}
	}

	ll midx = thap - sadv;
	
	if(sadu > sadv + p[u] || hap[u] < thap || hap[u] < 0 || sadu < 0){
		// printf("u: %d\n", u);
		return false;
	}

	return true;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n, m;

		scanf("%d %d", &n, &m);

		for(int i = 1 ; i <= n ; i++){
			scanf("%lld", &p[i]);
		}

		for(int i = 1 ; i <= n ; i++){
			scanf("%lld", &h[i]);
		}

		// printf("->%d %d\n", h[1], h[2]);

		for(int i = 1 ; i < n ; i++){
			int u, v;

			scanf("%d %d", &u, &v);

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		if(dfs(1, 1)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}

		for(int i = 1 ; i <= n ; i++) adj[i].clear();
	}

	return 0;
}