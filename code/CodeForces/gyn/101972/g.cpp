//15, 11, 2018, 15:47:56 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 510;
int tab[N][N];
int best1[N][N], best2[N][N];
int b1[N][N], b2[N][N], b3[N][N], b4[N][N];
int tmp[4];

int main(){
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                scanf("%d", &tab[i][j]);
            }
        }
        
        for(int j = 1 ; j <= m ; j++){
            for(int i = 1 ; i <= n ; i++){
                best1[i][j] = max(tab[i][j], best1[i - 1][j]);
            }
        }

        for(int j = 1 ; j <= m ; j++){
            for(int i = n ; i >= 1 ; i--){
                best2[i][j] = max(tab[i][j], best2[i + 1][j]);
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(j == 1){
                    b1[i][j] = best1[i][j];
                    continue;
                }

                b1[i][j] = max(b1[i][j - 1], best1[i][j]);
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = m ; j >= 1 ; j--){
                if(j == m){
                    b2[i][j] = best1[i][j];
                    continue;
                }

                b2[i][j] = max(b2[i][j + 1], best1[i][j]);
            }
        }

        for(int i = n ; i >= 1 ; i--){
            for(int j = 1 ; j <= m ; j++){
                if(j == 1){
                    b3[i][j] = best2[i][j];
                    continue;
                }

                b3[i][j] = max(b3[i][j - 1], best2[i][j]);
            }
        }

        for(int i = n ; i >= 1 ; i--){
            for(int j = m ; j >= 1 ; j--){
                if(j == m){
                    b4[i][j] = best2[i][j];
                    continue;
                }

                b4[i][j] = max(b4[i][j + 1], best2[i][j]);
            }
        }

        int best = 1e9;

        for(int i = 2 ; i < n ; i++){
            for(int j = 2 ; j < m ; j++){
                tmp[0] = b1[i - 1][j - 1];
                tmp[1] = b2[i - 1][j + 1];
                tmp[2] = b3[i + 1][j - 1];
                tmp[3] = b4[i + 1][j + 1];

                int mn = 1e9, mx = 0;

                for(int d = 0 ; d < 4 ; d++){
                    mx = max(mx, tmp[d]);
                    mn = min(mn, tmp[d]);
                }

                best = min(best, mx - mn);
            }
        }

        printf("%d\n", best);

        memset(b1, 0LL, sizeof b1);
        memset(b2, 0LL, sizeof b2);
        memset(b3, 0LL, sizeof b3);
        memset(b4, 0LL, sizeof b4);
        memset(best1, 0LL, sizeof best1);
        memset(best2, 0LL, sizeof best2);
    }

    return 0;
}