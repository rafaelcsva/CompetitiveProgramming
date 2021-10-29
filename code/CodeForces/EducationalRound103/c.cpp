#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = int(1e5) + 10;
ll c[N];
ll a[N], b[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &c[i]);
        }

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &b[i]);
        }

        ll ans = 0LL;
        ll cur = 0LL;

        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                cur = abs(b[i + 1] - a[i + 1]) + 1LL;
                continue;
            }

            ans = max(ans, c[i] + cur);

            if(a[i + 1] == b[i + 1]){
                cur = 1LL;
            }else{
                cur += c[i] - (abs(b[i + 1] - a[i + 1]) - 1LL);
                cur = max(cur, abs(b[i + 1] - a[i + 1]) + 1LL);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
