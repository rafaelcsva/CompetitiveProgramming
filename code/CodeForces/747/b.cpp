#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = ll(1e9) + 7LL;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, k;

        scanf("%lld %lld", &n, &k);

        ll pot = 1LL;

        ll number = 0LL;
        
        for(ll d = 0 ; d < 30LL ; d++){
            ll e = 1LL << d;
        
            if(k & e){
                number += pot;

                if(number >= mod){
                    number -= mod;
                }
            }

            pot = (pot * n) % mod;
        }

        printf("%lld\n", number);
    }

    return 0;
}