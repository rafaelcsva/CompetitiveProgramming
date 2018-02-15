#include <bits/stdc++.h>

using namespace std;

typedef long long int	ll;
const int N = (int) 1e4 + 10;
ll u[N], v[N], inf = (ll) 1e18;
ll dp[N][N];
string s;

ll cost(ll i, ll j){
    if(i > 0 && j > 0){
        return (u[i] + j) ^ (v[j] + i);
    }else{
        return 0;
    } 
}

void solve(int i, int j){
    if(i == 1 && j == 1){
        return;
    }
    
    if(dp[i][j] == dp[i - 1][j] + cost(i, j)){
        s += "D";
        solve(i - 1, j);
    }else{
        s += "R";
        solve(i, j - 1);
    }
}

int main() {
    int n, m;
    
   // ios::sync_with_stdio(false);
    
    cin >> n >> m;
    
    for(int i = 1 ; i <= n ; i++){
        cin >> u[i];
    }
    
    for(int i = 1 ; i <= m ; i++){
        cin >> v[i];
    }
    
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = inf;
    }
    
    for(int j = 0 ; j <= m ; j++){
    	dp[0][j] = inf;
    }
    
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= m ; j++){
            ll a, b;
            
            if(i == 1 && j == 1){
            	a = 0;
            	b = 0;
            }else{
            	a = dp[i - 1][j];
            	b = dp[i][j - 1];
            }
    		
	    
            dp[i][j] = min(a + cost(i, j), b + cost(i, j));
        }
    }
    
    int i = n, j = m;
    
    while(i != 1 || j != 1){
    	if(dp[i][j] == dp[i - 1][j] + cost(i, j)){
    		s += "D";
    		i--;
    	}else{
    		s += "R";
    		j--;
    	}
    }	
    
    reverse(s.begin(), s.end());
    
    cout << s << '\n';
    
    return 0;
}
