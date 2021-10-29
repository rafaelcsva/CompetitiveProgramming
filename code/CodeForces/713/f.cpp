#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll a[N];
ll b[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        ll c;

        scanf("%d %lld", &n, &c);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%lld", &b[i]);
        }

        ll money = 0LL;
        ll ans = ll(1e18);
        ll daysgone = 0LL;

        for(int i = 0 ; i < n ; i++){
            ll rest = c - money;
            // printf("(%d) at %lld\n", i, daysgone);

            if(rest > 0LL){
                ans = min(ans, daysgone + ((rest + a[i] - 1LL) / a[i]));
            }else{
                ans = min(ans, daysgone);
            }

            ll crest = b[i] - money;

            if(crest > 0LL){
                ll ear = (crest + a[i] - 1LL) / a[i];
                // printf("%lld\n", ear);
                daysgone += ear;
                money += a[i] * ear;
            }
            daysgone++;
            // printf("days=  %lld\n", daysgone);
            money -= b[i];
        }

        printf("%lld\n", ans);
    }

    return 0;
}