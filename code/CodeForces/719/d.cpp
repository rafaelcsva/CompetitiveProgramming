#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
map< int, ll > cnt;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        ll ans = 0LL;

        for(int i = 1 ; i <= n ; i++){
            int ai;

            scanf("%d", &ai);

            ans += cnt[ai - i];
            cnt[ai - i]++;
        }

        printf("%lld\n", ans);

        cnt.clear();
    }

    return 0;
}