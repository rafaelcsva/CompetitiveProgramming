#include <bits/stdc++.h>

using namespace std;

const int N = 12;
char tab1[N][N], tab2[N][N];
vector< int > adj[N * N];
int match[N * N];
int vis[N * N];

bool aug(int u){
    if(vis[u]){
        return false;
    }

    vis[u] = true;

    for(auto v: adj[u]){
        if(match[v] == -1 || aug(match[v])){
            match[v] = u;
            return true;
        }
    }

    return false;
}

int main(){
    int t;
    int test = 1;

    scanf("%d", &t);

    while(t--){
        int r, c, f, s;

        memset(match, -1, sizeof match);
    
        scanf("%d %d %d %d", &r, &c, &f, &s);

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                scanf("\n%c", &tab1[i][j]);
            }
        }

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                scanf("\n%c", &tab2[i][j]);
            }
        }

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(j != c - 1){
                    // printf("%c %c %c %c %d\n", tab1[i][j], tab2[i][j], tab1[i][j + 1], tab2[i][j + 1],);
                    if(tab1[i][j] != tab2[i][j] && tab1[i][j + 1] != tab2[i][j + 1] && tab1[i][j] != tab1[i][j + 1]){
                        int u = i * c + j;
                        int v = i * c + j + 1;

                        adj[u].push_back(v);
                        adj[v].push_back(u);
                        // printf("%d, %d -> %d %d\n", i, j, i, j + 1);
                    }
                }

                if(i != r - 1){
                    if(tab1[i][j] != tab2[i][j] && tab1[i + 1][j] != tab2[i + 1][j] && tab1[i][j] != tab1[i + 1][j]){
                        int u = i * c + j;
                        int v = (i + 1) * c + j;

                        adj[u].push_back(v);
                        adj[v].push_back(u);

                        // printf("%d, %d -> %d %d\n", i, j, i + 1, j);
                    }
                }
            }
        }

        int mtch = 0;
    
        for(int i = 0 ; i < r * c ; i++){
            memset(vis, 0, sizeof vis);

            int ii = i / c;
            int jj = i % c;
            if(aug(i) && (ii + jj) & 1){
                // printf("adds on (%d, %d)\n", i / c, i % c);
                mtch++;
            }
        }

        int tot = 0;

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(tab1[i][j] != tab2[i][j]){
                    tot++;
                }

                adj[i * c + j].clear();
            }
        }

        printf("Case #%d: %d\n", test++, min((tot - 2 * mtch) * f + mtch * s, f * tot));
    }

    return 0;
}