#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 510;
const ll mod = ll(1e9) + 7LL;
ll comb[N][N];
ll fat[N];
int test = 1;

int main(){
	int t;

	comb[0][0] = 1LL;
	fat[0] = 1LL;

	for(int i = 1 ; i < N ; i++){
		fat[i] = ll(i) * fat[i - 1];
		fat[i] %= mod;

		comb[i][0] = comb[i][i] = 1LL;

		for(int j = 1 ; j < i ; j++){
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];

			if(comb[i][j] >= mod){
				comb[i][j] -= mod;
			}
		}
	}

	scanf("%d", &t);

	while(t--){
		int n, k, p;

		scanf("%d %d %d", &n, &k, &p);

		ll ans = 0LL;

		for(int i = k + 1 ; i <= n ; i++){
			for(int d = p + 1 ; d <= n ; d++){
				ll tmp = comb[d - 2][i - k - 1];
				tmp %= mod;

				tmp *= fat[n - 2 - (i - k - 1)];
				tmp %= mod;

				ans += tmp;

				// printf("adding %lld\n", tmp);

				if(ans >= mod){
					ans -= mod;
				}
			}
		}

		ll tmp = (comb[p - 1][n - k] * fat[k - 1]) % mod;
		
		ans += tmp;

		if(ans >= mod){
			ans -= mod;
		}

		printf("Case #%d: %lld\n", test++, ans);
	}

	return 0;
}