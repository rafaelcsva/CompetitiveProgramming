#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(5e4 + 10);
bool is_composite[N];
vector< ll > primes;
const int M = int(1e5 + 10);
ll a[M];

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

ll sum;
const ll inf = ll(1e18);
const ll LIM = 1000 + 10;

ll solve(ll x, int n){
	ll tmp = 0LL;

	for(int i = 0 ; i < n ; i++){
		tmp += abs(a[i] - x);
	}

	return tmp;
}

bool is_prime(ll number){
	if(number <= 1LL) return false;

	for(int i = 0 ; i < primes.size() ; i++){
		ll u = primes[i];

		if(u * u > number) break;

		if(number % u == 0LL) return false;
	}

	return true;
}

int main(){
	sieve();
	//printf("%lu\n", primes.size());	

	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i]);

		sum += a[i];
	}

	sort(a, a + n);

	ll mean = sum / n;

	ll ans = inf;

	for(ll k = 0 ; k < LIM ; k++){
		ll tmp = 0LL;

		if(is_prime(mean + k)){
			ans = min(ans, solve(mean + k, n));
		}

		if(is_prime(mean - k)){
			ans = min(ans, solve(mean - k, n));
		}
	}

	if(n & 1){
		mean = a[n / 2];
	}else{
		mean = (a[n / 2 - 1] + a[n / 2]) / 2LL;
	}

	for(ll k = 0 ; k < LIM ; k++){
		ll tmp = 0LL;

		if(is_prime(mean + k)){
			ans = min(ans, solve(mean + k, n));
		}

		if(is_prime(mean - k)){
			ans = min(ans, solve(mean - k, n));
		}
	}

	printf("%lld\n", ans);

	return 0;
}