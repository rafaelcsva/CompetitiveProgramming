#include <bits/stdc++.h>

using namespace std;

const int M = 40100, inf = (int) 1e9, N = 110;
int t, m, n;
int c[110];
int dp[M][N], used[M][N], dp2[M][N], used2[M][N];
int qtd = 0;

int solve1(int x, int k){
	if(x >= m){
		return x;
	}	
	
	if(k == n){
		return inf;
	}
	
	int &ans = dp[x][k];
	
	if(used[x][k] == t){
		return ans;
	}
	
	ans = inf;
	used[x][k] = t;
	
	ans = min(solve1(x + c[k], k + 1), solve1(x, k + 1));
	
	return ans;
}

int solve2(int x, int k){
	
	if(x == m){
		return 0;
	}
	
	if(x > m){
		return inf;
	}
	
	if(k == n){
		return inf;
	}
	
	int &ans = dp2[x][k];
	
	if(used2[x][k] == t){
		return ans;
	}
	
	ans = inf;
	used2[x][k] = t;
	
	ans = min(solve2(x + c[k], k + 1) + 1, solve2(x, k + 1));
	
	return ans;
}

int main (){
	int T;
	
	scanf("%d", &T);
	
	for(t = 1 ; t <= T ; t++){
		scanf("%d", &m);
		
		scanf("%d", &n);
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &c[i]);
		}
		
		m = solve1(0, 0);
		
		printf("%d %d\n", m, solve2(0, 0));
	}

	return 0;
}
