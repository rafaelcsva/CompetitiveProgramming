#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = int(1e6);
ll dp[N];
const ll mod = ll(1e9 + 7LL);
ll fat[N];

ll MOD(ll x){
	return ((x % mod) + mod) % mod;
}

ll fast_pow(ll n, ll x){
	if(x == 1LL){
		return n;
	}

	if(x == 0LL){
		return 1LL;
	}

	ll lf = fast_pow(n, x >> 1LL);
	lf = (lf * lf) % mod;

	if(x & 1LL){
		lf = (lf * n) % mod;
	}

	return lf;
}

ll comb(int n, int k){
	ll fn = fat[n];
	ll fk = fat[k];
	ll fnk = fat[n - k];

	fk = fast_pow(fk, mod - 2LL);
	fnk = fast_pow(fnk, mod - 2LL);

	return MOD(MOD(fn * fk) * fnk);
}

class HomeAwayLeague{
public:
	int matches(int x){
		dp[0] = 1LL;
		dp[2] = 1LL;

		for(ll k = 3 ; k < N ; k++){
			dp[k] = MOD((k - 1LL) * (dp[k - 1] + dp[k - 2]));
		}

		fat[0] = fat[1] = 1LL;

		for(ll k = 2 ; k < N ; k++){
			fat[k] = MOD(k * (fat[k - 1]));
		}

		ll h = x >> 1;
		ll c = comb(x, h);

		ll r = MOD(c * MOD(fat[h] * dp[h]));

		return r;
	}
};

int main(){
	HomeAwayLeague test;

	printf("%d\n", test.matches(8));

	return 0;
}