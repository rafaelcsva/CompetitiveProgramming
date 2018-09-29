//10, 08, 2018, 16:19:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int MX = 1e6;
const int M = 5000;

ll n, m;
ll dp[8][MX];
bool used[8][MX];
ll mod = 1e9;

ll solve(int i, int j){
    if(i > n || j > m){
        return 0LL;
    }

    if(i == n && j == m){
        return 1LL;
    }

    if(j == m){
        if(i + 2 < n){
            return solve(i + 2, 0);
        }else{
            return 1LL;
        }
    }

    ll &ans = dp[i][j];

    if(used[i][j]){
        return ans;
    }

    ans = 0LL;
    used[i][j] = 1;

    if(i != n - 1){
        ans += solve(i, j + 1) * 2LL;
        ans %= mod;
        ans += solve(i, j + 2) * 3LL;
        ans %= mod;
        ans += solve(i, j + 3) * 2LL;
        ans %= mod;
    }else{
        ans += solve(i, j + 1);
        ans %= mod;
        ans += solve(i, j + 2);
        ans %= mod;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // pascal();
    // printf("calculed %d\n", MX * M);
    scanf("%lld %lld", &n, &m);

    if(m >= MX){
        printf("0\n");
    }else{
        printf("%lld\n", solve(0, 0));
    }

    return 0;
}