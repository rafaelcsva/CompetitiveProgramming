#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = ll(1e9) + 7LL;
const int N = 5010;

ll dp[N][N];
ll f[N];
ll a[N];

int main(){
    int n, k, q;

    scanf("%d %d %d", &n, &k, &q);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
        dp[i][0] = 1LL;
    }

    for(int j = 1 ; j <= k ; j++){
        for(int i = 1 ; i <= n ; i++){
            dp[i][j] = dp[i - 1][j - 1] + dp[i + 1][j - 1];

            if(dp[i][j] >= mod){
                dp[i][j] -= mod;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= k ; j++){
            f[i] = (f[i] + dp[i][j] * dp[i][k - j]) % mod;
        }
    }

    ll ans = 0LL;

    for(int i = 1 ; i <= n ; i++){
        ans = (ans + f[i] * a[i]) % mod;
    }

    while(q--){
        int pos;
        ll x;

        scanf("%d %lld", &pos, &x);

        ans -= f[pos] * a[pos];
        a[pos] = x;
        ans += f[pos] * a[pos];

        ans = ((ans % mod) + mod) % mod;

        printf("%lld\n", ans);
    }

    return 0;
}