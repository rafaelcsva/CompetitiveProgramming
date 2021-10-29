#include <bits/stdc++.h>

using namespace std;

const int N = int(110);
const int D = 3;
int dp[N][D];
int a[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        for(int d = 0 ; d < D ; d++){
            dp[i][d] = n;

            if((a[i] & d) == d){
                int add = 0;

                if(d == 0){
                    add = 1;
                }

                for(int j = 0 ; j < D ; j++){
                    if((j & d) == 0){
                        dp[i][d] = min(add + dp[i - 1][j], dp[i][d]);
                    }
                }
            }

            // printf("(%d, %d) = %d\n", i, d, dp[i][d]);
        }
    }

    printf("%d\n", min({dp[n][0], dp[n][1], dp[n][2]}));

    return 0;
}