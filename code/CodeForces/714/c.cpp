#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int D = 10;
const int M = int(2e5) + 10;
const ll mod = ll(1e9) + 7LL;
ll dp[D][M];

int main(){
    for(int j = 0 ; j < D ; j++){
        dp[j][0] = 1LL;
    }

    for(int i = 1 ; i < M ; i++){
        for(int d = 0 ; d < D ; d++){
            if(d == 9){
                dp[d][i] = dp[0][i - 1] + dp[1][i - 1];

                if(dp[d][i] >= mod){
                    dp[d][i] -= mod;
                }
            }else{
                dp[d][i] = dp[d + 1][i - 1];
            }
        }
    }

    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        ll ans = 0LL;

        while(n){
            ans += dp[n % 10][m];
            if(ans >= mod){
                ans -= mod;
            }
            n /= 10;
        }

        printf("%lld\n", ans);
    }

    return 0;
}