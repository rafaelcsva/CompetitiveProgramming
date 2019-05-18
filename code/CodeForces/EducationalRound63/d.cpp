#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(3e5 + 100);
bool used[N][2][2];
ll dp[N][2][2];
int n;
ll x;
ll a[N];

ll solve(int i, int flag1, int flag2){
	if(i == n){
		return 0LL;
	}

	ll &ans = dp[i][flag1][flag2];
	bool &us = used[i][flag1][flag2];

	if(us){
		return ans;
	}

	us = true;

	if(flag1){
		ans = max(a[i] * x + solve(i + 1, flag1, flag2), a[i] + solve(i + 1, 0, flag2));
	}else{
		if(flag2 == 0){
			ans = max(a[i] * x + solve(i + 1, 1, 1), a[i] + solve(i + 1, 0, 0));
		}else{
			ans = solve(i + 1, flag1, flag2) + a[i];
		}
	}

	ans = max(ans, 0LL);

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> x;

	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}

	ll best = 0LL;

	for(int i = 0 ; i < n ; i++){
		best = max(best, solve(i, 0, 0));
	}

	cout << best << endl;

	return 0;
}