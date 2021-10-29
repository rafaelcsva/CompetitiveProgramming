#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int tab[4][N][N];
int n;

int transform(int i, int p){
    int tot = 0;

    for(int l = 0 ; l < n ; l++){
        for(int c = 0 ; c < n ; c++){
            int e = (l + c) & 1;

            if(tab[i][l][c] != ((e + p) & 1)){
                tot++;
            }
        }
    }

    return tot;
}

int test(int mask){
    // printf("test w %d\n", mask);
    int ans = 0;

    for(int d = 0 ; d < 4 ; d++){
        int e = 1 << d;

        if(mask & e){
            // printf("transform %d in %d = %d\n", d, 1, transform(d, 1));
            ans += transform(d, 1);
        }else{
            // printf("transform %d in %d = %d\n", d, 0, transform(d, 1));
            ans += transform(d, 0);
        }
    }

    return ans;
}

int main(){
    scanf("%d", &n);

    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int l = 0 ; l < n ; l++){
                char c;

                scanf("\n%c", &c);
                tab[i][j][l] = (c == '1');
            }
        }

        // printf("e: %d\n", tab[i][0][0]);
    }

    int ans = int(1e9);

    for(int mask = 0 ; mask < (1 << 4) ; mask++){
        if(__builtin_popcount(mask) == 2){
            ans = min(ans, test(mask));
        }
    }

    printf("%d\n", ans);

    return 0;
}