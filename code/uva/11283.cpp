//30, 07, 2018, 19:44:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 4, M = 16;
bool dp[(1 << M) + 1][N + 1][N + 1][M + 1];
int used[(1 << M) + 1][N][N + 1][M + 1];
char tab[N][N];
char s[M + 2];
int len;
int test = 1;

int get_points(int len){
    if(len <= 4){
        return 1;
    }

    if(len == 5){
        return 2;
    }

    if(len == 6){
        return 3;
    }

    if(len == 7){
        return 5;
    }

    return 11;
}

bool ok(int i, int j, int p){
    if(i < 0 || j < 0 || i >= N || j >= N){
        return false;
    }

    return tab[i][j] == s[p];
}

bool solve(int mask, int i, int j, int p){
    if(p == len){
        return true;
    }

    bool &ans = dp[mask][i][j][p];

    if(used[mask][i][j][p] == test){
        return ans;
    }

    used[mask][i][j][p] = test;

    ans = false;

    for(int addi = -1 ; addi <= 1 ; addi++){
        for(int addj = -1 ; addj <= 1 ; addj++){
            
            if(ok(addi + i, addj + j, p)){
                int el = 1 << ((addi + i) * N + j + addj);

                if((mask & el) == 0){
                   if(solve(mask | el, addi + i, addj + j, p + 1)){
                       return ans = true;
                   }
                }
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int game = 1;

    scanf("%d", &t);

    while(t--){
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                scanf("\n%c", &tab[i][j]);
            }
        }

        int k;

        scanf("%d", &k);

        int score = 0;
        
        for(int i = 0 ; i < k ; i++){
            scanf("\n%s", s);

            len = strlen(s);
            
            bool solved = false;

            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N ; j++){
                    if(tab[i][j] == s[0]){
                        int mask = 1 << (i * N + j);
                        
                        if(solve(mask, i, j, 1)){
                            solved = true;
                            break;
                        }
                    }
                }

                if(solved){
                    break;
                }
            }

            if(solved){
                score += get_points(len);
            }
            
            test++;
        }
    
        printf("Score for Boggle game #%d: %d\n", game++, score);
    }

    return 0;
}