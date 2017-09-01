#include <bits/stdc++.h>

#define	MAXIMO	1010

using namespace std;

int dp[MAXIMO][MAXIMO];

string s1, s2;

int max(int a, int b){
	return a>b ? a : b;
}

int solve(int i, int j){
	if(i >= s1.length() || j >= s2.length())
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	if(s1[i] == s2[j]){
		return dp[i][j] = 1 + solve(i+1, j+1);
	}
	
	return dp[i][j] = max(solve(i, j+1), solve(i+1, j));
}

int main (){

	while(getline(cin,s1)){
		getline(cin,s2);
		int max = s1.length() > s2.length() ? s1.length() : s2.length();

		for(int i = 0 ; i < 1000 ; i++)
			for(int j = 0 ; j < 1000 ; j++)
				dp[i][j] = -1;
				
		
		printf("%d\n", solve(0, 0));			
	}
	
	return 0;
}
