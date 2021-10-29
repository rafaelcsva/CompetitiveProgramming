#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, k;

        scanf("%lld %lld", &n, &k);

        ll sum = 0LL;
        ll ans = 0LL;

        for(int i = 0 ; i < n ; i++){
            ll ai;

            scanf("%lld", &ai);

            if(i != 0){
                ll val = (100LL * ai + k - 1LL) / k;
                if(sum < val){
                    ans += val - sum;
                    sum = val;
                }
            }

            sum += ai;
        }

        printf("%lld\n", ans);
    }

    return 0;
}