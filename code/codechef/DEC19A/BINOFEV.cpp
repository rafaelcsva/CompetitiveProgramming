#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const ll mod = 998244353LL;
const int N = int(1e6 + 10);
ll fat[N];

ll fast_expo(ll number, ll x){
	ll base = number;
	ll r = 1LL;

	while(x){
		if(x & 1LL){
			r = (r * base) % mod;
		}

		base = (base * base) % mod;
		x >>= 1LL;
	}

	return r;
}

ll MOD(ll x){
	return ((x % mod) + mod) % mod;
}

ll inv2;

ll comb(ll n){
	return ((n * (n - 1LL)) % mod * inv2) % mod;
}

ll idiota(int n, ll p){
	ll fp = p;
	ll ac = 0LL;

	for(int i = 1 ; i <= n ; i++){
		ac += comb(fp);
		// printf("%lld\n", fp);
		
		fp *= p;
		fp %= mod;

		if(ac >= mod) ac -= mod;
	}

	return ac;
}

int main(){
	fat[0] = 1LL;

	for(ll i = 1 ; i < N ; i++){
		fat[i] = i * fat[i - 1];
		fat[i] %= mod;
	}

	int t;

	scanf("%d", &t);

	inv2 = fast_expo(2LL, mod - 2LL);
	
	while(t--){
		ll n, p, r;

		scanf("%lld %lld %lld", &n, &p, &r);
		assert(r == 2LL);

		ll invp = fast_expo(p - 1LL, mod - 2LL);
		ll nump = fast_expo(p, n + 1LL);

		ll p1 = (MOD(nump - p) * invp) % mod;

		ll invpp = fast_expo((p * p) % mod - 1LL, mod - 2LL);
		ll numpp = fast_expo(p, 2LL * n + 2LL);

		ll p2 = (MOD(numpp - p * p) * invpp) % mod;

		printf("%lld\n", (MOD(p2 - p1) * inv2) % mod);
	}

	return 0;
}