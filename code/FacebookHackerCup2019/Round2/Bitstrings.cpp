#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;

const int N = int(4e3 + 10), M = int(1e4);
int father[N];
int dp[N][M];
int used[N][M];
int sz[N];
int test;
pii con[N];
int color[N];
int pnt = 0;
pii req[M];
int ss[M];

int find(int x){
	if(x == father[x]){
		return x;
	}

	return father[x] = find(father[x]);
}

void join(int u, int v){
	int x = find(u);
	int y = find(v);

	if(x != y){
		if(x < y){
			father[y] = x;
			sz[x] += sz[y];
		}else{
			father[x] = y;
			sz[y] += sz[x];
		}
	}
}

int solve(int t, int sum){
	if(t == pnt){
		return dp[t][sum] = abs(sum - N);
	}

	if(used[t][sum] == test){
		return dp[t][sum];
	}

	used[t][sum] = test;

	return dp[t][sum] = min(solve(t + 1, sum - con[t].second), solve(t + 1, sum + con[t].second));
}

void take_dp(int t, int sum){
	if(t == pnt){
		return;
	}

	if(dp[t][sum] == dp[t + 1][sum - con[t].second]){
		color[con[t].first] = 1;
		take_dp(t + 1, sum - con[t].second);
	}else{
		color[con[t].first] = 0;
		take_dp(t + 1, sum + con[t].second);
	}
}

int main(){
	int t;

	scanf("%d", &t);

	for(test = 1 ; test <= t ; test++){
		int n, m;

		scanf("%d %d", &n, &m);

		for(int i = 1 ; i <= n ; i++){
			father[i] = i;
			sz[i] = 1;
		}

		for(int i = 0 ; i < m ; i++){
			int xi, yi;

			scanf("%d %d", &xi, &yi);

			req[i] = {xi, yi};

			while(xi < yi){
				join(xi, yi);
				xi++, yi--;
			}
		}
		
		printf("Case #%d: ", test);

		pnt = 0;

		for(int i = 1 ; i <= n ; i++){
			if(find(i) == i){
				con[pnt++] = {i, sz[i]};
			}
		}

		int r = solve(0, N);
		// printf("min = %d\n", r);
		take_dp(0, N);

		for(int i = 1 ; i <= n ; i++){
			// ss[i] = color[find(i)];
			putchar_unlocked(color[find(i)] + '0');
			// printf("%d", color[find(i)]);
		}
		putchar_unlocked('\n');

		for(int i = 0 ; i < m ; i++){
			while(req[i].first < req[i].second){
				assert(ss[req[i].first] == ss[req[i].second]);
				req[i].first++;
				req[i].second--;
			}
		}
	}

	return 0;
}