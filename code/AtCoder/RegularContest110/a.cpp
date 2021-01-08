#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

ll mlcm(ll lcm, ll i){
    return lcm * (i / __gcd(lcm, i));
}

int main(){
    ll n;

    scanf("%lld", &n);

    ll lcm = 1LL;

    for(ll i = 2LL ; i <= n ; i++){
        lcm = mlcm(lcm, i);
    }

    printf("%lld\n", lcm + 1LL);

    for(ll i = 2LL ; i <= n ; i++){
        assert((lcm + 1LL) % i == 1LL);
    }

    return 0;
}