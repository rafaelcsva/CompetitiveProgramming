#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = 5, M = 30100;
ll dp[N][M];
ll used[N][M];
int coin[N] = {1, 5, 10, 25, 50};
int t = 1, n;

ll solve(int i, int m){
	if(m < 0){
		return 0LL;
	}
	
	if(m == 0){
		return 1LL;
	}
	
	if(i == N){
		return 0LL;
	}
	
	ll &ans = dp[i][m];
	
	if(used[i][m] == t){
		return ans;
	}
	
	ans = 0LL;
	used[i][m] = t;
	
	for(int k = 0 ; m - k >= 0 ; k += coin[i]){
		ans += solve(i + 1, m - k);
	}
	
	return ans;
}

int main (){
	
	while(scanf("%d", &n) != EOF){
		
		ll m = solve(0, n);
		
		if(m == 1LL){
			printf("There is only 1 way to produce %d cents change.\n", n);
		}else{
			printf("There are %lld ways to produce %d cents change.\n", m, n);
		}
	}
	
	return 0;
}
