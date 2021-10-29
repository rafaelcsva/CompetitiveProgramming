#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
int dp[N][N];
int a[N][N];

int main(){
    int h, w;
    
    scanf("%d %d", &h, &w);

    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            char c;

            scanf("\n%c", &c);

            if(c == '+'){
                a[i][j] = 1;
            }else{
                a[i][j] = -1;
            }
        }
    }

    for(int i = h - 1 ; i >= 0 ; i--){
        for(int j = w - 1 ; j >= 0 ; j--){
            if(i == h - 1 && j == w - 1){
                continue;
            }

            dp[i][j] = -int(1e9);
            if(i != h - 1){
                dp[i][j] = a[i + 1][j] - dp[i + 1][j];
            }

            if(j != w - 1){
                dp[i][j] = max(dp[i][j], a[i][j + 1] - dp[i][j + 1]);
            }
        }
    }

    if(dp[0][0] > 0){
        printf("Takahashi\n");
    }else if(dp[0][0] == 0){
        printf("Draw\n");
    }else{
        printf("Aoki\n");
    }

    return 0;
}