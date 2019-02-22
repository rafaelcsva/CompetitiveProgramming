#include <bits/stdc++.h>

using namespace std;

const int N = 2010, T = 2010;
long double dp[N][T];
bool used[N][T];
int n, t;
long double p;

long double solve(int i, int s){
	if(i > n){
		return n;
	}

	if(s == t){
		
		return (long double)i;
	}
	
	long double &ans = dp[i][s];
	
	if(used[i][s]){
		return ans;
	}
	
	used[i][s] = 1;
	
	long double ds = 1.0 - p;
	
	ans = p * solve(i + 1, s + 1) + (ds) * (solve(i, s + 1));

	return ans;
}

int main (){
	cin >> n >> p >> t;
	
	cout << fixed << setprecision(10) << solve(0, 0) << '\n';
	
	return 0;	
}
