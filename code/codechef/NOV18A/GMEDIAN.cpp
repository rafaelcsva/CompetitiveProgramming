//02, 11, 2018, 08:28:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2011;
ll c[N][N];
ll pref[N][N];
const ll mod = 1e9 + 7;
int a[N];
int cnt[N];
int goes[N];

void pascal(){
    for(int i = 0 ; i < N ; i++){
        c[i][i] = c[i][0] = 1LL;
        for(int j = 1 ; j < i ; j++){
            c[i][j] += c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= mod;
        }        
    }
}

ll MOD(ll x){
    if(x >= mod || x < 0LL){
        x %= mod;
        x += mod;
        x %= mod;
    }

    return x;
}

ll sum_to(int f, int s, int k){
    if(s == 0){
        return pref[f][k];
    }

    // printf("%d %d %d %lld %lld\n", f, s, k, pref[f][k], pref[s - 1][k]);
    return pref[f][k] - pref[s - 1][k];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    pascal();

    for(int i = 0 ; i < N ; i++){
        pref[0][i] = c[0][i];

        for(int j = 1 ; j < N ; j++){
            pref[j][i] = pref[j - 1][i] + c[j][i];
            pref[j][i] = MOD(pref[j][i]);
        }
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }

        sort(a + 1, a + n + 1);

        ll odd_arrays = 0LL;

        for(int i = 1 ; i <= n ; i += 2){
            odd_arrays += c[n][i];
            odd_arrays %= mod;
        }

        ll even_arrays = 0LL;

        for(int i = 1 ; i <= n ; i++){
            goes[a[i]]++;
            int q = cnt[a[i]] - goes[a[i]];

            if(!q){
                continue;
            }

            // printf("to aqui!\n");

            int lo = i - 1;
            // printf("lo = %d %d\n", lo, q);

            for(int k = 0 ; k <= lo ; k++){
                even_arrays += c[lo][k] * MOD(sum_to(n - (i + 1), n - (i + q), k));
                // printf("%d %d %d %lld\n", (n - (i + 1)), (n - (i + q)), k, MOD(sum_to(n - (i + 1), n - (i + q), k)));
                even_arrays = MOD(even_arrays);
            }
        }

        // printf("odd = %lld | even = %lld\n", odd_arrays, even_arrays);

        ll tot = (even_arrays + odd_arrays) % mod;

        printf("%lld\n", tot);

        memset(goes, 0, sizeof goes);
        memset(cnt, 0, sizeof cnt);
    }

    return 0;
}