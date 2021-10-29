#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll d, k;

        scanf("%lld %lld", &d, &k);

        ll lo = 0LL, hi = (d / k) + 10LL;
        ll r = -1LL;
    
        while(lo <= hi){
            ll mid = (lo + hi) >> 1LL;
            ll km2 = (k * mid) * (k * mid);

            if(km2 * 2LL <= d * d){
                r = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1LL;
            }
        }

        // printf("r: %lld\n", r);
        if(k * r * k * r + k * (r + 1LL) * k * (r + 1LL) <= d * d){
            printf("Ashish\n");
        }else{
            printf("Utkarsh\n");
        }
    }

    return 0;
}
