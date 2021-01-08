#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;
const int N = int(2e5) + 10;
int color[N];
vector< pii > adj[N];
int vis[N];
int n, m;

void dfs(int u, int ft){
    vis[u] = 1;

    for(auto v: adj[u]){
        if(vis[v.first]){
            continue;
        }

        if(color[u] == -1){
            if(v.second != color[ft]){
                color[u] = v.second;
                dfs(v.first, u);
            }else{
                color[v.first] = v.second;
                dfs(v.first, u);
            }
        }else{
            if(v.second == color[u]){
                dfs(v.first, u);
            }else{
                color[v.first] = v.second;
                dfs(v.first, u);
            }
        }
    }

    if(color[u] == -1){
        if(color[ft] != n)
            color[u] = color[ft] + 1;
        else
            color[u] = color[ft] - 1;
    }
}

int main(){
    memset(color, -1, sizeof color);

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; i++){
        int u, v, c;

        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs(1, 0);

    for(int i = 1 ; i <= n ; i++){
        printf("%d\n", color[i]);
    }

    return 0;
}