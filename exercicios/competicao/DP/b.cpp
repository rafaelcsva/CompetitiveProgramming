#include <bits/stdc++.h>

using namespace std;

vector<int>moedas;
int dp[10010][10];

int solve(int x, int j){
	if(j > 10|| x < 0)
		return 0;

	if(x == 0)
		return 1;

	if(dp[x][j] != -1)
		return dp[x][j];

	for(int i = 0 ; i < moedas.size() ; i++){
		if(solve(x-moedas[i], j+1))
			return dp[x][j] = 1;
	}

	return dp[x][j] = 0;
}

int main (){
	int n, m;
		
	scanf("%d%d", &n, &m);

	for(int i = 0 ; i < n ; i++){
		int a;

		scanf("%d", &a);

		moedas.push_back(a);
	}

	for(int i = 0 ; i <= m ; i++)
		for(int j = 0 ; j <= 10 ; j++)
			dp[i][j] = -1;

	if(solve(m, 1))
		printf("S\n");
	else
		printf("N\n");

	return 0;
}
