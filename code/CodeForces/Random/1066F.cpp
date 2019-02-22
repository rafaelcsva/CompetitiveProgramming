#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = int(2e5 + 10);
map< ll, ll > nxt;
map< ll, int > up, bt;
ll x[N], y[N];
set< ll > st;
ll dp[N];
bool used[N];

ll solve(int i){
	ll e = max(x[i], y[i]);
	
	if(nxt[e] == 0){
		return 0LL;
	}
	
	ll u = nxt[e];
	ll &ans = dp[i];
	
	if(used[i]){
		return ans;
	}
	
	used[i] = true;
	ll dis1 = 0LL, dis2 = 0LL;
	
	ll dis = abs(x[up[u]] - x[bt[u]]) + abs(y[up[u]] - y[bt[u]]);
	dis1 = abs(x[i] - x[bt[u]]) + abs(y[i] - y[bt[u]]) + dis;
	dis2 = abs(x[i] - x[up[u]]) + abs(y[i] - y[up[u]]) + dis;
	
	ans = min(dis1 + solve(up[u]), dis2 + solve(bt[u]));
	
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;

	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> x[i] >> y[i];
		
		st.insert(max(x[i], y[i]));
	}
	
	ll cur = 0LL;
	
	for(set< ll >::iterator it = st.begin() ; it != st.end() ; it++){
		nxt[cur] = *it;
		cur = *it;
	}
	
	for(int i = 0 ; i < n ; i++){
		ll r = max(x[i], y[i]);
		
		if(up.count(r) == 0){
			up[r] = i;
		}else{
			if(x[up[r]] > x[i] || y[up[r]] < y[i]){
				up[r] = i;
			}
		}
		
		if(bt.count(r) == 0){
			bt[r] = i;
		}else{
			if(x[bt[r]] < x[i] || y[bt[r]] > y[i]){
				bt[r] = i;
			}
		}
	}
    // cout << " to aqui!\n";
	int u = nxt[0];
	ll ans;
	ll dis = abs(x[up[u]] - x[bt[u]]) + abs(y[up[u]] - y[bt[u]]), dis1, dis2;
	// cout << bt[u] << " " << up[u] << " " << nxt[nxt[nxt[u]]] << endl;
	dis1 = x[bt[u]] + y[bt[u]] + dis;
	dis2 = x[up[u]] + y[up[u]] + dis;
	
	ans = min(dis1 + solve(up[u]), dis2 + solve(bt[u]));
	
	cout << ans << endl;
	
	return 0;
}