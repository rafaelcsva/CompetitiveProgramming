#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(2e5 + 100);
bool is_composite[N];
vector< ll > primes;
ll pref[N];

void sieve(){
	for(int i = 2 ; i * i < N ; i++){
		if(!is_composite[i]){
			for(int j = i + i ; j < N ; j += i){
				is_composite[j] = true;
			}
		}
	}

	for(ll i = 2 ; i < N ; i++){
		if(!is_composite[i]){
			primes.push_back(i);
		}
	}
}

ll fast_pow(ll n, ll x){
	ll b = n;
	ll number = 1LL;

	while(x > 0LL){
		if(x & 1LL){
			number *= b;
		}

		x /= 2LL;
		b = (b * b);
	}

	return number;
}

ll sumDiv(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1LL;

	while(PF * PF <= N){
		ll power = 0LL;

		while(N % PF == 0LL){
			N /= PF;
			power++;
		}

		ans *= (fast_pow(PF, power + 1) - 1LL) / (PF - 1LL);

		PF = primes[++PF_idx];
	}

	if(N != 1){
		ans *= (fast_pow(N, 2) - 1LL) / (N - 1LL);
	}

	return ans;
}

int main(){
	sieve();
	// printf("sai!\n");

	for(ll i = 1 ; i < N ; i++){
		pref[i] = sumDiv(i) + pref[i - 1];
		assert(pref[i] > 0LL);
	}

	fflush(stdout);

	int n, q;

	scanf("%d %d", &n, &q);

	while(q--){
		int x, y;
		ll k;

		scanf("%d %d %lld", &x, &y, &k);

		printf("%lld\n", (pref[y] - pref[x - 1]) % k);
	}

	return 0;
}