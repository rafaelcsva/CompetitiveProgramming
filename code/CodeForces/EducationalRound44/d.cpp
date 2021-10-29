#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

bool can(ll x, ll h, ll n){
    ll hf = x / 2LL;
    ll sumR = ((1LL + hf) * hf) / 2LL;

    ll oHf = (x + 1LL) / 2LL;

    ll sumLmax = 0LL;
    ll sumLmin = ((oHf + 1LL) * oHf) / 2LL;
    ll dec = 0LL;

    if(oHf <= h){
        sumLmax = oHf * oHf;
    }else{
        sumLmax = ((oHf - h + 1LL) * (h + oHf)) / 2LL;
    }

    if(x <= h){
        dec = ((1LL + x) * x) / 2LL;
    }

    return n <= max(sumLmax + sumR, dec);
}

int main(){
    ll n, h;

    scanf("%lld %lld", &n, &h);
    
    ll lo = 0LL;
    ll hi = 2LL * n;
    ll r = -1LL;

    while(lo <= hi){
        ll mid = (lo + hi) >> 1LL;

        if(can(mid, h, n)){
            r = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    assert(r != -1LL);

    printf("%lld\n", r);

    return 0;
}