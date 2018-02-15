#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = 110, S = 400, M = 50;
int n, m, t, coinC[N], coinI[N];
const ll inf = (ll) 1e9;
ll dp[S][S], s, used[S][S];

ll solve(ll c, ll i){
	//cout << c << ' ' << i << ' ' << k << '\n';
	if(s * s == c * c + i * i){
	//	cout << c << ' ' << i << '\n';
		return 0LL;
	}else if(s * s < c * c + i * i){
		return inf;
	}
	
	ll &ans = dp[c][i];
	
	if(used[c][i] == t){
		return ans;
	}
	
	ans = inf;
	used[c][i] = t;
	
	for(int k = 0 ; k < m ; k++){
		ans = min(ans, solve(c + coinC[k], i + coinI[k]) + 1LL);
	}	
	
	return ans;
}

int main (){
	int n;
	
	scanf("%d", &n);
	
	for(t = 1 ; t <= n ; t++){
		scanf("%d%lld", &m, &s);
		
		for(int i = 0 ; i < m ; i++){
			scanf("%d%d", &coinC[i], &coinI[i]);
		}

		ll r = solve(0LL, 0LL);
		
		if(r >= inf){
			printf("not possible\n");
		}else{
			printf("%lld\n", r);
		}
	}

	return 0;
}
