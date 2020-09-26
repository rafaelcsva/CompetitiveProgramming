#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		ll x;

		scanf("%lld", &x);

		ll st = 1LL;
		ll add = 2LL;

		ll qtd = 0LL;

		while(x >= (st * (st + 1)) / 2LL){
			x -= (st * (st + 1)) / 2LL;

			st += add;
			add *= 2LL;
			qtd++;
		}

		printf("%lld\n", qtd);
	}

	return 0;
}