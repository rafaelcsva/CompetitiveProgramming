#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = 300, K = 40;
ll dp[N][K][4], used[N][K][4], inf = (ll) 1e14;
int test, n, k;
string s;
string chef = "chef";

ll solve(int i, int j, int d){
	if(j < 0LL){
		return inf;
	}
	
	if(i == n){
	
		if(j == 0){
			return 0;
		}
		
		return inf;
	}
	
	ll &ans = dp[i][j][d];
	
	if(used[i][j][d] == test){
		return ans;
	}
	
	if(s[i] == chef[d]){
		if(d == 3){
			ans = min(solve(i + 1, j - 1, d), solve(i + 1, j - 1, d) + 1LL);
		}else{
			ans = min(solve(i + 1, j, d + 1), solve(i + 1, j, d) + 1LL);
		} 
	}else{
		ans = solve(i + 1, j, d);
	}
	
	return ans;
}

int main (){
	int t;
	
	cin >> t;
	
	for(test = 1 ; test <= t ; test++){
		
		cin >> n >> k;
		
		cin >> s;
		
		ll r = solve(0, k, 0);
		
		if(r >= inf){
			cout << "-1\n";
		}else{
			cout << r << '\n';
		}
	}

	return 0;
}
