#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 51;
ll fat[N];
int n[N], m;
int k;
int used[N][N];
ll dp[N][N];
int test = 1;

ll solve(int i, int r){
	if(r == 0){
		return fat[m];
	}

	if(i == k){
		return (r == 0) ? fat[m] : 0;
	}

	int &us = used[i][r];
	ll &ans = dp[i][r];

	if(us == test){
		return ans;
	}

	us = test;
	ans = 0LL;

	for(int d = 0 ; d <= min(r, n[i]) ; d++){
		ans += solve(i + 1, r - d) / fat[d];
	}

	return ans;
}

int main(){
	fat[0] = 1LL;

	for(ll i = 1 ; i < N ; i++){
		fat[i] = i * fat[i - 1];
	}

	while(scanf("%d %d", &m, &k) != EOF){
		if(m == 0) break;

		for(int i = 0 ; i < k ; i++){
			scanf("%d", &n[i]);
		}

		printf("%lld\n", solve(0, m));

		test++;
	}

	return 0;
}