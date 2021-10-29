#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector< int > depth;

void dfs(int v, int p, int dep = 0)
{
    depth[v] = dep;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, dep + 1);
    }

    tout[v] = ++timer;
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
    tin.resize(n);
    tout.resize(n);
    depth.resize(n, 0);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

const int N = 210;
const ll inv2 = ll(500000004LL);
const ll mod = ll(1e9) + 7LL;

ll fast_expo(ll x, ll e){
    ll r = 1LL;
    ll b = x;

    while(e){
        if(e & 1LL){
            r = (r * b) % mod;
        }

        b = (b * b) % mod;
        e >>= 1LL;
    }

    return r;
}

ll dp[N][N];

int main(){
    for(int i = 1 ; i < N ; i++){
        dp[i][0] = 1LL;
    }

    for(int i = 1 ; i < N ; i++){
        for(int j = 1 ; j < N ; j++){
            dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) * inv2) % mod;
        }
    }

    scanf("%d", &n);

    adj.resize(n);

    for(int i = 0 ; i < n - 1 ; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0LL;

    for(int i = 0 ; i < n ; i++){
        preprocess(i);

        for(int a = 0 ; a < n ; a++){
            for(int b = 0 ; b < a ; b++){
                int u = lca(a, b);
                int y = depth[a] - depth[u];
                int x = depth[b] - depth[u];

                ans += dp[x][y];
            
                if(ans >= mod){
                    ans -= mod;
                }
            }
        }
    }

    printf("%lld\n", (ans * fast_expo(n, mod - 2)) % mod);

    return 0;
}