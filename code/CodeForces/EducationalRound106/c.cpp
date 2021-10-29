#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll c[N];
ll mn[2];
ll r[2];
ll sum[2];
const ll inf = ll(1e18);

int main(){
    int t;

    scanf("%d", &t);
    
    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%lld", &c[i]);
        }

        ll ans = inf;
        mn[0] = mn[1] = inf;
        r[0] = r[1] = inf;
        sum[0] = sum[1] = 0LL;

        for(int i = 1 ; i <= n ; i++){
            mn[i & 1] = min(mn[i & 1], c[i]);

            sum[i & 1] += c[i];

            ll qtd = ll((i + 1) / 2);
            r[i & 1] = ll(n - qtd + 1LL) * mn[i & 1] + sum[i & 1] - mn[i & 1];

            ans = min(ans, r[0] + r[1]);
        } 

        printf("%lld\n", ans);
    }

    return 0;
}