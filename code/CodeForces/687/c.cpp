#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int dp[N];
int n, p, k;
char a[N];
int x, y;

int solve(int i){
    if(i > n){
        return 0;
    }

    int &ans = dp[i];

    if(ans != -1){
        return ans;
    }

    ans = solve(i + k) + (1 - a[i]) * x;

    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        memset(dp, -1, sizeof dp);

        scanf("%d %d %d", &n, &p, &k);

        for(int i = 1 ; i <= n ; i++){
            scanf("\n%c", &a[i]);
            a[i] -= '0';
        }

        scanf("%d %d", &x, &y);

        int ans = int(1e9);

        for(int i = 1 ; i <= n - p + 1 ; i++){
            ans = min(ans, solve(i + p - 1) + (i - 1) * y);
        }

        printf("%d\n", ans);
    }

    return 0;
}