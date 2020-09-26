#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int dp[N][2];
int a[N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}

		for(int i = n - 1 ; i >= 0 ; i--){
			for(int j = 0 ; j < 2 ; j++){
				dp[i][j] = min(dp[i + 1][!j] + (j * a[i]), dp[i + 2][!j] + j * (a[i] + a[i + 1]));
			}
		}

		printf("%d\n", dp[0][1]);

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < 2 ; j++){
				dp[i][j] = 0;
			}
		}
	}

	return 0;
}