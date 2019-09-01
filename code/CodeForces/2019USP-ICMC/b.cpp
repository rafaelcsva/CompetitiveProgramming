#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

set< ll > ans;

int main(){
	ll a, b;

	scanf("%lld %lld", &a, &b);

	for(ll div = 1LL ; div * div <= a ; div++){
		if(a % div == 0LL){
			if(div % b == 0LL){
				ans.insert(div);
			}

			ll o = a / div;

			if(o % b == 0LL){
				ans.insert(o);
			}
		}
	}

	for(ll a: ans){
		printf("%lld ", a);
	}

	printf("\n");

	return 0;
}