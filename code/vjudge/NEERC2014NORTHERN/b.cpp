#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

typedef pair< ll, int >	pll;
const int N = int(1e5 + 10);
ll pref1[N], pref2[N];
pll a[N], b[N];

int main(){
	freopen("buffcraft.in", "r", stdin);
	freopen("buffcraft.out", "w", stdout);

	ll num = ll(5e4);

	// printf("%lld\n", num * (num + 1LL) * num * (num + 1LL));

	int k, cd, cp;
	ll be;

	scanf("%lld %d %d %d", &be, &k, &cd, &cp);

	for(int i = 1 ; i <= cd ; i++){
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}

	for(int i = 1 ; i <= cp ; i++){
		scanf("%lld", &b[i].first);
		b[i].second = i;
	}

	sort(a + 1, a + 1 + cd, greater< pll >());
	sort(b + 1, b + 1 + cp, greater< pll >());

	if(cd + cp <= k){
		printf("%d %d\n", cd, cp);

		for(int i = 1 ; i <= cd ; i++){
			printf("%d ", i);
		}
		if(cd)
			printf("\n");
		for(int i = 1 ; i <= cp ; i++){
			printf("%d ", i);
		}

		if(cp)
			printf("\n");

		return 0;
	}else{
		pref1[0] = be;
		pref2[0] = 100L;

		for(int i = 1 ; i <= cd ; i++){
			pref1[i] += pref1[i - 1] + a[i].first;
		}

		for(int i = 1 ; i <= cp ; i++){
			pref2[i] += pref2[i - 1] + b[i].first;
		}

		ll ans = 0LL;
		int ptans1 = 0;
		int ptans2 = 0;

		for(int i = 0 ; i <= min(cd, k) ; i++){
			if(k - i > cp){
				continue;
			}

			if(pref1[i] * pref2[k - i] > ans){
				ptans1 = i;
				ptans2 = k - i;
				ans = pref1[i] * pref2[k - i];
			}
		}

		printf("%d %d\n", ptans1, ptans2);

		for(int i = 1 ; i <= ptans1 ; i++){
			printf("%d ", a[i].second);
		}

		if(ptans1)
			printf("\n");

		for(int i = 1 ; i <= ptans2 ; i++){
			printf("%d ", b[i].second);
		}

		if(ptans2)
			printf("\n");
	}

	return 0;
}