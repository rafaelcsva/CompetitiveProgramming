#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
const ll mod = 998244353LL;
ll fat[N];
int a[N];

ll fast_expo(ll x, ll e){
    ll b = x;
    ll r = 1LL;

    while(e){
        if(e & 1LL){
            r = (r * b) % mod;
        }

        e >>= 1LL;
        b = (b * b) % mod;
    }

    return r;
}

ll inv(ll x){
    return fast_expo(x, mod - 2);
}

ll mult(int a, int b){
    if(b < 0){
        return 0LL;
    }

    return (fat[a] * inv(fat[b])) % mod;
}

int main(){
    fat[0] = 1LL;

    for(ll i = 1LL ; i < N ; i++){
        fat[i] = i * fat[i - 1];
        fat[i] %= mod;
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }

        sort(a, a + n);

        if(a[n - 1] == a[n - 2]){
            printf("%lld\n", fat[n]);
        }else{
            if(abs(a[n - 2] - a[n - 1]) > 1){
                printf("0\n");
            }else{
                int cnt = 0;
            
                for(int i = 0 ; i < n ; i++){
                    if(a[n - 2] == a[i]){
                        cnt++;
                    }
                }
                int r = n - cnt - 1;

                ll ans = 0LL;

                for(int i = n - 2, j = 1 ; i >= 0 ; i--, j++){
                    ll add = fat[n - 1] - (mult(r, r - j) * fat[i]) % mod;

                    if(add < 0LL){
                        add += mod;
                    }

                    ans += add;

                    if(ans >= mod){
                        ans -= mod;
                    }
                }

                printf("%lld\n", ans);
            }
        }
    }

    return 0;
}