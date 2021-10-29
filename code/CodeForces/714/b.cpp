#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll fat[N];
ll a[N];
const ll mod = ll(1e9) + 7LL;

int main(){
    fat[0] = 1LL;

    for(ll i = 1LL ; i < N ; i++){
        fat[i] = (i * fat[i - 1]) % mod;
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        ll res = -1LL;

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);

            if(res == -1LL){
                res = a[i];
            }else{
                res &= a[i];
            }
        }

        ll qtd = 0LL;

        for(int i = 0 ; i < n ; i++){
            qtd += (a[i] == res);
        }

        ll ans = (((qtd * (qtd - 1LL)) % mod) * fat[n - 2]) % mod;

        printf("%lld\n", ans);
    }

    return 0;
}