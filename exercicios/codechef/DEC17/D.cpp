#include <bits/stdc++.h>

#define INF	(int) 1e9
using namespace std;

const int N = 110;
int x, y, z, a, b, c;
int used[N][N][N], dp[N][N][N];
int t;

int solve(int i, int j, int k){
	if(i > x || j > y || k > z)
		return dp[i][j][k] = INF;

	if(i == x && j == y && k == z)
		return 0;

	int &ans = dp[i][j][k];

	
	if(used[i][j][k] == t){
		return ans;
	}
	
	used[i][j][k] = t;
	ans = INF;


	ans = min(ans, a + solve(i + 1, j, k));
	ans = min(ans, a + solve(i, j + 1, k));
	ans = min(ans, a + solve(i, j, k + 1));
	
	ans = min(ans, b + solve(i + 1, j + 1, k));
	ans = min(ans, b + solve(i + 1, j, k + 1));
	ans = min(ans, b + solve(i, j + 1, k + 1));

	ans = min(ans, c + solve(i + 1, j + 1, k + 1));

	return ans;	
}

int A, B, C;

void printDP(int i, int j, int k){
	printf("%d %d %d\n", i, j, k);
	if(i == x && j == y && k == z){
		
		printf("A = %d\nB = %d\nC = %d\n", A, B, C);
		return;
	}

	int &ans = dp[i][j][k];

	if(ans == a + dp[i + 1][j][k]){
		A++;
		printDP(i + 1, j, k);
		
	}else if(ans == a + dp[i][j + 1][k]){
		A++;
		printDP(i, j + 1, k);
		
	}else if(ans == a + dp[i][j][k + 1]){
		A++;
		printDP(i, j, k + 1);
		
	}else if(ans == b + dp[i + 1][j + 1][k]){
		B++;
		printDP(i + 1, j + 1, k);
	}else if(ans == b + dp[i + 1][j][k + 1]){
		B++;
		printDP(i + 1, j, k + 1);
	}else if(ans == b + dp[i][j + 1][k + 1]){
		B++;
		printDP(i, j + 1, k + 1);
	}else if(ans == c + dp[i + 1][j + 1][k + 1]){
		C++;
		printDP(i + 1, j + 1, k + 1);
	}
	
}

int main (){
	int T;
	cin >> T;

	for(t = 1 ; t <= T ; t++){

		cin >> x >> y >> z >> a >> b >> c;

		cout << solve(0, 0, 0) << '\n';
		printDP(0, 0, 0);
	}

	return 0;
}
