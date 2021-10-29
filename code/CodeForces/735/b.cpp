#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int E = 900;

ll a[301000];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        ll k;

        scanf("%d %lld", &n, &k);

        for(int i = 1 ; i <= n ; i++){
            scanf("%lld", &a[i]);
        }

        ll ans = -ll(1e18);

        for(int i = 1 ; i <= n ; i++){
            for(int j = i - 1 ; j >= 1 ; j--){
                if(i - j > E){
                    break;
                }

                ans = max(ans, ll(i) * ll(j) - k * (a[i] | a[j]));
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}