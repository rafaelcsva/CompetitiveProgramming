//14, 04, 2018, 11:12:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int p, q, c, m;
map<pii, int>mp;
const int N = int(2e3 + 100);
ll dp[N][N], used[N][N];
ll mod = ll(1e9 + 7);

ll solve(int g, int b){
    if(mp[{g, b}] != 0){
        return 0LL;
    }

    if(g > p || b > q){
        return 0LL;
    }
    
    if(g == p && b == q){
        return 1LL;
    }

    if(used[g][b]){
        return dp[g][b];
    }

    used[g][b] = 1;

    if(g - b > c){
        dp[g][b] += solve(g, b + 1);
    }

    dp[g][b] += solve(g + 1, b);

    return dp[g][b] % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> p >> q >> c >> m;
    
    for(int i = 0 ; i < m ; i++){
        int u, v;

        cin >> u >> v;

        mp[{u, v}] = 1;
    }

    cout << solve(0, 0) << endl;

    return 0;
}