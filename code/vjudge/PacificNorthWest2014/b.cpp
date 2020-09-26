#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 102;
ll dis[N][N];
ll dd[N];
int n, k;
queue< int > q;
vector< ll > v;

int bfs(int u, ll ed){
	while(!q.empty()) q.pop();

	memset(dd, -1, sizeof dd);

	dd[u] = 0;

	q.push(u);

	while(!q.empty()){
		auto v = q.front();

		if(dd[v] > k){
			return dd[v];
		}

		q.pop();

		for(int i = 0 ; i < n ; i++){
			if(dis[v][i] <= ed && dd[i] == -1){
				dd[i] = dd[v] + 1;
				q.push(i);
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		if(dd[i] == -1LL){
			// printf("falhei no %d\n", i);
			return k + 1;
		}
	}

	return 0;
}

bool can(ll val){
	for(int i = 0 ; i < n ; i++){
		if(bfs(i, val) > k){
			// printf("falha no %d\n", i);

			return false;
		}
	}

	return true;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int m;

		scanf("%d %d %d", &n, &k, &m);

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				dis[i][j] = (i == j) ? 0 : -1LL;
			}
		}

		for(int i = 0 ; i < m ; i++){
			int ui, vi;

			ll di;

			scanf("%d %d %lld", &ui, &vi, &di);

			dis[ui][vi] = dis[vi][ui] = di;
		}

		for(int k = 0 ; k < n ; k++){
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < n ; j++){
					if(dis[i][k] == -1LL || dis[k][j] == -1LL) continue;

					if(dis[i][j] == -1LL){
						dis[i][j] = dis[i][k] + dis[k][j];
					}

					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}

		for(int i = 0 ; i < n ; i++){
			for(int j = i + 1 ; j < n ; j++){
				v.push_back(dis[i][j]);
			}
		}

		sort(v.begin(), v.end());

		int lo = 0;
		int hi = int(v.size()) - 1;
		ll r = -1LL;

		while(lo <= hi){
			int mid = (lo + hi) >> 1;

			if(can(v[mid])){
				r = v[mid];
				hi = mid - 1;
			}else{
				// printf("%lld nao passa\n", v[mid]);
				lo = mid + 1;
			}
		}

		printf("%lld\n", r);

		v.clear();
	}

	return 0;
}