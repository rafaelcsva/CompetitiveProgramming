#include <bits/stdc++.h>

using namespace std;

const int N = int(5e5) + 10;
int p[N];
int cicle_sz[N];
int vis[N];
int walk[N], walkcicle[N];
int father[N];
int ans[N];
vector< int > adj[N];

int dfs1(int u, int &csz){
    vis[u] = 1;

    for(auto v: adj[u]){
        if(vis[p[u]] == 1){
            csz++;
            father[u] = p[u];

            return p[u];
        }else{
            int d = dfs1(p[u], csz);
            father[u] = d;

            if(d){
                csz++;
                if(d == u){
                    cicle_sz[u] = csz;

                    return 0;
                }else{
                    return d;
                }
            }
        }
    }

    vis[u] = 2;
    return 0;
}

void dfs2(int u){
    if(vis[u]){
        return;
    }

    vis[u] = 1;

    for(auto v: adj[u]){
        dfs2(u);

        if(walkcicle[])
    }
}

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 1 ; i <= n ; i++){
        adj[p[i]].push_back(i);
    }

    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            int csz = 0;
            dfs1(i, csz);
        }
    }

    memset(vis, 0, sizeof vis);

    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            dfs2(i);
        }    
    }

    for(int i = 1 ; i <= n ; i++){
        if(walk[i] >= k){
            printf("%d\n", k + 1);
        }else{
            int ans = walk[i] + min(2 * (k - walk[i]), walkcicle[i] - 1) + 1;

            printf("%d\n", ans);
        }
    }

    return 0;
}