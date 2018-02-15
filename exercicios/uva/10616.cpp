#include <bits/stdc++.h>

using namespace std;

const int N = 210, S = 30, M = 40;
typedef long long int	lli;
lli dp[S][N][M], used[S][N][M], a[N];
int n, q, Q, m;
lli d;

lli mod(lli x){
	return (x + d) % d;
}

lli solve(lli s, int k, int c){

	if(c == m){
		return s == 0;
	}
	
	if(k == n){
		return 0;
	}
	
	lli &ans = dp[s][k][c];
	
	if(used[s][k][c] == Q){
		return ans;
	}
	
	used[s][k][c] = Q;
	
	return ans = solve(mod(s + mod(a[k] % d)), k + 1, c + 1) + solve(s, k + 1, c);
}

int main (){
	int test = 1;
	
	while(scanf("%d%d", &n, &q) != EOF){
		if(n == 0 && q == 0){
			break;
		}
		
		for(int i = 0 ; i < n ; i++){
			scanf("%lld", &a[i]);
		}
		
		printf("SET %d:\n", test++);
		
		int lq = 1;
		
		while(q--){
			Q++;
			
			scanf("%lld%d", &d, &m);
			
			printf("QUERY %d: %lld\n", lq++, solve(0LL, 0, 0));
		}
	}
	
	return 0;
}
