#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = (int)1e6;
const ll inf = (ll) 1e18;
ll h[N], p[N];
map<pair<ll, ll>, ll> dp, used;
int n;

ll solve(ll x, ll cur){
	pair<ll, ll>ii = make_pair(x, cur);
	
	if(x == n){
		return 0LL;
	}

	
	if(used[ii]){
		return dp[ii];
	}
	
	used[ii] = 1LL;
	
	ll h1, h2;
	
	h1 = abs(cur - h[x + 1]);
	
	if(x + 1 == n){
		h1 = 0LL;
	}

	dp[ii] = solve(x + 1LL, h[x + 1]) + 1LL + p[x + 1] + h1;
	
	if(h[x + 1] <= cur){
		dp[ii] = min(dp[ii], solve(x + 1LL, cur) + 1LL);
	}
	
	return dp[ii];
}

int main (){

	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> h[i];
	}	
	
	for(int i = 1 ; i < n ; i++){
		cin >> p[i];
	}

	cout << solve(0LL, p[0]) << '\n';

	return 0;
}
