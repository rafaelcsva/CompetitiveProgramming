#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;

const int N = 20;
int dp[N][2], used[N][2];
int v[N];
lli d = 0LL;

int solve(int i, int b){
	if(i == d){
		return 0;
	}
	
	int &ans = dp[i][b];
	
	if(used[i][b]){
		return ans;
	}
	
	used[i][b] = 1;
	
	if(b){
		ans = solve(i + 1, b) + 9;
	}else{
		for(int k = v[i] ; k >= 0 ; k--){
			ans = max(ans, solve(i + 1, k < v[i]) + k);
		}
	}
	
	return ans;
}

int main (){
	lli n;
	
	cin >> n;
	
	lli num = 0LL;
	lli pot = 10LL;
	lli tmp = n;
		
	while(tmp){
		v[d] = tmp % 10;
		tmp /= 10LL;
		d++;
	}
	
	reverse(v, v + d);
	
	cout << solve(0, 0) << '\n';
	
	return 0;
}
