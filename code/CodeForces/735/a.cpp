#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

ll a[101000];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        ll ans = 0LL;

        for(int i = 1 ; i < n ; i++){
            ans = max(ans, a[i] * a[i - 1]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}