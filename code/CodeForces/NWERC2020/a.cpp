#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 110;
const int M = 10010;
const ll m = 10009;
ll a[N];
ll dp[N][M];
int n, q;
const ll inf = ll(1e18);

ll solve(int i, int j){
    if(i > n){
        return inf;
    }

    if(j <= n){
        return a[j];
    }

    ll &ans = dp[i][j];

    if(ans != -1LL){
        return ans;
    }

    ans = min(solve(i, j - i) + a[i], solve(i + 1, j));

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    cin >> n >> q;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }

    while(q--){
        ll qi;

        cin >> qi;

        if(qi <= n){
            cout << a[qi] << endl;
        }else{
            if(qi < M){
                cout << solve(1, qi) << endl;
            }else{
                ll best = inf;
        
                for(ll i = 1 ; i <= n ; i++){
                    ll r = qi % i;
                    ll p = (m - r) / i;
                    ll res = r + p * i;
                    ll add = ((qi - res) / i) * a[i];
                    
                    best = min(best, add + solve(1, res));
                }

                cout << best << endl;
            }
            
        }
    }

    return 0;
}