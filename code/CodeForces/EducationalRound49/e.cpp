//18, 08, 2018, 13:17:01 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 510;
ll dp[N][N][N][2];
bool used[N][N][N][2];
const ll mod = 998244353LL;

ll solve(int pos, int nw, int mx, bool ver){
    if(nw > mx){
        return 0LL;
    }

    if(nw == mx){
        ver = true;
    }

    bool &us = used[pos][nw][mx][ver];
    ll &ans = dp[pos][nw][mx][ver];

    if(pos == 0){
        return ans = ver;
    }

    if(us){
        // return ans;
    }

    ans = 0LL;
    us = true;

    ans += solve(pos - 1, 1, mx, ver) + solve(pos - 1, nw + 1, mx, ver);
    ans %= mod;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    scanf("%d %d", &n, &k);

    ll tot = 0LL;

    for(int d = 1 ; d < k ; d++){
        if(d > n){
            printf("acabou no %d\n", d);
            break;
        }
        // if(solve(n, 0, d, false)){
        //     printf("1. (%d) + %lld\n", d, solve(n, 0, d, false));
        // }
        tot += solve(n, 0, d, false);
        
        // tot %= mod;
    }

    if(n > 1){
        for(int d = 1 ; d < k ; d++){
            if(d * n >= k || d > n){
                printf("breaked in %d\n", d);
                break;
            }

            // if(solve(n, 0, d, false)){
            //     printf("2. (%d) + %lld\n", d, solve(n, 0, d, false));
            // }
            tot += solve(n, 0, d, false);
            
            // tot %= mod;
        }
    }

    printf("%lld\n", tot);

    return 0;
}