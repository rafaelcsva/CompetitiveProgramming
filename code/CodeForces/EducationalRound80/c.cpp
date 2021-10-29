#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = ll(1e9) + 7LL;

const int N = 1010;
const int D = 20;
ll dp[N][D];
int n, m;

ll solve(int i, int j){
    if(i >= n){
        return 0LL;
    }
    if(j == 0){
        return 1LL;
    }
    // printf("%d %d\n", i, j);
    ll &ans = dp[i][j];
    if(ans != -1){
        return ans;
    }

    ans = solve(i + 1, j) + solve(i, j - 1);

    if(ans >= mod){
        ans -= mod;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);

    cin >> n >> m;

    cout << solve(0, 2 * m) << "\n";

    return 0;
}