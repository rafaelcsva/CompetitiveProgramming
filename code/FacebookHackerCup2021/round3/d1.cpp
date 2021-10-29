#include <bits/stdc++.h>

using namespace std;

vector< vector< int > > tab;

void dfs(int i, int j){
    if(i < 0 || i >= tab.size() || j < 0 || j >= tab[i].size() || !tab[i][j]){
        return;
    }

    tab[i][j] = 0;

    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i, j + 1);
}

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ;  test <= t ; test++){
        int r, c;

        scanf("%d %d", &r, &c);

        tab.clear();
        tab.resize(r);

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                int hij;

                scanf("%d", &hij);
                tab[i].push_back(hij);
            }
        }

        int x = 0, y = 0;

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                int sij;

                scanf("%d", &sij);
                tab[i][j] = tab[i][j] > sij;

                x += tab[i][j];
            }
        }

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(tab[i][j]){
                    dfs(i, j);
                    y++;
                }
            }
        }

        printf("Case #%d: %d %d\n", test, x, y);
    }

    return 0;
}
