#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, a;

        scanf("%lld %lld", &n, &a);

        ll sum = n * a;
    
        ll lo = 1LL, hi = n;
        ll r = 1LL;
        while(lo <= hi){
            ll mid = (lo + hi) >> 1LL;
            ll msum = ((1 + mid) * mid) / 2LL;

            if(sum - msum >= n - mid){
                r = mid;
                lo = mid + 1LL;
            }else{
                hi = mid - 1LL;
            }
        }

        printf("%lld\n", r);
    }

    return 0;
}