#include <bits/stdc++.h>

using namespace std;

const int N = 52;
int tab[N][N];

int main(){
    int h, w;

    scanf("%d %d", &h, &w);

    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            scanf("%d", &tab[i][j]);
        }
    }

    for(int i = 0 ; i < h ; i++){
        for(int j =0 ; j < w ; j++){
            for(int ii = i + 1 ; ii < h ; ii++){
                for(int jj = j + 1 ; jj < w ; jj++){
                    if(tab[i][j] + tab[ii][jj] > tab[ii][j] + tab[i][jj]){
                        printf("No\n");
                        return 0;
                    }
                }
            }
        }
    }

    printf("Yes\n");

    return 0;
}