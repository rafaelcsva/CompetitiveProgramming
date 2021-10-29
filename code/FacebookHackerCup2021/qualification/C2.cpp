#include <bits/stdc++.h>

using namespace std;

const int N = 52;
int comp[N][N];
int dp[N][N][N][2];
int pre[N];
int depth[N];
int c[N];
int father[N];
vector< int > leafs;

vector< int > adj[N];

int lca(int a, int b){
    if(comp[a][b] != -1){
        return comp[a][b];
    }

    if(a == b){
        return comp[a][b] = a;
    }

    if(depth[a] > depth[b]){
        comp[a][b] = comp[b][a] = lca(father[a], b);
    }else{
        comp[a][b] = comp[b][a] = lca(a, father[b]);
    }

    return comp[a][b];
}

void dfs(int u, int ft, int acc = 0, int dep = 0){
    acc += c[u];
    bool is_leaf = true;

    for(auto v: adj[u]){
        if(v == ft) continue;

        is_leaf = false;
        dfs(v, u, acc, dep + 1);
    }

    if(is_leaf){
        leafs.push_back(u);
    }

    pre[u] = acc;
    depth[u] = dep;
    father[u] = ft;
}

int solve(int u, int lc, int k, int frag = 1){
    int &ans = dp[u][lc][k][frag];

    if(ans != -1){
        return ans;
    }

    ans = pre[leafs[u]] - pre[lc];

    if(k == 0){
        if(lc != 1 || frag){
            return ans = -int(1e9);
        }else{
            return ans;
        }
    }

    int add = 0;

    for(int j = u + 1 ; j < leafs.size() ; j++){
        int l = lca(leafs[u], leafs[j]);

        if(!frag){
            add = max(add, solve(j, l, k - (l != lc), l == lc));
        }else{
            add = max(add, solve(j, l, k - 1, 0));
        }
    }

    ans += add;

    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        memset(comp, -1, sizeof comp);
        memset(dp, -1, sizeof dp);

        int n, k;

        scanf("%d %d", &n, &k);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &c[i]);
        }

        for(int i = 1 ; i < n ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 1);

        int ans = 0;

        if(n == 1 || k == 0){
            ans = c[1];
        }else{
            for(int i = 0 ; i < leafs.size() ; i++){
                ans = max(ans, solve(i, 1, k) + c[1]);
            }
        }

        printf("Case #%d: %d\n", test, ans);

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }
        leafs.clear();
    }

    return 0;
}
