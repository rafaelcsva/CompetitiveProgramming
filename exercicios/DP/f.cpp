#include <bits/stdc++.h>

using namespace std;

#define MAXIMO	1010

int n;
int cards[MAXIMO];
int dp[MAXIMO][MAXIMO];

int solve(int i , int j){

	if(i > j)
		return 0;
	
	if(i == j)
		return cards[i];

	if(dp[i][j] != -1)
		return dp[i][j];

	int a, b;

	if(cards[i+1] >= cards[j]){
		a = cards[i]+solve(i+2, j); 
	}else{
		a = cards[i] + solve(i+1, j-1);
	}

	if(cards[j-1] > cards[i]){
		b = cards[j] + solve(i, j-2);
	}else{
		b = cards[j] + solve(i+1, j-1);
	}

	return dp[i][j] = max(a,b);
}

int main (){
	int m = 0;

	while(scanf("%d", &n)&&n){
		m++;
		int total = 0;

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &cards[i]);
			total += cards[i];
		}
		
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ;j < n ; j++)
				dp[i][j] = -1;

		int opt = solve(0, n-1);
 
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", m, opt-(total-opt)); 
	}	
	
	return 0;
}
