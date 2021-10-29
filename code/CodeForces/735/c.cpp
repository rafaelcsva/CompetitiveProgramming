#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 40;
ll dp[N];
ll n, m;

ll solve(int d){
    if(d < 0){
        return ll(1e18);
    }

    ll &ans = dp[d];

    if(ans != -1LL){
        return ans;
    }

    ll e = 1LL << ll(d);

    // printf("%d %lld %lld\n", d, e, n & e);

    if(m & e){
        ans = (e ^ (n & e)) + solve(d - 1);
    }else{
        ans = min(solve(d - 1), e ^ (n & e));
    }

    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%lld %lld", &n, &m);

        memset(dp, -1, sizeof dp);

        if(n > m){
            printf("0\n");
        }else{
            printf("%lld\n", solve(32));
        }
    }

    return 0;
}