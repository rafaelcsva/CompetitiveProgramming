#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        ll mx = -ll(1e9 + 1), mn = ll(1e9) + 1;

        for(int i = 0 ; i < n ; i++){
            ll ai;

            scanf("%lld", &ai);

            mx = max(mx, ai);
            mn = min(mn, ai);
        }
        // printf("%lld %lld\n", mx, mn);
        printf("%lld\n", (mx - mn) * 2LL);
    }

    return 0;
}