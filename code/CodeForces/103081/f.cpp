#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 2023;
ll dp[N][2 * N];
ll mod;
int n, r;
ll inv2 = 0LL;

ll solve(int i, int qtd){
    if(qtd < 0){
        return 0LL;
    }

    if(i >= n){
        return qtd == 0LL;
    }

    ll &ans = dp[i][qtd];
    if(ans != -1LL){
        return ans;
    }
    
    ans = (ll(qtd) * solve(i + 1, qtd - 1LL)) % mod;
    if(i != r){
        ans = (ans + (ll(qtd) * solve(i + 1, qtd))) % mod;

        ll u = (ll(qtd) * solve(i + 1, qtd + 1)) % mod;
    
        u /= 2LL;
        ans = (ans + u) % mod;
    }
    // printf("%d, %d %d\n", i, qtd, r);
    // printf("ans = %lld\n", ans);

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    
    ll md;
    scanf("%d %d %lld", &r, &n, &md);
    mod = md;
    
    while(mod < ll(3e9)){
        mod <<= 1LL;
    }

    if(md == 1LL){
        printf("0\n");
        return 0;
    }
    r = n - r;

    if(mod & 1LL){
        inv2 = (mod + 1LL) / 2LL;
    }

    // printf("inv = %lld\n", inv2);

    printf("%lld\n", solve(0, 1LL) % md);

    return 0;
}