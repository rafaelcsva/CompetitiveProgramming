#include <bits/stdc++.h>

using namespace std;

const int N = 14;
vector< int > adj[N];
bool dp[1 << 14][N][N];
bool used[1 << 14][N][N];
int can[1 << 14];
bool used1[1 << 14];
int dp1[1 << 14];
bool calc[1 << 14];
int res[1 << 14];
int n, m;
int vis[N + 10];
int test = 1;

bool solve(int mask, int u, int start){
	bool &ans = dp[mask][u][start];
	bool &us = used[mask][u][start];

	if(us){
		return ans;
	}

	us = true;

	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i];

		if(v == start){
			can[mask] = 1;
		}

		int e = 1 << (v - 1);

		if((mask & e) == 0){
			solve(mask | e, v, start);
		}
	}

	return ans;
}

int dfs(int i, int mask){
	int cnt = 0;
	vis[i] = test;

	for(int k = 0 ; k < adj[i].size() ; k++){
		int v = adj[i][k];

		int e = 1 << (v - 1);

		if(mask & e){
			cnt++;


			if(vis[v] != test){
				cnt += dfs(v, mask);
			}
		}
	}

	return cnt;
}

int dfs(int mask){
	for(int j = 0 ; j < n ; j++){
		int e = 1 << j;

		if(mask & e){
			test++;
			return dfs(j, mask);
		}
	}

	return 0;
}

int take(int mask){
	if(calc[mask]){
		return res[mask];
	}

	calc[mask] = true;
	int d = __builtin_popcount(mask);

	if(d <= 3){
		return res[mask] = 0;
	}else{
		return res[mask] = dfs(mask) - d;
	}
}

int solve1(int mask){
	if(mask == (1 << n) - 1){
		return 0;
	}

	if(used1[mask]){
		return dp1[mask];
	}

	for(int j = 1 ; j < (1 << n) ; j++){
		if((mask & j) == 0 && can[j]){
			dp1[mask] = max(dp1[mask], take(j) + solve1(mask | j));
		}
	}

	return dp1[mask];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0 ; i < m ; i++){
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1 ; i <= n ; i++){
		solve(1 << (i - 1), i, i);
	}

	cout << solve1(0) << endl;

	return 0;
}