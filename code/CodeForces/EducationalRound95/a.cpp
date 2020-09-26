#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		ll x, y, k;

		scanf("%lld %lld %lld", &x, &y, &k);

		ll num = (y * k + k - 1 + x - 2LL) / (x - 1LL);

		printf("%lld\n", num + k);
	}

	return 0;
}