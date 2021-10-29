#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
bool ispecial[N];
vector< int > adj[N];
int sz[N];

int dfs(int u, int ft){
    sz[u] = ispecial[u];

    for(auto v: adj[u]){
        if(v == ft) continue;
    
        sz[u] += dfs(v, u);
    }

    return sz[u];
}

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n - 1 ; i++){
        int u, v, d;

        scanf("%d %d %d", &u, &v, &d);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root;

    for(int i = 0 ; i < k ; i++){
        int ai;

        scanf("%d", &ai);
        ispecial[ai] = true;

        root = ai;
    }

    dfs(root, root);
    
    int cnt = 0;

    for(int i = 1 ; i <= n ; i++){
        if(sz[i] > 0){
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
