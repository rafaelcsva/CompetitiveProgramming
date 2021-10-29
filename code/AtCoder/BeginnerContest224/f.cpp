#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
const ll mod = ll(998244353LL);
ll dp[N];
ll pot[N];

int main(){
    pot[0] = 1LL;
    ll e = 1LL;

    for(int i = 1 ; i < N ; i++){
        if(i >= 2){
            e = (e * 2LL) % mod;
        }

        pot[i] = (e + 10LL * pot[i - 1]) % mod;
    }

    string s;

    cin >> s;

    int n = s.length();

    ll sufdp = 0LL;
    ll sufnm = 0LL;
    ll tpot = 1LL;

    for(int i = n - 1 ; i >= 0 ; i--){
        ll d = s[i] - '0';

        ll add = (d * pot[n - i - 1]) % mod;
        dp[i] = (add + sufnm + sufdp) % mod;
        sufnm = (add + sufnm) % mod;
        sufdp = (sufdp + dp[i]) % mod;

        // printf("%lld %lld %lld\n", sufnm, sufdp, dp[i]);
        tpot = (tpot * 2LL) % mod;
    }

    printf("%lld\n", dp[0]);

    return 0;
}