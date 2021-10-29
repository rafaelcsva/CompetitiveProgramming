#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
const int D = 110;
bool dp[D][N];
int t[N];

int main(){
    int n;

    scanf("%d", &n);

    int tot = 0;

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &t[i]);
        tot += t[i];
    }

    dp[0][0] = true;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= tot ; j++){
            dp[i][j] |= dp[i - 1][j];

            if(j >= t[i]){
                dp[i][j] |= dp[i - 1][j - t[i]];
            }
        }
    }

    int ans = N;

    for(int i = 0 ; i <= tot ; i++){
        if(dp[n][i]){
            ans = min(ans, max(i, tot - i));
        }
    }

    printf("%d\n", ans);

    return 0;
}