#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10, K = 51;
int dp[N][K];
bool used[N][K];
int n, k;
int cap[N];

int solve(int i, int c){
	if(i == n){
		return 0;
	}
	
	int &ans = dp[i][c];
	bool &us = used[i][c];
	
	if(us){
		return ans;
	}
	
	us = true;
	
	for(int k = i + 1; k < n ; k++){
		int cost = abs(cap[i] - cap[k]);
		
		if(cost <= c){
			ans = max(ans, 1 + solve(k, c - cost));
		}
		
		if(cost == 0)	
			break;
	}
	
	return ans;
}

int main (){
	scanf("%d %d", &n, &k);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &cap[i]);
	}
	
	printf("%d\n", 1 + solve(0, k));
	
	return 0;
}
