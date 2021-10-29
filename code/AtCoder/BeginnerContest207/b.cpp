#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll a, b, c, d;

    cin >> a >> b >> c >> d;

    ll lo = ll(1LL), hi = ll(1e6);
    ll r = -1LL;

    while(lo <= hi){
        ll x = (lo + hi) >> 1LL;

        if(a + x * b <= d * x * c){
            r = x;
            hi = x - 1;
        }else{
            lo = x + 1;
        }
    }

    printf("%lld\n", r);
    return 0;
}