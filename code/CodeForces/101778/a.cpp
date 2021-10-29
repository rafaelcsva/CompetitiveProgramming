#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll fat[N];
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

ll inv(ll x){
    return fast_expo(x, mod - 2LL);
}

ll comb(ll n, ll k){
    ll d = inv((fat[n - k] * fat[k]) % mod);
    
    return (fat[n] * d) % mod;
}

int main(){
    int t;

    scanf("%d", &t);

    fat[0] = 1LL;

    for(ll i = 1LL ; i < N ; i++){
        fat[i] = (ll(i) * fat[i - 1]) % mod;
    }

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);
        n = abs(n);
        int tot = n + m;

        if(tot & 1){
            printf("0\n");
        }else{
            int x = tot / 2;

            if(x > m){
                printf("0\n");
            }else{
                ll p = inv(fast_expo(2LL, m));
                ll c = comb(m, x);

                printf("%lld\n", (c * p) % mod);
            }
        }
    }

    return 0;
}