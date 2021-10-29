#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = int(4e5) + 10;

const ll mod = ll(998244353LL);
ll fat[N];

ll fast_expo(ll x, ll e){
    ll r = 1LL;
    ll b = x;
    // printf("r: %lld %lld %lld\n", r, b, e);
    while(e){
        if(e & 1LL){
            r = (r * b) % mod;
        }

        e >>= 1LL;
        b = (b * b) % mod;
    }

    // printf("r: %lld %lld\n", r, b);

    return r;
}

ll inv(ll x){
    return fast_expo(x, mod - 2);
}

ll c(int n, int k){
    return (fat[n] * ((inv(fat[k]) * inv(fat[n - k])) % mod)) % mod;
}

int main(){
    fat[1] = fat[0] = 1LL;

    for(int i = 2; i < N; ++i){
        fat[i] = (ll(i) * fat[i - 1]) %mod;
    }
    int n, m;

    scanf("%d %d", &n, &m);

    ll ans = 0LL;

    for(int i = 1 ; i <= m ; i++){
        int ti = i;
        ll tmp = 1LL;
        for(int j = 2 ; j * j <= ti ; j++){
            int cnt = 0;
            while(ti % j == 0){
                cnt++;
                ti /= j;
            }

            if(cnt){
                tmp = (tmp * c(cnt + n - 1, n - 1)) % mod;
            }
        }
        // printf("exited!\n");

        if(ti != 1){
            tmp = (tmp * c(n, n - 1)) % mod;
        }
        ans += tmp;

        if(ans >= mod){
            ans -= mod;
        }
    }

    printf("%lld\n", ans);

    return 0;
}