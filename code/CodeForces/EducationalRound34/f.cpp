#include <bits/stdc++.h>

using namespace std;

const int N = int(1e3 + 10);
int a[4];
int tab[4][N];
int premask[4][4];
int n;
int dp[N][(1 << 16)];

int adjust(int c, int mask){
    int nmask = 0;

    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            int val = 0;
            int pos = (i * 4 + j + 1);
            int posl = (i * 4 + j);
    
            if(j == 3){
                val = tab[i][c + 4];
            }else{
                val = (mask & (1 << pos)) != 0;
            }

            nmask |= (1 << (posl)) * val;
        }
    }

    // printf("%d moves to %d\n", mask, nmask);

    return nmask;
}

int solve(int i, int mask){
    // printf("%d %d %d\n", i, mask, n);
    // return 0;
    if(i >= n){
        return 0;
    }

    int &ans = dp[i][mask];

    if(ans != -1){
        return ans;
    }

    bool vermask = false;

    for(int i = 0 ; i < 4 ; i++){
        int e = 1 << (i * 4);

        if((mask & e) == 0){
            vermask = true;
            break;
        }
    }

    if(!vermask){
        // printf("%d moves\n", mask);
        return ans = solve(i + 1, adjust(i, mask));
    }

    // printf("%d dont moves\n", mask);

    ans = int(1e9);

    for(int k = 1 ; k <= 4 ; k++){
        for(int d = 0 ; d <= 4 - k ; d++){
            if((mask | premask[k - 1][d]) != mask){
                // printf("%d w %d = %d adds %d on %d\n", k, d, mask | premask[k - 1][d], a[k - 1], mask);
                ans = min(ans, a[k - 1] + solve(i, mask | premask[k - 1][d]));
                // if(ans == 3){
                //     break;
                // }
            }
        }
        // if(ans == 3) break;
    }

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);
    // printf("n = %d\n", n);

    for(int i = 0 ; i < 4 ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < n ; j++){
            char c;

            scanf("\n%c", &c);

            tab[i][j] |= (c == '.');
        }
    }
    // printf("n =  %d\n", n);

    for(int k = 1 ; k <= 4 ; k++){
        for(int i = 0 ; i <= 4 - k ; i++){
            for(int j = 0 ; j < k ; j++){
                for(int l = 0 ; l < k ; l++){
                    int e = ((i + l) * 4) + j;
            
                    premask[k - 1][i] |= (1 << e);
                }
            }
            // printf("%d, %d = %d\n", k - 1, i, premask[k - 1][i]);
            // printf("n aqui =  %d\n", n);
        }
    }
    // printf("n =  %d\n", n);

    int initmask = 0;

    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            initmask |= (1 << ((i * 4 + j))) * tab[i][j];
        }
    }

    // printf("init mask = %d, %d\n", initmask, n);

    printf("%d\n", solve(0, initmask));

    return 0;
}