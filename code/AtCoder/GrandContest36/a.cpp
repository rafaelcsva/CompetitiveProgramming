#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main(){
	ll n;

	scanf("%lld", &n);

	for(ll u = 1LL ; u * u <= n ; u++){
		if(n % u == 0LL){
			printf("%lld\n", u);
			// assert(false);
		}
	}

	return 0;
}