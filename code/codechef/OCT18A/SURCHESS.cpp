//05, 10, 2018, 09:23:44 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 300;
const int inf = 1e9;
char tab[N][N];
int sum[N][N][2], suml[N][N][2], sumc[N][N][2];
int best[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0 ; i < N ; i++){
        best[i] = inf;
    }

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            scanf("\n%c", &tab[i][j]);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            int s = (i + j) & 1;
            int d = !s;

            if(tab[i][j] == '1'){
                suml[i][j][s] = 1;
            }

            suml[i][j][s] += suml[i][j - 1][s];
            suml[i][j][d] += suml[i][j - 1][d];
        }
    }

    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            int s = (i + j) & 1;
            int d = !s;

            if(tab[j][i] == '1'){
                sumc[j][i][s] = 1;
            }

            sumc[j][i][s] += sumc[j - 1][i][s];
            sumc[j][i][d] += sumc[j - 1][i][d];
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            int s = (i + j) & 1;
            int d = !s;

            if(tab[i][j] == '1'){
                sum[i][j][s] = 1;
            }            

            sum[i][j][s] += sum[i - 1][j - 1][s] + sumc[i - 1][j][s] + suml[i][j - 1][s];
            sum[i][j][d] += sum[i - 1][j - 1][d] + sumc[i - 1][j][d] + suml[i][j - 1][d];
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            for(int k = i, t = j ; k <= n && t <= m ; k++, t++){
                int tot = (k - i + 1) * (t - j + 1);
                int side = (k - i + 1);

                int fb = sum[k][t][0] - sum[k][j - 1][0] - sum[i - 1][t][0] + sum[i - 1][j - 1][0];
                int sb = sum[k][t][1] - sum[k][j - 1][1] - sum[i - 1][t][1] + sum[i - 1][j - 1][1];

                if((i + j) & 1){
                    swap(fb, sb);
                }
                
                int need_f = (tot + 1) / 2 - fb;
                int need_s = tot / 2 - sb;
                
                // if(side == 8){
                //     printf("%d %d %d %d\n", fb, sb, need_f, need_s);
                // }
                
                best[side] = min(best[side], need_f + sb);
                best[side] = min(best[side], fb + need_s);
            }
        }
    }

    int q;

    // printf("%d %d\n", sum[8][8][0], sum[8][8][1]);

    scanf("%d", &q);

    while(q--){
        int ci;

        scanf("%d", &ci);

        int ans = 0;

        for(int i = 1 ; i < N ; i++){
            if(best[i] <= ci){
                ans = i;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}