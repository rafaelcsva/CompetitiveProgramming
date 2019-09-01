#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = 2100;
ll bit[N];
const ll mod = ll(1e9 + 7);

int LSOne(int x){
	return x & (-x);
}

void update(int x){
	while(x < N){
		bit[x] += 1LL;
		x += LSOne(x);
	}
}

ll query(int x){
	ll sum = 0LL;

	while(x > 0){
		sum += bit[x];
		x -= LSOne(x);
	}

	return sum;
}

ll rsq(int l, int r){
	return query(r) - query(l - 1);
}

int a[N];
ll dp[N];

int main(){
	int n;
	ll k;

	scanf("%d %lld", &n, &k);

	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &a[i]);

		dp[i] = rsq(a[i] + 1, N - 1);
		update(a[i]);
	}

	if(k == 1){
		ll sum = 0LL;

		for(int i = 1 ; i <= n ; i++){
			sum += dp[i];
		}

		printf("%lld\n", sum);
	}else{
		ll inv = ll(5e8 + 4);
		ll tot = 0LL;
		ll sum = ((((1LL + k - 1LL) * (k - 1LL)) % mod) * inv) % mod;
		ll ans = 0LL;

		for(int i = 1 ; i <= n ; i++){
			ll current = rsq(a[i] + 1, N - 1);
			ll d = current - dp[i];

			ans = ans + ((dp[i] * k) + d * sum) % mod; 
			// printf("%lld %lld\n", dp[i], d);

			if(ans >= mod) ans -= mod;
			
			update(a[i]);
		}

		printf("%lld\n", ans);
	}

	return 0;
}