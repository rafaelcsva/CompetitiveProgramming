#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = 60;
ll dp[N * N][N], used[N * N][N], q;
int n, k, m;

ll solve(int i, int j){
	if(j > k){
		return 0LL;
	}
	
	if(i == n){
		return j == k;
	}
	
	if(j == k){
		return i == n;
	}
	
	ll &ans = dp[i][j];
	
	if(used[i][j] == q){
		return ans;
	}
	
	ans = 0LL;
	used[i][j] = q;
	
	for(int add = 1 ; add <= m ; add++){
		ans += solve(i + add, j + 1);
	}
	
	return ans;
}

int main (){
	while(scanf("%d%d%d", &n, &k, &m) != EOF){
		q++;
		printf("%lld\n", solve(0, 0));
	}

	return 0;
}
