#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 100;
ll a[N];
int n, k;

int can(ll x){
    for(int i = 0 ; i < n ; i++){
        int idx = upper_bound(a + i, a + n, a[i] + 2LL * x) - a;
        // printf("%d we have %d %lld %lld\n", i, idx, x, a[i] + 2LL * x);
        if(idx - i >= k + 1){
            return i;
        }
    }

    return -1;
}

int main(){
    int t;
    
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &k);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        ll lo = 0, hi = ll(1e9);
        ll x = -1;

        while(lo <= hi){
            ll mid = (lo + hi) >> 1;

            if(can(mid) != -1){
                hi = mid - 1;
                x = mid;
                // printf("can w %d\n", mid);
            }else{
                // printf("cant w %d\n", mid);
                lo = mid + 1;
            }
        }

        int idx = can(x);
        // printf("%d\n", can(499999999));
        printf("%lld\n", a[idx] + x);
    }

    return 0;
}