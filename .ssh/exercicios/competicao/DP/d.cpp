#include <bits/stdc++.h>

using namespace std;
int n, k;
int dp[38][38];
int s[40];

int solve(int pos, int soma, int proximo){
	if(soma < 0){
		return 0;
	}

	if(pos == 2*n){
		if(soma == 0)
			return 1;
		return 0;
	}

	if(dp[pos][soma]!=-1){
		return dp[pos][soma];
	}

	if(s[pos]){
		return dp[pos][soma] = solve(pos+1, soma+1, proximo-1);
	}
	return dp[pos][soma] = solve(pos+1, soma+1, proximo) + solve(pos+1, soma-1, proximo);
}
	
int main (){
	int d;

	scanf("%d", &d);

	for(int i = 0 ; i < d ; i++){
		scanf("%d%d", &n, &k);

		for(int j = 0 ; j <= 40 ; j++)
			s[j] = 0;

		for(int j = 0 ; j < 38 ; j++)
			for(int k = 0; k < 38 ; k++)
				dp[j][k] = -1;

		int m;

		for(int j = 0 ; j < k ; j++){
			scanf("%d", &m);
			s[m-1] = 1;
		}

		printf("%d\n", solve(0, 0, k-1));
	}

	return 0;	
}
