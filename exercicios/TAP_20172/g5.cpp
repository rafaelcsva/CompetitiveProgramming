#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
#define MAXIMO	100010

using namespace std;
int T, M, N;

int used[60][MAXIMO];
int dp[60][MAXIMO];

int solve(int t, int n){
	if(t == T)
		return 1;
		
	if(used[t][n]){
		return dp[t][n];
	}
	
	used[t][n] = 1;
	
	if(n > M && n < N){
		return dp[t][n] = (solve(t+1, n+1)%MOD + solve(t+1, n-1)%MOD)%MOD;
	}else if(n > M){
		return dp[t][n] = solve(t+1, n-1)%MOD;
	}
	
	return dp[t][n] = solve(t+1, n+1)%MOD;
}

int main (){

	scanf("%d%d%d", &T, &M, &N);
	
	long long int l = 0;
	
	for(int i = M ; i <= N ; i++){
		l = (l%MOD + solve(1, i)%MOD)%MOD;
	}
	
	printf("%Ld\n", l);

	return 0;
}
