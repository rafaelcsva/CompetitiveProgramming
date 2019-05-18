#include <bits/stdc++.h>

using namespace std;

typedef long long 	ll;
typedef pair< ll, ll >	pll;

const int N = 500;
int n;
pll p[N];

bool works(pll r){
	ll last = -1LL;

	for(int i = 0 ; i < n ; i++){
		ll val = p[i].first * r.first + p[i].second * r.second;

		if(last >= val){
			return false;
		}

		last = val;
	}

	return true;
}

bool can(){
	int var = 0;
	bool ok = true;

	for(ll k = 1LL ; k <= 100 ; k++){
		for(ll k2 = 1LL ; k2 <= 100 ; k2++){
			if(works({k, k2})){
				return true;
			}
		}
	}
	// for(int i = 0 ; i < n ; i++){
	// 	printf("%lld, %lld\n", p[i].first, p[i].second);
	// }
	// printf("aqui %d\n", var);

	return false;
}

int main(){
	int t;

	scanf("%d", &t);
	int test = 1;

	while(t--){
		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			scanf("%lld %lld", &p[i].first, &p[i].second);
		}

		sort(p, p + n);

		int perm = 0;

		do{
			if(can()){
				perm++;
			}
		}while(next_permutation(p, p + n));
		
		printf("Case #%d: %d\n", test++, perm);
	}

	return 0;
}