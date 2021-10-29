#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(4e6) + 10;
ll dp[N][2];
const ll mod = ll(1e9) + 7LL;

ll fast_expo(ll x, ll e){
    ll b = x;
    ll r = 1LL;

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
    dp[0][0] = 1LL;

    for(int i = 1 ; i < N ; i++){
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = (2LL * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);
        int cnthas = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                char c;

                scanf("\n%c", &c);

                if(c == '#'){
                    cnthas++;
                }
            }
        }

        if(cnthas == n * m){
            printf("%lld\n", dp[cnthas][1]);
        }else{
            printf("%lld\n", fast_expo(2LL, cnthas));
        }
    }

    return 0;
}