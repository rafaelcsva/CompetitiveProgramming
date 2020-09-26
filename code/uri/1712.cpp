#include <bits/stdc++.h>

using namespace std;

const int N = 52;
int dp[N][N][11];
int a[N][N];

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 4 ; j++){
			scanf("%d", &a[i][j]);
		}
	}

	int ans = 0;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			dp[i][j][1] = a[i][j];
			ans = max(ans, dp[i][j][1]);

			for(int k = 2 ; k <= m ; k++){
				if(i - 1 >= 0){
					dp[i][j][k] = a[i][j] + dp[i - 1][j][k - 1];
				}

				if(j - 1 >= 0){
					dp[i][j][k] = max(dp[i][j][k], a[i][j] + dp[i][j - 1][k - 1]);
				}

				ans = max(ans, dp[i][j][k]);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}