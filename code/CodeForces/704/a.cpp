#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll p, a, b, c;

        scanf("%lld %lld %lld %lld", &p, &a, &b, &c);

        ll mm = min({((p + a - 1LL) / a) * a, ((p + b - 1LL) / b) * b, ((p + c - 1LL) / c) * c});

        printf("%lld\n", mm - p);
    }

    return 0;
}