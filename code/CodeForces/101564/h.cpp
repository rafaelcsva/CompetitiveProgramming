#include <bits/stdc++.h>

using namespace std;

const int N = 30;
const int M = int(2e2 + 10);
char c[N];
int mp[M];
int dp[M][M][N];
pair< int, char > tab[N][N];
char s[M];
const int inf = 1e9;

int main(){
	int n;
	bool print = false;


	while(scanf("%d", &n) != EOF){
		if(n == 0) break;

		if(print){
			printf("\n");
		}

		print = true;

		for(int i = 0 ; i < n ; i++){
			scanf("\n%c", &c[i]);
			mp[c[i] - 'a'] = i;
		}

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				int u;
				char d;

				scanf("\n%d-%c", &u, &d);

				tab[i][j] = {u, d};
			}
		}

		int np;

		scanf("%d", &np);

		for(int i = 0 ; i < np ; i++){
			scanf("\n%s", s);

			int e = strlen(s);
			// printf("e: %d\n", e);

			for(int i = 0 ; i < e ; i++){
				for(int j = i ; j < e ; j++){
					for(int k = 0 ; k < n ; k++){
						dp[i][j][k] = inf;
					}
				}
			}

			for(int k = 0 ; k < e ; k++){
				dp[k][k][mp[s[k] - 'a']] = 0;
			}

			for(int len = 2 ; len <= e ; len++){
				for(int i = 0 ; i <= e - len ; i++){
					for(int k = i ; k < i + len - 1; k++){
						for(int k1 = 0 ; k1 < n ; k1++){
							for(int k2 = 0 ; k2 < n ; k2++){
								int cost = tab[k1][k2].first;
								int ver = mp[tab[k1][k2].second - 'a'];
								// printf("ver = %d\n", ver);

								dp[i][i + len - 1][ver] = min(dp[i][i + len - 1][ver], cost + dp[i][k][k1] + dp[k + 1][i + len - 1][k2]);
								// printf("%d (%d, %d, %d) (%d, %d)\n", dp[i][i + len - 1][ver], i, i + len - 1, ver, k1, k2);
							}
						}
					}
				}
			}

			int best = inf;
			char resp = 'z';

			for(int k = 0 ; k < n ; k++){
				if(dp[0][e - 1][k] < best){
					best = dp[0][e - 1][k];
					resp = c[k];
				}
			}

			printf("%d-%c\n", best, resp);
		}
	}

	return 0;
}