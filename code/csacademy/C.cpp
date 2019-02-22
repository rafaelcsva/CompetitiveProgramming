#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 100);
int x, y;
vector< int > adj[N], rev[N], new_adj[N];
vector< int > topological_sort;
int color[N];
bool dp[N][2];
int comp = 1;
int bel[N];
int resp[N];

void dfs1(int u, int ft){
    color[u] = 1;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(!color[v]){
            dfs1(v, u);
        }
    }

    topological_sort.push_back(u);
}

void dfs2(int u, int ft){
    // cout << u << ": " << comp << endl;
    bel[u] = comp;
    color[u] = 1;

    for(int i = 0 ; i < rev[u].size() ; i++){
        int v = rev[u][i];

        if(!color[v]){
            dfs2(v, u);
        }
    }
}

void dfs3(int u, int ft){
    color[u] = 1;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(bel[v] != bel[u]){
            assert(v != ft);
            // cout << bel[u] << "->" << bel[v] << endl; 
            new_adj[bel[u]].push_back(bel[v]);
        }

        if(!color[v]){
            dfs3(v, u);
        }
    }
}

void dfs4(int u, int ft){
    color[u] = 1;

    for(int i = 0 ; i < new_adj[u].size() ; i++){
        int v = new_adj[u][i];

        if(!color[v]){
            dfs4(v, u);
        }
    }

    topological_sort.push_back(u);
}

bool can_reach(int u, int target, int ft){
    if(target == u){
        return true;
    }

    bool ok = false;

    for(int i = 0 ; i < new_adj[u].size() ; i++){
        int v = new_adj[u][i];

        if(v == ft){
            continue;
        }

        ok |= can_reach(v, target, u);
    }

    return ok;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;
    cin >> x >> y;

    for(int i = 0 ; i < m ; i++){
        int ui, vi;

        cin >> ui >> vi;

        adj[ui].push_back(vi);
        rev[vi].push_back(ui);
    }

    for(int i = 1 ; i <= n ; i++){
        if(!color[i]){
            dfs1(i, i);
        }
    }

    memset(color, 0, sizeof color);

    for(int i = n - 1 ; i >= 0 ; i--){
        int v = topological_sort[i];

        if(!color[v]){
            // cout << "v: " << v << endl;
            dfs2(v, v);

            comp++;
        }
    }

    memset(color, 0, sizeof color);

    for(int i = 1 ; i <= n ; i++){
        if(!color[i]){
            dfs3(i, i);
        }
    }

    memset(color, 0, sizeof color);
    topological_sort.clear();

    // cout << comp << endl;

    for(int i = 1 ; i < comp ; i++){
        if(!color[i]){
            dfs4(i, i);
        }
    }

    dp[bel[x]][0] = 1;
    dp[bel[x]][1] = can_reach(bel[x], bel[y], bel[x]);
    // cout << dp[bel[x]][1] << " === " << endl;
    dp[bel[y]][1] = 1;
    dp[bel[y]][0] = can_reach(bel[y], bel[x], bel[y]);

    // cout << topological_sort.size() << endl;

    for(int i = 0 ; i < topological_sort.size() ; i++){
        int u = topological_sort[i];
        // cout << u << " " << bel[u] << endl;

        for(int j = 0 ; j < new_adj[u].size() ; j++){
            int v = new_adj[u][j];

            dp[u][0] |= dp[v][0];
            dp[u][1] |= dp[v][1];
        }

        resp[u] = !(dp[u][0]) + !(dp[u][1]);

        if(dp[u][0] && dp[bel[x]][1]){
            resp[u] = 0;
        }

        if(dp[u][1] && dp[bel[y]][0]){
            resp[u] = 0;
        }

        if(dp[bel[x]][1] || dp[bel[y]][0]){
            resp[u] = min(resp[u], 1);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        cout << resp[bel[i]] << " ";
    }

    cout << endl;

    return 0;
}