#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const ll B = ll(3e5);
ll x, y, d;

// store x, y, and d as global variables
void extendedEuclid(ll a, ll b) {
	if (b == 0) { x = 1; y = 0; d = a; return; }
	// base case
	extendedEuclid(b, a % b);
	// similar as the original gcd
	ll x1 = y;
	ll y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}

int main(){
	ll m, a, b;

	scanf("%lld %lld %lld", &m, &a, &b);

	ll sum = 0LL;
	ll bound = max({B, a, b});
	bound = min(bound, m);

	ll sum = 1LL;
	ll carry = 1LL;

	b = -b;

	extendedEuclid(a, b);

	for(ll i = 1LL ; i <= bound ; i++){
		if((i % d) == 0LL){
			ll x1 = x * (i / d);
			ll y1 = y * (i / d);
			ll f1 = b / d;
			ll f2 = a / g;

			ll k = max((-x1 + f1 - 1LL) / f1, (y1 + f2 - 1LL) / f2);

			ll ry = y1 - f2 * k;
			ll rx = x2 + f1 * k;
		}
	}

	return 0;
}