#include <bits/stdc++.h>

#define MAXIMO	100

using namespace std;

int main (){
	int n;
	int dp[MAXIMO][2];
	int pies[MAXIMO];
	int total = 0;
	
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &pies[i]);
		total+=pies[i];
	}

	dp[n-1][1] = pies[n-1];
	dp[n-1][0] = 0;

	for(int i = n-2 ; i >= 0 ; i--){
		dp[i][1] = max(dp[i+1][0] + pies[i], dp[i+1][1]);
		dp[i][0] = min(dp[i+1][1] , pies[i] + dp[i+1][0]); 
	}	

	printf("%d %d\n", total-dp[0][1], dp[0][1]);
			
	return 0;
}
