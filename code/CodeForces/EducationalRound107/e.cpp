#include <bits/stdc++.h>
 
using namespace std;
 
 
typedef long long	ll;
 
const int N = int(3e5) + 10;
const ll mod = 998244353LL;
 
string s[N];
ll w;
ll dp[N][2];
 
ll fast_expo(ll x, ll e, ll mod){
	ll r = 1LL;
	ll b = x;
	
	while(e){
		if(e & 1LL){
			r = (r * b) % mod;
		}
		
		e >>= 1LL;
		b = (b * b) % mod;
	}
	
	return r;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, m;
	
	cin >> n >> m;
 
	for(int i = 0; i < n ; i++){
		cin >> s[i];
 
		for(int j = 0 ; j < m ; j++){
			w += ll(s[i][j] == 'o');
		}
	}
 
	ll ans = 0LL;
 
	for(int i = 0 ; i < n ; i++){
		ll tw = w;
		dp[0][0] = 1LL;
		dp[0][1] = (s[i][0] == 'o');
		tw -= (s[i][0] == 'o');
		
		//printf("%c\n", s[i][0]);
 
		for(int j = 1 ; j < m ; j++){
			dp[j][0] = (dp[j - 1][0] + dp[j - 1][1]) % mod;
 
			if(s[i][j] == 'o'){
				tw--;

				dp[j][1] = dp[j - 1][0];

				dp[j][0] = (dp[j][0] + dp[j - 1][1]) % mod;
 
				ans = (ans + dp[j - 1][1] * fast_expo(2LL, tw, mod)) % mod;
			}else{
				dp[j][1] = 0;
			}
		}
	}

	for(int i = 0 ; i < m ; i++){
		ll tw = w;
		dp[0][0] = 1LL;
		dp[0][1] = (s[0][i] == 'o');
		tw -= (s[0][i] == 'o');

		for(int j = 1 ; j < n ; j++){
			dp[j][0] = (dp[j - 1][0] + dp[j - 1][1]) % mod;
 
			if(s[j][i] == 'o'){
				tw--;
				
				dp[j][1] = dp[j - 1][0];
				
				dp[j][0] = (dp[j][0] + dp[j - 1][1]) % mod;
 
				ans = (ans + dp[j - 1][1] * fast_expo(2LL, tw, mod)) % mod;
			}else{
				dp[j][1] = 0;
			}
		}
	}
	
	cout << ans << endl;
 
	return 0;
}
