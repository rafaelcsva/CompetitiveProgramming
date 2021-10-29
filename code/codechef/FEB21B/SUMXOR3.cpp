#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];

ll comb(ll n, ll k){
    ll inv = bigMOD((fat[n - k] * fat[k]), MOD - 2, MOD);

    return (fat[n] * inv);
}

int main(){
    fat[0] = 1ll;

    for(ll i = 1ll ; i < N ; i++){
        fat[i] = (i * fat[i - 1]) % MOD;
    }

    int n, m;

    scanf("%d %d", &n, &m);

    for(int k = 1 ; k <= n ; k++){
        for(int i = 0 ; i < n ; i++){
            a[i] = (i + 1) <= k;
            printf("%d ", a[i]);
        }

        int ans = 0;

        for(int mask = 0 ; mask < (1 << n) ; mask++){
            if(__builtin_popcount(mask) > m) continue;
            // printf("mask = %d\n", mask);
            int sum = 0;
            for(int d = 0 ; d < n ; d++){
                int e = 1 << d;

                if(mask & e){
                    sum += a[d];
                }
            }

            ans += (sum & 1);
        }

        printf("| %d\n", ans);
    }
    printf("\n");

    return 0;
}