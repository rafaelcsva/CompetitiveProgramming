#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

ll dp[1010][10][1034];
int n;
string s;
const ll mod = 998244353LL;

ll solve(int i, int l, int msk){
    if(i == n){
        return 1LL;
    }

    auto &ans = dp[i][l][msk];

    if(ans != -1LL){
        return ans;
    }

    ans = 0LL;

    int c = s[i] - 'A';

    if(c == l || ((msk & (1 << c)) == 0)){
        ans = solve(i + 1, c, msk | (1 << c));
    }

    ans += solve(i + 1, l, msk);

    if(ans >= mod){
        ans -= mod;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    cin >> n;
    cin >> s;

    ll ans = 0LL;

    for(int i = 0 ; i < n ; i++){
        int c = s[i] - 'A';

        ans += solve(i + 1, c, 1 << c);

        if(ans >= mod){
            ans -= mod;
        }
    }

    printf("%lld\n", ans);

    return 0;
}