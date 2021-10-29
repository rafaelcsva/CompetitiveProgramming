#include <bits/stdc++.h>

using namespace std;

const int N = int(8e5) + 10;
int n, l;
queue< int > leafs;
int father[N], son[N];
vector<vector<int>> adj;
vector< int > con[N];
int pre[N];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    father[v] = p;
    bool is_leaf = true;

    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p){
            is_leaf = false;
            dfs(u, v);
        }
    }

    tout[v] = ++timer;

    if(is_leaf){
        leafs.push(v);
    }
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.clear();
    tout.clear();
    up.clear();

    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        scanf("%d", &n);

        adj.resize(n + 1);

        for(int i = 0 ; i < n - 1 ; i++){
            int ui, vi;

            scanf("%d %d", &ui, &vi);
            ui--, vi--;
        
            adj[ui].push_back(vi);
            adj[vi].push_back(ui);
        }

        preprocess(0);

        for(int i = 0 ; i < n ; i++){
            int bi;

            scanf("%d", &bi);

            con[bi].push_back(i);

            son[i] = int(adj[i].size()) - (i != 0);
        }

        for(int i = 1 ; i <= n ; i++){
            int rt = -1;

            for(auto u: con[i]){
                if(rt == -1){
                    rt = u;
                }else{
                    rt = lca(rt, u);
                }
            }

            for(auto u: con[i]){
                pre[rt]--;
                pre[u]++;
            }
        }
        
        int ans = 0;

        while(!leafs.empty()){
            auto u = leafs.front();
            leafs.pop();

            if(u == 0){
                break;
            }

            // printf("%d\n", u + 1);

            if(pre[u] == 0){
                // printf("rmv %d-%d\n", u + 1, father[u] + 1);
                ans++;
            }

            pre[father[u]] += pre[u];
            son[father[u]]--;

            if(son[father[u]] == 0){
                leafs.push(father[u]);
            }
        }

        printf("Case #%d: %d\n", test, ans);

        for(int i = 0 ; i <= n ; i++){
            pre[i] = 0;
            con[i].clear();
            adj[i].clear();
            son[i] = 0;
        }

        adj.clear();
    }

    return 0;
}
