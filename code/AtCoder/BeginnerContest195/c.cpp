#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll n;

    ll sum = 0LL;

    scanf("%lld", &n);

    ll p = 1LL;
    ll d = 1LL;

    while(p * 10LL <= n){
        p *= 10LL;
        d++;
    }
    // printf("ak\n");

    while(n){
        ll r = n - p + 1LL;
        sum += ((d - 1LL) / 3LL) * r;
        p /= 10LL;
        n -= r;
        // printf("%lld\n", n);
        d--;
    }

    printf("%lld\n", sum);

    return 0;
}