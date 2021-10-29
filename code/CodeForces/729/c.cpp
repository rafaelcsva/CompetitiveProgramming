#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = ll(1e9) + 7LL;

const int N = 43;
ll dp[N];
ll pre[N];

int main(){
    ll cur = 1LL;

    for(ll i = 1LL ; i < N ; i++){
        cur = (cur * i) / __gcd(cur, i);
        pre[i] = cur;
        // printf("%lld\n", cur);
    }

    int t;

    scanf("%d", &t);

    while(t--){
        ll n;

        scanf("%lld", &n);

        ll ans = 0LL;

        memset(dp, 0, sizeof dp);

        for(ll d = N - 1 ; d >= 1 ; d--){
            dp[d] = n / pre[d];

            dp[d] %= mod;

            for(ll e = d + 1 ; e < N ; e++){
                dp[d] -= dp[e];

                if(dp[d] < 0){
                    dp[d] += mod;
                }
            }
            // printf("for %lld we have %lld %lld\n", pre[d], dp[d], d);
            ans = (ans + (dp[d] % mod) * (d + 1LL) % mod) % mod;
            // printf("ans = %lld\n", ans);
        }

        printf("%lld\n", ans);
    }

    return 0;
}