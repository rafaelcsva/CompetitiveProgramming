#include <bits/stdc++.h>

using namespace std;

const int N = 200;
int n, m;
int tab[N][N];
int vi[4] = {0, 0, -1, 1};
int vj[4] = {1, -1, 0, 0};

bool ok(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool is_valid(){
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            bool frag1 = tab[i][j] == 0;
            bool frag2 = true;

            for(int k = 0 ; k < 4 ; k++){
                int x = vi[k] + i;
                int y = vj[k] + j;

                if(ok(x, y)){
                    frag1 |= (tab[i][j] > tab[x][y]);
                    frag2 &= (abs(tab[i][j] - tab[x][y]) <= 1);
                }
            }

            if(!(frag1 & frag2)){
                return false;
            }
        }
    }

    return true;
}

void print_tab(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("-----------\n");
}

void solve(int i, int j){
    if(i == n){
        if(is_valid()){
            print_tab();
        }
        return;
    }

    for(int k = 0 ; k < min(n, m) ; k++){
        tab[i][j] = k;

        if(j == m - 1){
            solve(i + 1, 0);
        }else{
            solve(i, j + 1);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);

    solve(0, 0);

    return 0;
}