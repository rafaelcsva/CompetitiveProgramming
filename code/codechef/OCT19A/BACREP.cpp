#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = int(2e6);
const int off = int(5e5 + 10);
typedef pair< int, ll >	pli;

bool is_leaf[N];
vector< int > adj[N];
vector< pli > con[N][2];
int father[N];
ll bit[N];
vector< int > tim;
ll ans[N];
int deep[N];

int LSOne(int x){
	return x & (-x);
}

ll query(int x){
	ll sum = 0LL;

	while(x > 0){
		sum += bit[x];
		x -= LSOne(x);
	}
	
	return sum;
}

void update(int x, ll add){
	x += off;

	while(x < N){
		bit[x] += add;
		x += LSOne(x);
	}
}

ll rsq(int l, int r){
	if(l + off < N)
		l += off;

	if(r + off < N)
		r += off;
//	printf("%lld - %lld\n", query(r), query(l - 1));

	return query(r) - query(l - 1);
}

void dfs(int u, int ft, int de = 0){
	father[u] = ft;
	deep[u] = de;
	bool has_son = false;

	for(int v: adj[u]){
		if(v == ft) continue;

		dfs(v, u, de + 1);
		has_son = true;
	}

	is_leaf[u] = !has_son;
}

void compute(int u, int ft){
	// printf("---%d----\n", u);

	for(auto e: con[u][0]){
		update(deep[u] - e.first - 1, e.second);
	}

	for(auto e: con[u][1]){
		int l = deep[u] - e.first - 1;
		// printf("%d: %d %d %d\n", u, l, e.first, deep[u]);
		int r = l;

		if(is_leaf[u]){
			r = N - 1;
			// printf("eh folha!\n");
		}

		ans[e.first] += rsq(l, r);
	}

	for(auto v: adj[u]){
		if(v != father[u]){
			compute(v, u);
		}
	}

	for(auto e: con[u][0]){
		update(deep[u] - e.first - 1, -e.second);
	}
}

int main(){
	int n, q;

	scanf("%d %d", &n, &q);

	for(int i = 1 ; i < n ; i++){
		int ui, vi;

		scanf("%d %d", &ui, &vi);

		adj[ui].push_back(vi);
		adj[vi].push_back(ui);
	}

	dfs(1, 1);

	for(int i = 1 ; i <= n ; i++){
		ll ai;

		scanf("%lld", &ai);

		if(is_leaf[i]){
			con[i][0].push_back({0, ai});
			continue;
		}

		for(int v: adj[i]){
			if(v != father[i]){
				con[v][0].push_back({0, ai});
			}
		}
	}

	for(int t = 0 ; t < q ; t++){
		char op;

		scanf("\n%c", &op);

		if(op == '+'){
			int v;
			ll k;

			scanf("%d %lld", &v, &k);
			
			con[v][0].push_back({t, k});
		}else{
			int v;

			scanf("%d", &v);

			con[v][1].push_back({t, 0LL});
			tim.push_back(t);
		}
	}

	compute(1, 1);

	for(auto i: tim){
		printf("%lld\n", ans[i]);
	}

	return 0;
}