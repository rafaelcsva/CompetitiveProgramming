#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll n, k;

    scanf("%lld %lld", &n, &k);

    for(ll d = 2 ; d <= n ; d++){
        ll add = 0;
        ll td = 1LL;
        ll tn = n;
        ll adde = 0;

        while(td * d < n){
            td *= d;
            adde++;
        }

        if(adde < k){
            printf("%lld, %lld\n", adde + n / d);
            break;
        }
    }

    return 0;
}