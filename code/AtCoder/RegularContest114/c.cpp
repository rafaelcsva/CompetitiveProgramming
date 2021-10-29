#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 5001;
const ll mod = 998244353LL;
ll dp[N][N];
int n;
ll m;

ll solve(int i, int op){
    if(i == n){
        // printf("%d\n", op);
        return ll(op);
    }

    ll &ans = dp[i][op];

    if(ans != -1LL){
        return ans;
    }

    return ans = (solve(i + 1, op) + (m - 1LL) * solve(i + 1, op + 1)) % mod;
}

int main(){
    memset(dp, -1LL, sizeof dp);

    scanf("%d %lld", &n, &m);

    ll ans = (solve(1, 1) * m) % mod;

    printf("%lld\n", ans);

    return 0;
}