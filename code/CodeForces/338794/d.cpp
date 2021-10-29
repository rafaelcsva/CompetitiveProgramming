#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll dp[N];
const ll mod = ll(1e9) + 7LL;

int main(){
    int t, k;

    scanf("%d %d", &t, &k);

    dp[0] = 1LL;

    for(int i = 1 ; i < N ; i++){
        dp[i] = dp[i - 1];

        if(i >= k){
            dp[i] += dp[i - k];

            if(dp[i] >= mod){
                dp[i] -= mod;
            }
        }
    }

    for(int i = 1 ; i < N ; i++){
        dp[i] += dp[i - 1];

        if(dp[i] >= mod){
            dp[i] -= mod;
        }
    }

    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);

        ll ans = dp[b] - dp[a - 1];

        if(ans < 0){
            ans += mod;
        }

        printf("%lld\n", ans);
    }

    return 0;
}