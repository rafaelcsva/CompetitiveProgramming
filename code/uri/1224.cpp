#include <bits/stdc++.h>

using namespace std;

const int N = int(1e4) + 10;

typedef long long	ll;

ll a[N];

int test = 1;
ll dp[3][N];

int main(){
	int n;

	while(scanf("%d", &n) != EOF){
		for(int i = 0 ; i < n ; i++) scanf("%lld", &a[i]);	

		for(int i = n - 1 ; i >= 0 ; i--){
			int l = i % 3;	
			int l1 = l + 1;
			int l2 = l + 2;

			if(l1 >= 3){
				l1 -= 3;
			}

			if(l2 >= 3){
				l2 -= 3;
			}

			for(int j = i + 1 ; j < n ; j++){
				if(j - i == 1){
					dp[l][j] = max(a[i], a[j]);
				}else{
					dp[l][j] = a[i] + min(dp[l1][j - 1], dp[l2][j]);
					dp[l][j] = max(dp[l][j], a[j] + min(dp[l1][j - 1], dp[l][j - 2]));
				}
			}
		}

		printf("%lld\n", dp[0][n - 1]);
	}

	return 0;
}