#include <bits/stdc++.h>

using namespace std;

int g[110][110];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            int l = (n - 1) / 2;

            for(int j = 1 ; j <= l ; j++){
                int pos = (i + j) % n;
                g[i][pos] = 1;
                g[pos][i] = -1;
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                printf("%d ", g[i][j]);
            }
        }

        printf("\n");

        memset(g, 0, sizeof g);
    }

    return 0;
}