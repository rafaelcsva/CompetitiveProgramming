#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(5010);
ll dp[N][N];
ll a[N];
ll b[N];
ll pref[N];
ll suf[N];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &b[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        pref[i] = a[i] * b[i] + pref[i - 1];
    }

    for(int i = n ; i >= 1 ; i--){
        suf[i] = a[i] * b[i] + suf[i + 1];
        // printf("+%lld\n", a[i] * b[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        dp[i][i] = a[i] * b[i];
    }

    ll ans = suf[1];
    // printf("%lld\n", suf[n]);

    for(int d = 1 ; d <= n ; d++){
        for(int i = 1 ; i <= n - d ; i++){
            int j = i + d;
            ll add = a[i] * b[j] + b[i] * a[j];

            if(i + 1 <= j - 1){
                add += dp[i + 1][j - 1];
            }

            dp[i][j] = add;

            ans = max(ans, dp[i][j] + pref[i - 1] + suf[j + 1]);
        }
    }

    printf("%lld\n", ans);

    return 0;
}