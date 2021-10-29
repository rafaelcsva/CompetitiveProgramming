#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        long long x, y, a, b;

        scanf("%lld %lld %lld %lld", &x, &y, &a, &b);

        if(a > b){
            swap(a, b);
        }

        if(a == b){
            printf("%lld\n", min(x / a, y / a));
            continue;
        }

        long long lo = 0, hi = min(x / a, y / a);
        long long t = b - a;
        long long ans = 0;
        const long long D = 100;

        while(hi - lo > D){
            long long mid1 = (2 * lo + hi) / 3;
            long long mid2 = (lo + 2 * hi) / 3;
            long long val1 = min((x - mid1 * a) / t + (y - mid1 * a) / t, mid1);
            long long val2 = min((x - mid2 * a) / t + (y - mid2 * a) / t, mid2);
            ans = max({ans, val1, val2});
            // prlong longf("%d %d %d %d\n", mid1, mid2, val1, val2);

            if(val1 <= val2){
                lo = mid1;
            }else{
                hi = mid2;
            }
        }

        for(long long r = lo ; r <= min(hi + 10,  min(x / a, y / a))  ; r++){
            ans = max(ans, min((x - r * a) / t + (y - r * a) / t, r));
        }

        printf("%lld\n", ans);
    }

    return 0;
}