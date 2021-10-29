#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll x[N], y[N];
int s[N];
ll bit[N];
const ll mod = 998244353LL;

int LSOne(int x){
    return x & (-x);
}

void update(int x, ll add){
    while(x < N){
        bit[x] += add;

        if(bit[x] >= mod){
            bit[x] -= mod;
        }

        x += LSOne(x);
    }
}

ll query(int x){
    ll sum = 0LL;

    while(x > 0){
        sum += bit[x];

        if(sum >= mod){
            sum -= mod;
        }
    
        x -= LSOne(x);
    }

    return sum;
}

ll rsq(int l, int r){
    ll res = query(r) - query(l - 1);

    if(res < 0LL){
        res += mod;
    }

    return res;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld %lld %d", &x[i], &y[i], &s[i]);
    }

    ll ans = 0LL;

    for(int i = 1 ; i <= n ; i++){
        ans += (x[i] - x[i - 1]);

        if(ans >= mod) ans -= mod;

        ll dpi = x[i] - y[i];

        if(dpi >= mod) dpi -= mod;
    
        int r = lower_bound(x + 1, x + 1 + n, y[i]) - x;

        if(r < i){
            dpi += rsq(r, i - 1);

            if(dpi >= mod) dpi -= mod;
        }

        update(i, dpi);

        if(s[i]){
            ans += dpi;

            if(ans >= mod) ans -= mod;
        }
    }

    ans++;

    if(ans >= mod){
        ans -= mod;
    }

    printf("%lld\n", ans);

    return 0;
}