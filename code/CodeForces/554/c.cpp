#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

ll lcm(ll a, ll b){
	return a * (b / __gcd(a, b));
}

int main(){
	ll a, b;

	scanf("%lld %lld", &a, &b);

	ll best = ll(1e18);
	ll bound = ll(1e5);
	ll besti = 0;

	for(ll k = 0LL ; k <= bound ; k++){
		ll d = lcm(a + k, b + k);
		
		if(d < best){
			besti = k;
			best = d;
		}
	}

	printf("%lld\n", besti);

	return 0;
}