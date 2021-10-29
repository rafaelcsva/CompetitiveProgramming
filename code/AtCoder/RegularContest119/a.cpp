#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll n;

    scanf("%lld", &n);

    ll ans = ll(1e18) + 10;

    for(ll i = 0 ; i < 60LL ; i++){
        ll r = 1LL << i;

        ans = min(ans, (n / r) + i + (n % r));
    }

    printf("%lld\n", ans);

    return 0;
}