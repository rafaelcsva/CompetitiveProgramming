#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

ll compute(ll n, ll k){
    if(k == 1){
        return int(1e9);
    }

    ll ans = 0;

    while(n){
        ans += n % k;
        n /= k;
    }

    return ans;
}

int main(){
    int q;

    scanf("%d", &q);

    while(q--){
        ll n, L, R;
    
        scanf("%lld %lld", &n, &R);
        L = 2;

        ll ans = ll(1e18);
        // R = n;
        ll ansi = L;
        // bool frag = false;

        for(ll l = 1, r; l <= n; l = r + 1) {
            r = n / (n / l);
            // n / i has the same value for l <= i <= r
            
            if(r < L) continue;

            if(l > R){
                continue;
            }
            // printf("%d-%d\n", l, r);
            // frag = true;
    
            ll res = compute(n, min(r, R));

            if(ans > res){
                ans = res;
                ansi = min(r, R);
            }

            // res = compute(n, max(l, L));

            // if(ans > res){
            //     ans = res;
            //     ansi = max(l, L);
            // }

            // if(ans == 1){
            //     break;
            // }
        }

        // assert(frag);
        printf("%lld\n", ansi);
    }

    return 0;
}
