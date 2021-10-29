#include <bits/stdc++.h>

using namespace std;

const int N = int(4e5) + 10;
int adj[N];
bool vis[N];
const int mod = int(1e9) + 7;
int a[N], b[N];

void dfs(int u){
    if(vis[u]) return;
    vis[u] = true;
    dfs(adj[u]);
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
        }

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &b[i]);
            adj[a[i]] = b[i];
        }

        int ans = 1;

        for(int i = 1 ; i <= n ; i++){
            if(!vis[i] && adj[i] != i){
                ans = (ans * 2) % mod;
                dfs(i);
            }
        }

        printf("%d\n", ans);
        for(int i = 1 ; i <= n ; i++){
            vis[i] = false;
        }
    }

    return 0;
}