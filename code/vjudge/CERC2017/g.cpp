#include <bits/stdc++.h>

using namespace std;

const int N = 300100;
vector< pair< int, bool > > adj[N];
int dis[N];
int n, m;
double dp[N];
bool used[N];
const double inf = double(1e9);
const double eps = double(-1);

void bfs(){
	dis[n] = 0;

	priority_queue< pair< int, int > > pq;

	pq.push({n, adj[n].size()});

	while(!pq.empty()){
		auto uu = pq.top();
		pq.pop();

		int u = uu.first;

		for(auto &v: adj[u]){
			if(dis[v.first] == -1){
				dis[v.first] = dis[u] + 1;
				pq.push({v.first, adj[v.first].size()});
			}
		}
	}
}

double solve(int u){
	if(u == n){
		return 0.0;
	}

	double &ans = dp[u];
	bool &us = used[u];

	if(us){
		return ans;
	}

	ans = 0.0;
	us = true;
	bool is_leaf = true;

	int sz = 0;

	for(auto v: adj[u]){
		if(dis[v.first] + 1 == dis[u]) sz++;
	}

	for(auto v: adj[u]){
		if(dis[v.first] + 1 != dis[u])
			continue;

		is_leaf = false;
		double acc = double(sz) / double(adj[u].size());
		double err = 1.0 - acc;
		double er = 1.0;
		double anst = 0.0;

		for(int i = 1 ; i <= 100 ; i++){
			anst += (acc * er * (i + solve(v.first)));
			er *= err;
			printf("add %lf %lf %lf %lf\n", acc, err, (acc * er * i), ans);
		}

		ans += anst;
	}

	if(is_leaf){
		return ans = -inf;
	}
	printf("to retornando %lf\n", ans);

	return ans;
}

int main(){
	memset(dis, -1, sizeof dis);

	while(scanf("%d %d", &n, &m) != EOF){
		for(int i = 0 ; i < m ; i++){
			int u, v;

			scanf("%d %d", &u, &v);

			adj[u].push_back({v, false});
			adj[v].push_back({u, false});
		}

		bfs();

		int sz = 0;
		printf("%d\n", dis[1]);

		for(auto v: adj[1]){
			if(dis[v.first] + 1 == dis[1]) sz++;
		}

		double ans = 0.0;

		for(auto u: adj[1]){
			double acc = double(sz) / double(adj[1].size());
			double err = 1.0 - acc;
			double er = 1.0;

			printf("%lf %lf\n", acc, err);

			if(dis[u.first] + 1 == dis[1]){
				double r = solve(u.first);

				if(r < eps) continue;

				printf("r: %lf\n", r);

				for(int i = 1 ; i <= 100 ; i++){
					double tmp = (er * acc) * (i + r);

					ans += tmp;

					er *= err;
				}
			}
		}

		printf("%.5lf\n", ans);
	}

	return 0;
}