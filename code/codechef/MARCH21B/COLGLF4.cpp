#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

ll a, b, c;

ll getMaxA(ll e, ll &x){
    ll c = e / 2LL;

    if(c >= x){
        ll cost = x * a;
        x = 0;
        return cost;
    }

    x -= c;
    return c * a;
}

ll getMaxB(ll h, ll &x){
    ll c = h / 3;

    if(c >= x){
        ll cost = x * b;
        x = 0;
        return cost;
    }

    x -= c;
    return c * b;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        ll e, h;

        scanf("%d %lld %lld %lld %lld %lld", &n, &e, &h, &a, &b, &c);

        ll ans = -1LL;

        for(ll d = 0 ; d <= n ; d++){
            if(d > e || d > h){
                break;
            }

            ll x = n - d;
            ll ee = e - d;
            ll hh = h - d;
            ll tmp = d * c;

            if(a < b){
                tmp += getMaxA(ee, x);
                tmp += getMaxB(hh, x);
            }else{
                tmp += getMaxB(hh, x);
                tmp += getMaxA(ee, x);
            }

            if(!x){
                if(ans == -1LL){
                    ans = tmp;
                }else{
                    ans = min(ans, tmp);
                }
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}