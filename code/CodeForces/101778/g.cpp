#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll k, l, m, n;

        scanf("%lld %lld %lld %lld", &k, &l, &m, &n);

        double sen = ((m * 2.0) / double(k)) / double(l);
        double a = k / double(l);
        double b = (2.0 * n / sen);
    
        double f = sqrt(a) * sqrt(b);
        double g = (f * (l / double(k)));

        printf("%.8lf %.8lf\n", f - l, g - k);
    }

    return 0;
}