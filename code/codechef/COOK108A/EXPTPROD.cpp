#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = 1010;
ll a[N];
const ll mod = ll(1e9 + 7LL);

ll fast_expo(ll b, ll x){
	ll number = b;
	ll r = 1LL;

	while(x){
		if(x & 1LL){
			r = (r * number) % mod;
		}

		number = (number * number) % mod;
		x >>= 1LL;
	}

	return r;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n, k;

		scanf("%d %d", &n, &k);

		ll sum = 0LL;

		for(int i = 0 ; i< n ; i++){
			scanf("%lld", &a[i]);
			sum += a[i];

			if(sum >= mod){
				sum -= mod;
			}
		}

		ll tot = fast_expo(n, k);
		ll inv = fast_expo(tot, mod - 2LL);
		ll tsum = fast_expo(sum, k);
		tsum %= ll(n);
		tsum = (tsum * inv) % mod;

		printf("%lld\n", tsum);
	}

	return 0;
}