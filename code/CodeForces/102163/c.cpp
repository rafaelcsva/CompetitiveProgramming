//17, 04, 2019, 18:25:37 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
ll dp[N][2];
int a[N];
const ll mod = ll(1e9) + 7LL;

ll MOD(ll x){
    if(x >= mod){
        return x - mod;
    }

    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
        }

        dp[1][0] = dp[1][1] = 1LL;
        ll ans = 1LL;
        
        for(int i = 2 ; i <= n ; i++){
            ll best = 0LL;

            for(int j = 1 ; j < i ; j++){
                if(a[j] < a[i]){
                    best = max(best, dp[j][0]);
                }    
            }

            ll sum = 0LL;

            for(int j = 1 ; j < i ; j++){
                if(a[j] < a[i] && dp[j][0] == best){
                    sum = MOD(sum + dp[j][1]);
                }
            }

            dp[i][1] = max(sum, 1LL);
            dp[i][0] = best + 1LL;

            ans = max(ans, dp[i][0]);
        }

        ll tot = 0LL;

        for(int i = 1 ; i <= n ; i++){
            if(dp[i][0] == ans){
                tot = MOD(tot + dp[i][1]);
            }
        }

        cout << ans << " " << tot << endl;
    }

    return 0;
}