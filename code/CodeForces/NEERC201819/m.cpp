#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const int DIG = 8;
const int W = 10;
char cube[N + 1][N + 1][N + 1];
vector< int > topological_sort, topological_sort1, adj[N], radj[N], adj2[N];
bool vis[N];
bool vis1[N];
bool vis2[N];
int combel[N];
int dep[N];
vector< int > comp[N];

void dfs_top(int u){
    vis[u] = true;

    for(auto v: adj[u]){
        if(vis[v]) continue;

        dfs_top(v);
    }

    topological_sort.push_back(u);
}

void dfs_top1(int u){
    vis2[u] = true;

    for(auto v: adj2[u]){
        if(vis2[v]) continue;

        dfs_top1(v);
    }

    topological_sort1.push_back(u);
}

void dfs_comp(int u, int bel){
    comp[bel].push_back(u);
    combel[u] = bel;
    vis1[u] = true;

    for(auto v: radj[u]){
        if(vis1[v]) continue;

        dfs_comp(v, bel);
    }
}

int main(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                cube[i][j][k] = '#';
            }
        }
    }

    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int aij;

            scanf("%d", &aij);

            if(aij){
                adj[i].push_back(j);
                radj[j].push_back(i);
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            dfs_top(i);
        }
    }

    reverse(topological_sort.begin(), topological_sort.end());

    int bel = 0;

    for(auto u: topological_sort){
        if(!vis1[u]){
            dfs_comp(u, bel);
            bel++;
        }
    }

    for(int i = 0 ; i < bel ; i++){
        for(auto u: comp[i]){
            for(auto v: adj[u]){
                if(combel[u] != combel[v]){
                    adj2[combel[u]].push_back(combel[v]);
                }
            }
        }
    }

    for(int i = 0 ; i < bel ; i++){
        if(!vis2[i]){
            dfs_top1(i);
        }
    }

    reverse(topological_sort1.begin(), topological_sort1.end());

    for(int i = 0 ; i < bel ; i++){
        int pt = 0;

        for(int l = 0 ; l < W ; l++){
            for(int c = i * W ; c < i * W + W ; c++){
                if(pt < comp[topological_sort1[i]].size()){
                    // printf("on %d %d\n", i * DIG, comp[i][pt]);
                    cube[i * DIG][l][c] = ('0' + comp[topological_sort1[i]][pt++]);
                }else{ 
                    cube[i * DIG][l][c] = '.';
                }
            }
        }

        for(int c = 0 ; c < N ; c++){
            cube[i * DIG][W][c] = '.';
            cube[i * DIG + 1][W][c] = '.';
            cube[i * DIG + 2][W][c] = '.';
            cube[i * DIG + 3][W][c] = '.';
        }
    }

    
    for(int i = 0 ; i < topological_sort1.size() ; i++){
        dep[topological_sort1[i]] = i;
    }

    for(int i = 0 ; i < bel ; i++){
        for(auto u: comp[topological_sort1[i]]){
            for(auto v: adj[u]){
                if(dep[combel[u]] < dep[combel[v]]){
                    int a = dep[combel[v]];
                    int b = dep[combel[u]];
                    // printf("digg %d->%d\n", a, b);

                    for(int i = b * DIG + 3; i <= a * DIG ; i++){
                        // assert(cube[i][W - 1][a * W - 1] == '.' || cube[i][W - 1][a * W - 1] == '#');
                    
                        if(i == b * DIG + 3){
                            cube[i][W - 1][a * W + 2] = '.';
                        }

                        cube[i][W - 2][a * W + 2] = '.';
                    }
                }
            }
        }
    }

    printf("%d %d %d\n", N, N, N);

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                printf("%c", cube[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}