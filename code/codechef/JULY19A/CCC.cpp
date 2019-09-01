#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 1010;
ll dp[N][N];
int used[N][N];
int test;
ll a[N];
const ll inf = ll(1e18);
int n;
ll pref[N];

ll solve(int i, int z){
	if(z > n - i + 1){
		return inf;
	}

	if(z <= 0){
		return 0;
	}

	ll &ans = dp[i][z];

	if(used[i][z] == test){
		return ans;
	}

	used[i][z] = test;

	return ans = min(solve(i + 1, z - 1) + a[i], a[i + 1] + solve(i + 1, z));
}

ll sum(int l, int r){
	if(r > n){
		return inf;
	}
	
	return pref[r] - pref[l - 1];
}

int main(){
	int t;

	scanf("%d", &t);

	for(test = 1 ; test <= t ; test++){
		int z;

		scanf("%d %d", &n, &z);

		for(int i = 1 ; i <= n ; i++){
			scanf("%lld", &a[i]);
			pref[i] = a[i] + pref[i - 1];
		}

		sort(a + 1, a + 1 + n, greater< ll >());

		ll best = inf;
		ll pref = 0LL;

		for(int i = 1 ; i <= n ; i++){
			pref = a[i] * ll(i);

			best = min(best, pref + sum(i + 1, i + 1 + z - 2));
		}

		printf("%lld\n", best);
	}

	return 0;
}