#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 1010;
ll dp[N][N][2];

void print(int n, int m){
    printf("-----------------\n");
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            printf("%lld ", dp[i][j][0] + dp[i][j][1] - 1LL);
        }
        printf("\n");
    }
}

int main(){
    int n, m, q;

    scanf("%d %d %d", &n, &m, &q);

    ll ans = 0LL;

    for(int i = n ; i >= 1; i--){
        for(int j = m ; j >= 1 ; j--){
            dp[i][j][0] = dp[i + 1][j][1] + 1;
            dp[i][j][1] = dp[i][j + 1][0] + 1;

            ans += dp[i][j][0] + dp[i][j][1] - 1LL;
        }
    }

    for(int i = 1 ; i <= q ; i++){
        int x, y;

        scanf("%d %d", &x, &y);

        if(dp[x][y][0]){
            ans -= dp[x][y][0] + dp[x][y][1] - 1LL;
            dp[x][y][0] = dp[x][y][1] = 0LL;
        }else{
            dp[x][y][0] = dp[x + 1][y][1] + 1;
            dp[x][y][1] = dp[x][y + 1][0] + 1;

            ans += dp[x][y][0] + dp[x][y][1] - 1LL;
        }

        int xx = x - 1;
        int yy = y;
        int d = 0;

        while(xx >= 1 && yy >= 1 && dp[xx][yy][d]){
            ans -= dp[xx][yy][d];
            // printf("(%d, %d, %d) %lld -> ", xx, yy, d, dp[xx][yy][d]);
            if(d){
                dp[xx][yy][d] = 1 + dp[xx][yy + 1][!d];
                ans += dp[xx][yy][d];
                // printf("%lld\n", dp[xx][yy][d]);
                xx--;
                d = !d;
            }else{
                dp[xx][yy][d] = 1 + dp[xx + 1][yy][!d];
                ans += dp[xx][yy][d];
                // printf("%lld\n", dp[xx][yy][d]);
                yy--;
                d = !d;
            }
            
        }

        xx = x;
        yy = y - 1;
        d = 1;

        while(xx >= 1 && yy >= 1 && dp[xx][yy][d]){
            ans -= dp[xx][yy][d];
            // printf("(%d, %d, %d) %lld -> ", xx, yy, d, dp[xx][yy][d]);
            if(d){
                dp[xx][yy][d] = 1 + dp[xx][yy + 1][!d];

                ans += dp[xx][yy][d];
                // printf("%lld\n", dp[xx][yy][d]);
                xx--;
                d = !d;
            }else{
                dp[xx][yy][d] = 1 + dp[xx + 1][yy][!d];

                ans += dp[xx][yy][d];
                // printf("%lld\n", dp[xx][yy][d]);
                yy--;
                d = !d;
            }
        }

        // print(n, m);
        printf("%lld\n", ans);
    }

    return 0;
}