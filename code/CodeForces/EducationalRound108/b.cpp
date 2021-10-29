#include <bits/stdc++.h>

using namespace std;

const int N = 110;
bool dp[N][N][10010];

int main(){
    dp[1][1][0] = true;

    for(int i = 1 ; i < N ; i++){
        for(int j = 1 ; j < N ; j++){
            for(int k = 1 ; k < 10010 ; k++){
                if(k >= j){
                    dp[i][j][k] = dp[i - 1][j][k - j];
                }
                if(k >= i){
                    dp[i][j][k] |= dp[i][j - 1][k - i];
                }
            }
        }
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int n, m, k;

        scanf("%d %d %d", &n, &m, &k);

        if(dp[n][m][k]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}