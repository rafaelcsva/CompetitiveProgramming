//07, 10, 2018, 10:25:22 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
ll dp[1 << 2][N][N];
ll used[1 << 2][N][N];
const ll mod = 1e9 + 7;
int n, k;
int test;

ll solve(int mask, int i, int j){
    if(j == 0LL){
        return 1LL;
    }

    if(i == n){
        return 0LL;
    }

    ll &ans = dp[mask][i][j];

    if(used[mask][i][j] == test){
        return ans;
    }
    ans = 0LL;
    used[mask][i][j] = test;

    for(int d = 0 ; d < (1 << 2) - 1 ; d++){
        if((mask & d) == 0){
            ans += solve(d, i + 1, j - __builtin_popcount(d));
            ans %= mod;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    test = 1;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &k);

        test++;

        printf("%lld\n", solve(0, 0, k));
    }   

    return 0;
}