#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll a, b, c;

        scanf("%lld %lld %lld", &a, &b, &c);
        
        ll sum = a + b * 2LL + c * 3LL;

        ll hf = sum / 2LL;

        ll mc = min(c, hf / 3LL);
        ll ans = ll(1e18);

        for(int i = 0 ; i < 3 && mc >= 0 ; i++){
            ll r = hf - mc * 3LL;
            ll mb = min(b, r / 2LL);

            for(int j = 0 ; j < 2 && mb >= 0 ; j++){
                ll re = hf - mc * 3LL - mb * 2LL;
                ll e1 = min(re, a);

                ans = min(ans, sum - 2 * (mc * 3LL + mb * 2LL + e1));
            
                mb--;
            }

            mc--;
        }

        printf("%lld\n", ans);
    }

    return 0;
}