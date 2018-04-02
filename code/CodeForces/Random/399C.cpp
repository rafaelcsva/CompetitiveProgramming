#include <bits/stdc++.h>

using namespace std;

const int N = 11, I = 1001, D = 11;
bool dp[N][N][I][D];
bool used[N][N][I][D];
int n;
string s;

bool solve(int la, int lb, int i, int d){
	if(i == n){
		return dp[la][lb][i][d] = true;
	}

	if(used[la][lb][i][d]){
		return dp[la][lb][i][d];
	}

	used[la][lb][i][d] = true;
	bool &ans = dp[la][lb][i][d];
	
	if(i == 0){
		for(int k = 1 ; k < D ; k++){
			if(s[k - 1] == '0')
				continue;

			ans = ans || solve(la + k, lb, i + 1, k);
		}
	}
	else if(i % 2){
		if(la <= lb){
			return false;
		}

		for(int k = 1; k < D ; k++){
			if(k == d || s[k - 1] == '0' || lb + k <= la){
				continue;
			}
			
			ans = ans || solve(0, lb + k - la, i + 1, k);
		}
	}else{
		if(lb <= la){
			return false;
		}
		
		for(int k = 1 ; k < D ; k++){
			if(k == d || s[k - 1] == '0' || la + k <= lb){
				continue;
			}
	
			ans = ans || solve(la + k - lb, 0, i + 1, k);
		}
	}
		
	return ans;
}

void printDP(int la, int lb, int i, int d){
	if(i == 0){
		for(int k = 1 ; k < D ; k++){
			if(dp[la + k][lb][i + 1][k]){
				printf("%d", k);
				printDP(la + k, lb, i + 1, k);
				break;
			}
		}
	}else if(i % 2){
		for(int k = 1 ; k < D ; k++){
			if(lb + k <= la || k == d){
				continue;
			}

			if(dp[0][lb + k - la][i + 1][k]){
				printf(" %d", k);
				printDP(0, lb + k - la, i + 1, k);
				break;
			}
		}
	}else{
		for(int k = 1 ; k < D ; k++){
			if(la + k <= lb || k == d)
				continue;

			if(dp[la + k - lb][0][i + 1][k]){
				printf(" %d", k);
				printDP(la + k - lb, 0, i + 1, k);
				break;
			}
		}
	}
}

int main (){

	cin >> s;

	cin >> n;

	if(solve(0, 0, 0, 0)){
		cout << "YES\n";
		printDP(0, 0, 0, 0);
		printf("\n");
	}else{
		cout << "NO\n";
	}

	return 0;
}
