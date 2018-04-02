#include <bits/stdc++.h>

using namespace std;

vector<int>moedas;
int dp[1010];
int used[1010];
int d = 1;

int solve(int m){
	if(m < 0){
		return 0;
	}

	if(m == 0)
		return 1;

	if(used[m] == d)
		return dp[m];

	used[m] = d;

	for(int i = 0 ; i < moedas.size() ; i++){
		if(solve(m-moedas[i])){
			return dp[m] = 1;
		}
	}


	return dp[m] = 0;
}

int main (){
	int n, m;

	scanf("%d%d", &n, &m);

	memset(dp, -1, sizeof(dp));
	
	for(int i = 0 ; i < n ; i++){
		int c;

		scanf("%d", &c);

		moedas.push_back(c);
	}
	
	int cont = 0;

	for(int i = 1 ; i < m ; i++){
		cont += solve(i);
		d++;
	}
	//cont = 0;

/*	for(int i = 0 ; i <= m ; i++){
		if(dp[i] == 0 || dp[i] == -1){
			cont++;
		}
	}*/
	printf("%d\n",m-cont-1);

	return 0;
}
