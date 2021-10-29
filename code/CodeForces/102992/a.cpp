#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int tab[N][N];
int startcol, endcol, startlin, endlin;

int main(){
    int n, m;

    // scanf("%d %d", &n, &m);

    endcol = endlin = N - 1;
    int mov = 0;

    int i = 0, j = 0;

    while(startcol <= endcol && startlin <= endlin){
        if(mov == 0){
            while(i <= endlin){
                tab[i][j] = 1;
                i++;
            }
            i--;
            startcol += 2;
        }else if(mov == 1){
            while(j <= endcol){
                tab[i][j] = 1;
                j++;
            }
            j--;
            endlin -= 2;
        }else if(mov == 2){
            while(i >= startlin){
                tab[i][j] = 1;
                i--;
            }
            i++;
            endcol -= 2;
        }else if(mov == 3){
            while(j >= startcol){
                tab[i][j] = 1;
                j--;
            }
            j++;
            startlin += 2;
        }
        mov = (mov + 1) % 4;
    }

    printf("%d %d\n", N, N);

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}