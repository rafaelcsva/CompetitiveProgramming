#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = ll(1e9) + 7LL;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, k;

        scanf("%lld %lld",&n, &k);
        ll r = 1LL;

        for(int i = 0 ; i < k ; i++){
            r = (r * n) % mod;
        }

        printf("%lld\n", r);
    }

    return 0;
}