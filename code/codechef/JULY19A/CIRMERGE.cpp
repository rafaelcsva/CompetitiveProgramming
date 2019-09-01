#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long	ll;
 
const int N = int(1000);
ll pref[N];
ll dp[N][N];
int used[N][N];
int test = 1;
ll a[N];
const ll inf = ll(1e18);
 
ll sum(int l, int r){
	if(l > r){
		return 0LL;
	}
 
	return pref[r] - pref[l - 1];
}
 
ll solve(int i, int j){
	if(i > j){
		return 0LL;
	}
 
	if(i == j){
//		printf("%d = %lld\n", i, a[i]);
		return 0LL;
	}
 
	if(i + 1 == j){
//		printf("%d, %d = %lld\n", i, j, a[i] + a[j]);
		return a[i] + a[j];
	}
 
	ll &ans = dp[i][j];
    int &us = used[i][j];

	if(us == test){
		return ans;
	}
    
    us = test;
	ans = inf;
 
	for(int k = i ; k < j ; k++){
		ans = min(solve(i, k) + solve(k + 1, j) + sum(i, j), ans);
	}
//	printf("%lld (%d, %d)\n", ans, i, j);
 
	return ans;
}

int main(){
	int n, k;
    int t;

    scanf("%d", &t);

    for(test = 1 ; test <= t ; test++){
    	scanf("%d", &n);
     
    	for(int i = 1 ; i <= n ; i++){
    		scanf("%lld", &a[i]);
    		pref[i] = a[i] + pref[i - 1];
    	}

        for(int i = 1 ; i <= n ; i++){
            pref[i + n] = a[i] + pref[i + n - 1];
            a[i + n] = a[i];
        }

        ll best = inf;

        for(int i = 1 ; i <= n ; i++){
            best = min(best, solve(i, i + n - 1));
        }

        printf("%lld\n", best);
    }

	return 0;
}
