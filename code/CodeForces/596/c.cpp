#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 2010;
ll dp1[N][N], dp2[N][N];
ll sufc[N][N];
ll sufl[N][N];
ll bit1[N][N];
ll bit2[N][N];
const ll mod = ll(1e9) + 7;
char tab[N][N];

int LSOne(int x){
	return x & (-x);
}

void update(int x, ll bit[], ll val){
	while(x < N){
		bit[x] += val;

		if(bit[x] >= mod){
			bit[x] -= mod;
		}

		x += LSOne(x);
	}
}

ll query(int x, ll bit[]){
	ll sum = 0LL;

	while(x > 0){
		sum += bit[x];
		
		if(sum >= mod){
			sum -= mod;
		}

		x -= LSOne(x);
	}

	return sum;
}

ll rsq(int l, int r, ll bit[]){
	return query(r, bit) - query(l - 1, bit);
}

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			scanf("\n%c", &tab[i][j]);
		}
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = m ; j >= 1 ; j--){
			sufc[i][j] += ((tab[i][j] == 'R') + sufc[i][j + 1]);
			// printf("%d, %d = %d\n", i, j, sufc[i][j]);
		}
	}

	for(int j = 1 ; j <= m ; j++){
		for(int i = n ; i >= 1 ; i--){
			sufl[i][j] += ((tab[i][j] == 'R') + sufl[i + 1][j]);
		}
	}

	if(tab[n][m] == 'R'){
		printf("0\n");
	}else{
		if(n == 1 && m == 1){
			printf("1\n");
			return 0;
		}

		dp1[n][m] = dp2[n][m] = 1LL;

		update(m, bit1[n], 1LL);
		update(n, bit2[m], 1LL);
		// printf("%d, %d\n", n, m);

		for(int i = n ; i >= 1 ; i--){
			for(int j = m ; j >= 1 ; j--){
				if(i == n && j == m){
					continue;
				}

				int r = sufc[i][j + 1];

				dp2[i][j] = rsq(j, m - r, bit1[i]);

				r = sufl[i + 1][j];

				dp1[i][j] = rsq(i, n - r, bit2[j]);

				update(i, bit2[j], dp2[i][j]);
				update(j, bit1[i], dp1[i][j]);

				// printf("1.%d, %d (%lld)\n", i, j, dp1[i][j]);
				// printf("2.%d, %d (%lld)\n", i, j, dp2[i][j]);
			}
		}

		printf("%lld\n", (dp1[1][1] + dp2[1][1]) % mod);
	}

	return 0;
}