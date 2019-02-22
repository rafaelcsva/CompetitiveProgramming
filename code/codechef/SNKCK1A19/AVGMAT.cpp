//20, 10, 2018, 08:21:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 310;
const int off_set = 610;
int sum1[N + 2 * off_set][N + 2 * off_set], sum2[N + 2 * off_set][N + 2 * off_set];
char tab[N + 2 * off_set][N + 2 * off_set];
int resp[N * 4];

void solve(int row, int col, int lim){
    for(int l = 1 ; l <= lim ; l++){
        int suma = sum1[row][col - l] - sum1[row - l - 1][col + 1];
        int sumb = sum2[row][col + l] - sum2[row - l - 1][col - 1];
        int sumc = sum1[row + l][col] - sum1[row - 1][col + l + 1];
        int sumd = sum2[row + l][col] - sum2[row - 1][col - l - 1];
        // printf("%d %d %d %d %d %d\n", suma, sumb, sumc, sumd, l, sum1[row + l][col]);

        int rea = tab[row - l][col] == '1' ? 1 : 0;
        int reb = tab[row][col + l] == '1' ? 1 : 0;
        int rec = tab[row + l][col] == '1' ? 1 : 0;
        int red = tab[row][col - l] == '1' ? 1 : 0;

        resp[l] += suma + sumb + sumc + sumd - (rea + reb + rec + red);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                scanf("\n%c", &tab[i + off_set][j + off_set]);
            }
        }

        int mm = N + 2 * off_set - 1;
        int nn = N + 2 * off_set - 1;

        // printf("(%d x %d)\n", nn, mm);
        for(int j = 1 ; j <= mm ; j++){
            int lin = 1;
            int col = j;

            while(lin <= nn && col >= 1){
                sum1[lin][col] = tab[lin][col] == '1' ? 1 : 0;

                sum1[lin][col] += sum1[lin - 1][col + 1];
                lin++, col--;
            }
        }

        for(int i = 2 ; i <= nn ; i++){
            int lin = i;
            int col = mm;

            while(lin <= nn && col >= 1){
                sum1[lin][col] = tab[lin][col] == '1' ? 1 : 0;

                sum1[lin][col] += sum1[lin - 1][col + 1];
                lin++, col--;
            }
        }

        for(int j = 1 ; j <= mm ; j++){
            int lin = 1;
            int col = j;

            while(lin <= nn && col <= mm){
                // printf("(%d, %d)\n", lin, col);
                sum2[lin][col] = tab[lin][col] == '1' ? 1 : 0;

                sum2[lin][col] += sum2[lin - 1][col - 1];
                lin++, col++;
            }
        }

        for(int i = 2 ; i <= nn ; i++){
            int lin = i;
            int col = 1;

            while(lin <= nn && col <= mm){
                // printf("(%d, %d)\n", lin, col);
                sum2[lin][col] = tab[lin][col] == '1' ? 1 : 0;

                sum2[lin][col] += sum2[lin - 1][col - 1];
                lin++, col++;
            }
        }


        int lim = n + m - 2;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(tab[i + off_set][j + off_set] == '1'){
                    assert(sum1[i + off_set][j + off_set] != 0 && sum2[i + off_set][j + off_set] != 0);
                    
                    // printf("test = %d %d %d\n", sum1[i + off_set][j + off_set], i + off_set, j + off_set);
                    solve(i + off_set, j + off_set, lim);
                }
            }
        }

        for(int i = 1 ; i <= lim ; i++){
            char c = i == lim ? '\n' : ' ';
            printf("%d%c", resp[i] / 2, c);
        }

        memset(resp, 0, sizeof resp);
        memset(tab, 0, sizeof tab);
    }

    return 0;
}