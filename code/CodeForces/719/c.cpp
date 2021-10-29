#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int mat[N][N];
set< int > st;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        if(n == 2){
            printf("-1\n");
            continue;
        }
        
        int st = 1;

        for(int i = n ; i >= 1 ; i--){
            int l = n;
            for(int j = i ; j <= n ; j++){
                mat[l][j] = st++;
                l--;
            }
        }

        for(int i = n - 1 ; i >= 1 ; i--){
            int l = i;
            for(int j = 1 ; l >= 1 ; j++){
                mat[l][j] = st++;
                l--;
            }
        }

        swap(mat[1][1], mat[n][n]);
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}