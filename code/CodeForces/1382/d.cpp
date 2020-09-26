#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
bool dp[2][N];
int a[N * 2];
vector< int > v;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < 2 * n ; i++){
			scanf("%d", &a[i]);
		}

		int i = 0;

		while(i < 2 * n){
			int j = i + 1;

			while(j < 2 * n && a[j] < a[i]){
				j++;
			}

			v.push_back(j - i);
			i = j;
		}

		dp[0][0] = true;
		int k = 1;

		for(auto u: v){
			// printf("%d ", u);
			for(int m = 0 ; m <= n ; m++){
				dp[k][m] = (dp[!k][m]);

				if(u <= m){
					dp[k][m] |= dp[!k][m - u];
				}
			}

			k = !k;
		}

		// printf("\n");

		if(dp[0][n]){
			printf("YES\n");
		}else{
			printf("NO\n");
		}

		memset(dp, false, sizeof dp);

		v.clear();
	}

	return 0;
}