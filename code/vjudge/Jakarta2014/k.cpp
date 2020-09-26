#include <bits/stdc++.h>

using namespace std;

const int mod = 997;
const int N = int(100) + 10;
const int M = int(1e6) + 10;
int dp[N][N];
int fat[2 * M];
int pascal[mod + 1][mod + 1];

int fast_expo(int x, int e){
	int r = 1;
	int b = x;

	while(e){
		if(e & 1){
			r = (r * b) % mod;
		}

		e >>= 1;
		b = (b * b) % mod;
	}

	return r;
}

int comb(int m, int n){
	int r = 1;

	while(m && n){
		int t1 = m % mod;
		int t2 = n % mod;

		r *= pascal[t1][t2];
		r %= mod;

		m /= mod;
		n /= mod;
	}

	return r;
}

vector< pair< int, int > > v;

bool ok(int i, int j){
	return v[i].first <= v[j].first && v[i].second <= v[j].second;
}

int calc(int i, int j){
	int l = v[j].first - v[i].first + 1;
	int c = v[j].second - v[i].second + 1;

	return comb(l + c - 2, l - 1);
}

int main(){
	pascal[0][0] = 1;

	for(int i = 1 ; i <= mod ; i++){
		pascal[i][0] = pascal[i][i] = 1;

		for(int j = 1 ; j < i ; j++){
			pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];

			if(pascal[i][j] >= mod){
				pascal[i][j] -= mod;
			}
		}
	}

	int test = 1;
		
	int t;

	scanf("%d", &t);

	while(t--){

		int n, m, k;

		scanf("%d %d %d", &n, &m, &k);

		v.push_back({1, 1});
		v.push_back({n, m});

		for(int i = 0 ; i < k ; i++){
			int ri, ci;

			scanf("%d %d", &ri, &ci);

			for(int k = -1 ; k <= 1 ; k++){
				for(int l = -1 ; l <= 1 ; l++){
					v.push_back({ri + k, ci + l});
				}
			}
		}

		sort(v.begin(), v.end());
		k = v.size();

		for(int t = 1 ; t < k ; t++){
			for(int i = 0 ; i < k - t ; i++){
				int j = i + t;

				if(ok(i, j)){
					int tot = calc(i, j);

					for(int k = i + 1 ; k < j ; k++){
						if(ok(i, k) && ok(k, j)){
							int tmp = (dp[i][k] * calc(k, j)) % mod;
							
							tot -= tmp;

							if(tot < 0){
								tot += mod;
							}
						}
					}

					dp[i][j] = tot;
				}else{
					dp[i][j] = 0;
				}
			}
		}

		printf("Case #%d: %d\n", test++, dp[0][k - 1]);

		v.clear();
	}

	return 0;
}