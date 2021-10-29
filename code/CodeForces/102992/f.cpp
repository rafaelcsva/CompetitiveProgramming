#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(3e4);

int main() {
    int t;

    scanf("%d", &t);

    while(t--){
        double n, m, p;

        scanf("%lf %lf %lf", &n, &m, &p);

        p = 1.0 - p / 10000.0;
        double q = p;
        double ans = 1e18;

        ll lo = 1LL, hi = ll(1e13);

        while(hi - lo > 10){
            ll mid1 = (2LL * lo + hi) / 3LL;
            ll mid2 = (lo + hi * 2LL) / 3LL;
            double val1 = (mid1 * n + m) / (1.0 - pow(p, mid1));
            double val2 = (mid2 * n + m) / (1.0 - pow(p, mid2));

            if(val1 > val2){
                lo = mid1;
            }else{
                hi = mid2;
            }
        }
        for(ll i = lo ; i <= hi ; i++){
            double tmp = (i * n + m) / (1.0 - pow(p, i));

            ans = min(ans, tmp);
            q *= p;
        }

        printf("%.8lf\n", ans);
    }

    return 0;
}