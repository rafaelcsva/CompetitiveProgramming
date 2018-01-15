#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;

const int N = 5010, mod = (int) 1e9 + 7;
int dp[N][N];
char com[N];

int main (){
	int n;

	scanf("%d", &n);		

	for(int i = 0 ; i < n ; i++){
		scanf("\n%c", &com[i]);
	}

	dp[0][0] = 1;

	for(int i = 0 ; i < n ; i++){
		if(com[i] == 'f'){
			for(int j = 1 ; j < n ; j++){
				dp[i + 1][j] = dp[i][j - 1] % mod;
			} 
		}else{
			for(int j = 0 ; j <= i ; j++){
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
			}
		}
	}

	int ans = 0;

	for(int i = 0 ; i < n ; i++){
		ans = dp[n - 1][i] % mod + ans;
	}

	printf("%d\n", ans);

	return 0;
}
