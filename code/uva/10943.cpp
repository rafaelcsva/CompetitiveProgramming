#include <bits/stdc++.h>

using namespace std;

const int mod = (int)1e6, M = 110;
int n, k, q;
int dp[M][M], used[M][M];

int solve(int m, int c){
	
	if(c == k - 1){
		return 1;
	}

	int &ans = dp[m][c];

	if(used[m][c] == q){
		return ans;
	}
	
	ans = 0;
	used[m][c] = q;
		
	for(int i = 0 ; i + m <= n ; i++){
		ans += solve(i + m, c + 1) % mod;
	}
	
	return ans % mod;
}

int main (){
	
	while(scanf("%d%d", &n, &k) != EOF){
		q++;
		
		if(n == 0 && k == 0){
			break;
		}
		
		printf("%d\n", solve(0, 0));
	}

	return 0;
}
