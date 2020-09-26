#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int K = 1010;

typedef long long	ll;

ll dp[N][K];
const ll mod = ll(1e9) +7LL;

int main(){
	int t;
	int test = 1;

	scanf("%d", &t);

	while(t--){
		int n, k;

		ll qtd = 0;

		scanf("%d %d", &n, &k);

		for(int i = 0 ; i < n ; i++){
			ll x;

			scanf("%lld", &x);
			
			qtd += x;
		}

		dp[0][0] = 1LL;

		for(int j = 1 ; j <= k ; j++){
			for(int i = 0 ; i <= n ; i++){
				ll q0 = ll(n - i);
				dp[i][j] = 0LL;

				if(i != n)
					dp[i][j] = dp[i + 1][j - 1] * q0;

				if(i != 0){
					dp[i][j] += ll(i) * dp[i - 1][j - 1];
				}

				dp[i][j] %= mod;
			}
		}

		printf("Case #%d: %lld\n", test++, dp[qtd][k]);
	}

	return 0;
}