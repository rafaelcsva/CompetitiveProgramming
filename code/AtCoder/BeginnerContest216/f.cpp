#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair< int, int >    pii;

const int N = 5010;
const ll mod = 998244353LL;
ll dp[N][N];
pii a[N];

ll solve(int i, int x){
    if(x < 0LL){
        return 0LL;
    }

    if(i == 0){
        return 1LL;
    }

    auto &ans = dp[i][x];

    if(ans != -1){
        return ans;
    }

    ans = 0LL;

    ans = solve(i - 1, x) + solve(i - 1, x - a[i].second);

    if(ans >= mod){
        ans -= mod;
    }

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i].first);
    }

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i].second);
    }

    sort(a + 1, a + n + 1);

    ll ans = 0LL;

    for(int i = 1 ; i <= n ; i++){
        ans += solve(i - 1, a[i].first - a[i].second);
    
        if(ans >= mod){
            ans -= mod;
        }
    }

    printf("%lld\n", ans);

    return 0;
}