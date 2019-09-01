#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(1e5 + 10);
vector< ll > primes;
bool is_composite[N];
char st[N];

void sieve (int n) {
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) primes.push_back (i);
		for (int j = 0; j < primes.size () && i * primes[j] < n; ++j) {
			is_composite[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

ll expo(ll x, ll n, ll mod){
	ll r = 1LL;
	ll rr = x;

	while(n){
		if(n & 1LL){
			r = (r * rr) % mod;
		}

		rr = (rr * rr) % mod;
		n >>= 1LL;
	}

	return r;
}

int main(){
	srand(time(NULL));
	sieve(N);

	int t;

	scanf("%d", &t);

	while(t--){
		ll ans1, ans2;

		printf("1 %lld\n", primes[100]);
		fflush(stdout);

		scanf("%lld", &ans1);

		printf("1 %lld\n", primes[100] * 100LL);
		fflush(stdout);

		scanf("%lld", &ans2);

		ll tot = primes[100] * primes[100] * 10000LL;
		ll number = tot - ans2;
		ll tmp = number;
		int cnt = 0;
		ll rr = -1LL;

		for(auto u: primes){
			if(u * u > number){
				break;
			}

			if(number % u == 0LL){
				// printf("%lld\n", u);

				if(tot % u == ans2 && (primes[100] * primes[100]) % u == ans1){
					cnt++;
					rr = u;
					// printf("%lld\n", u);
				}

				while(number % u == 0LL){
					number /= u;
				}
			}
		}

		if(number != 1LL){
			if(tot % number == ans2 && (primes[100] * primes[100]) % number == ans1){
				cnt++;
				rr = number;
			}
		}

		assert(cnt == 1);
		
		printf("2 %lld\n", rr);
		fflush(stdout);

		scanf("\n%s", st);
		
		assert(st[0] == 'Y');
	}

	return 0;
}