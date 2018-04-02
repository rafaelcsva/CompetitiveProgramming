#include <bits/stdc++.h>

using namespace std;

const int X = 10001, A = 10, inf = (int) 1e7, down = 20, keep = 30, up = 60;
int q, n;
int dp[X][A], used[X][A], str[A][X];

int solve(int x, int a){
	if(a >= A || a < 0){
		return inf;
	}
	
	if(x == n){
		if(a == 0){
			return dp[x][a] = 0;
		}else{
			return dp[x][a] = inf;
		}
	}
	
	int &ans = dp[x][a];
	
	if(used[x][a] == q){
		return ans;
	}
	
	ans = 0;
	used[x][a] = q;
	
	int cost = str[a][x];
	
	ans = min(solve(x + 1, a - 1) + max(down - cost, 0), min(solve(x + 1, a) + max(keep - cost, 0), solve(x + 1, a + 1) + max(up - cost, 0))); 
	ans = max(ans, 0);
	
	return ans;
}

void printDP(int x, int a){
	int cost = str[a][x];
	int d = dp[x][a];
	
	if(x == n){
		return;
	}
	
	if(d == solve(x + 1, a - 1) + max(down - cost, 0)){
		cout << "down in " << x << " with cost " << max(down - cost, 0) << ' ' << "(h = " << a << ")\n";
		printDP(x + 1, a - 1);
	}else if(d == solve(x + 1, a) + max(keep - cost, 0)){
		cout << "keep in " << x << " with cost " << max(keep - cost, 0) << ' ' << "(h = " << a << ") " << cost << '\n';
		printDP(x + 1, a);
	}else{
		cout << "up in " << x << " with cost " << max(up - cost, 0) << ' ' << "(h = " << a << ")\n";
		printDP(x + 1, a + 1);
	}
}

int main (){
	int t;
	
	ios::sync_with_stdio(false);
	
	cin >> t;

	for(q = 1 ; q <= t ; q++){
		cin >> n;
		
		n /= 100;
		
		for(int i = 9 ; i >= 0 ; i--){
			for(int j = 0 ; j < n ; j++){
				cin >> str[i][j];
				
			}
		}
		
		//cout << "*** " << str[1][0] << '\n';
		cout << solve(0, 0) << "\n\n";
		//printDP(0, 0);
	}
	
	return 0;
}
