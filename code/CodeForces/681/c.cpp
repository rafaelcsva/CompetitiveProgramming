#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll a[N], b[N];

bool can(ll x, int n){
    ll sum = 0LL;

    for(int i = 0 ; i < n ; i++){
        if(a[i] > x){
            sum += b[i];
        }

        if(sum > x){
            return false;
        }
    }

    return true;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &b[i]);
        }

        ll lo = 1LL, hi = ll(1e9);
        ll r = -1LL;

        while(lo <= hi){
            ll mid = (lo + hi) >> 1LL;

            if(can(mid, n)){
                r = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }

        printf("%lld\n", r);
    }

    return 0;
}
