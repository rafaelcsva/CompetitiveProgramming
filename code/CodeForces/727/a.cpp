#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int k;

    scanf("%d", &k);

    while(k--){
        ll n, x, t;

        scanf("%lld %lld %lld", &n, &x, &t);

        ll sum = 0LL;
        ll e = t / x;

        if(e > n){
            printf("%lld\n", ((n - 1LL) * n) / 2LL);
            continue;
        }

        ll ss = ((t / x - 1LL) * e) / 2LL;
        // printf("%lld %lld\n", )

        sum += (t / x) * (n - e) + ss;

        printf("%lld\n", sum);
    }

    return 0; 
}