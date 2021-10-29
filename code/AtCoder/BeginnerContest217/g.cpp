#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 5010;
const ll mod = 998244353LL;

ll c[N][N];
ll dp[N][N];
int qtd[N];
ll fat[N];
ll calcx[N][N];

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

ll calc(int x, int j){
    if(calcx[x][j]){
        return calcx[x][j];
    }

    return calcx[x][j] = (fat[x] * fast_expo(fat[j], mod - 2)) % mod;
}

int main(){
    fat[0] = 1LL;

    for(int i = 1 ; i < N ; i++){
        fat[i] = ll(i) * fat[i - 1];
        fat[i] %= mod;
    }

    for(int i = 0 ; i < N ; i++){
        c[i][0] = c[i][i] = 1LL;

        for(int j = 1 ; j < i ; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];

            if(c[i][j] >= mod){
                c[i][j] -= mod;
            } 
        }
    }

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n ; i++){
        qtd[i % m]++;
    }

    dp[m - 1][qtd[m - 1]] = 1LL;

    for(int i = m - 2 ; i >= 0 ; i--){
        // printf("%d %d\n", i, qtd[i]);
        for(int k = 1 ; k <= n ; k++){
            for(int j = 1 ;  j <= min(qtd[i], k) ; j++){
                dp[i][k] += ((c[k - j][qtd[i] - j] * calc(qtd[i], j)) % mod) * dp[i + 1][k - j];
                dp[i][k] %= mod;
            }

            dp[i][k] += (((dp[i + 1][k] * c[k][qtd[i]]) % mod) * fat[qtd[i]]) % mod;

            if(dp[i][k] >= mod){
                dp[i][k] -= mod;
            }
        }
    }

    for(int k = 1 ; k <= n ; k++){
        printf("%lld\n", dp[0][k]);
    }

    return 0;
}