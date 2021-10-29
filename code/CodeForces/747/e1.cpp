#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 70;
ll dp[N][10];
int K;
const ll mod = ll(1e9) + 7LL;

ll solve(int k, int cl){
    if(k == K){
        return 1LL;
    }
    // printf("aqui!\n");
    ll &ans = dp[k][cl];
    // printf("%lld\n", ans);

    if(ans != -1){
        return ans;
    }

    ans = 0LL;

    for(int i = 1 ; i <= 6 ; i++){
        if((i + 1)/2  == (cl + 1) / 2){
            continue;
        }

        ll dx = solve(k + 1, i);

        ans += (dx * dx) % mod;
        // printf("%d, %lld\n", k, dx);

        if(ans >= mod){
            ans -= mod;
        }
    }

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d", &K);

    printf("%lld\n", solve(0, 0));

    return 0;
}