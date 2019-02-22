//06, 02, 2019, 18:33:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
vector< int > adj[N], s1;
int vis[N];
int match[N];

int Aug(int u){
    if(vis[u]){
        return 0;
    }

    vis[u] = 1;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(match[v] == -1 || Aug(match[v])){
            match[v] = u;
            return 1;
        }
    }

    return 0;
}

void dfs(int u, int father, int color){
    if(color){
        s1.push_back(u);
    }

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(v == father){
            continue;
        }

        dfs(v, u, !color);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    while(scanf("%d", &n) != EOF){
        if(n == 0)
            break;

        for(int i = 1 ; i <= n ; i++){
            int sz;

            scanf("%d", &sz);

            for(int j = 0 ; j < sz ; j++){
                int v;

                scanf("%d", &v);

                adj[i].push_back(v);
            }
        }

        if(n == 1){
            printf("1\n");
            continue;
        }

        dfs(1, 1, 1);

        memset(match, -1, sizeof match);

        int mcbm = 0;

        for(int i = 0 ; i < s1.size() ; i++){
            int u = s1[i];

            memset(vis, 0, sizeof vis);

            mcbm += Aug(u);
        }

        printf("%d\n", mcbm);

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }

        s1.clear();
    }

    return 0;
}