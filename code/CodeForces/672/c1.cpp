#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5 + 10);
long long a[N];
long long dp[N][2];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, q;

        scanf("%d %d", &n, &q);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        const int inf = int(1e9);

        dp[0][0] = a[0];
        dp[0][1] = 0;

        for(int i = 1 ; i < n ; i++){
            dp[i][0] = max(a[i] + dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = max(-a[i] + dp[i - 1][0], dp[i - 1][1]);
        }

        printf("%lld\n", max(dp[n - 1][0], dp[n - 1][1]));
    }
}

