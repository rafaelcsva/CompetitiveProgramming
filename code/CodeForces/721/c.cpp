#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
map< int, ll > cnt;

int main(){
    int n;
    int t;
    
    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        ll ans = 0LL;

        for(ll i = 1LL ; i <= n ; i++){
            ll ai;
            scanf("%lld", &ai);

            ans += ll(n - i + 1LL) * cnt[ai];
            cnt[ai] += i; 
        }

        printf("%lld\n", ans);

        cnt.clear();
    }

    return 0;
}