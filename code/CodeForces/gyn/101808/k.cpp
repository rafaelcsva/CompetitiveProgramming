#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, ll> pii;
typedef unsigned long long ull;

const int N = int(2e5 + 10);
const int LOGN = 20;
int L[2 * N], E[2 * N], H[N], idx;
int LCA[2 * N][LOGN];
ll dis[N];
int father[2 * N][LOGN];
vector< vector< pii > > adj;

void dfs(int cur, int depth){
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;

    for(int i = 0 ; i < adj[cur].size() ; i++){
        int v = adj[cur][i].first;

        if(H[v] == -1){
            father[v][0] = cur;
            dfs(v, depth + 1);
            E[idx] = cur;
            L[idx++] = depth;
        }
    }
}

void buildRMQ(int n){
    idx = 0;
    memset(H, -1, sizeof H);

    dfs(0, 0);

    n *= 2;

    for(int i = 0 ; i < n ; i++){
        LCA[i][0] = i;
    }

    for(int i = 1 ; (1 << i) <= n ; i++){
        for(int j = 0 ; j + (1 << i) - 1 < n ; j++){
            int sz = 1 << (i - 1);

            if(L[LCA[j][i - 1]] < L[LCA[j + sz][i - 1]]){
                LCA[j][i] = LCA[j][i - 1];
            }else{
                LCA[j][i] = LCA[j + sz][i - 1];
            }
        }
    }
}

void buildParent(int n){
    for(int k = 1 ; k < LOGN ; k++){
        for(int i = 0 ; i < n ; i++){
            father[i][k] = father[father[i][k - 1]][k - 1];
        }
    }
}

int query_parent(int u, int k){
    int cur = u;

    for(int i = 0 ; i < LOGN ; i++){
        int e = 1 << i;

        if(k & e){
            cur = father[cur][i];
        }
    }

    return cur;
}

int query(int u, int v){
    int i = H[u], j = H[v];

    if(i > j){
        swap(i, j);
    }

    int sz = (int)floor(log(double(j - i + 1)) / log(2.0));

    if(L[LCA[i][sz]] < L[LCA[j - (1 << sz) + 1][sz]]){
        return E[LCA[i][sz]];
    }else{
        return E[LCA[j - (1 << sz) + 1][sz]];
    }
}

int ff[N];

int find(int x){
    if(x == ff[x]){
        return x;
    }

    return ff[x] = find(ff[x]);
}

void join(int u, int v){
    int x = find(u);
    int y = find(v);

    if(x != y){
        if(x < y){
            ff[y] = x;
        }else{
            ff[x] = y;
        }
    }
}

struct edge{
    int u, v;
    ll w;
};

void dfs1(int cur, int ft, ll carry){
    dis[cur] = carry;

    for(int i = 0 ; i < adj[cur].size() ; i++){
        int v = adj[cur][i].first;
        ll w = adj[cur][i].second;

        if(v == ft){
            continue;
        }

        dfs1(v, cur, carry + w);
    }
}

ll distance(int u, int v){
    int f = query(u, v);

    ll dist = dis[u] + dis[v] - 2LL * dis[f]; 

    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    edge special;

    while(t--){
        int n, q;
        
        scanf("%d %d", &n, &q);

        for(int i = 0 ; i < n ; i++){
            ff[i] = i;
        }

        adj.resize(n + 1);

        for(int i = 0 ; i < n ; i++){
            int u, v;
            ll w;

            scanf("%d %d %lld", &u, &v, &w);

            u--, v--;

            if(find(u) == find(v)){
                special = {u, v, w};
            }else{
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});

                join(u, v);
            }
        }

        dfs1(0, 0, 0LL);

        buildRMQ(n);
        buildParent(n);

        while(q--){
            int u, v;

            scanf("%d %d", &u, &v);
            u--, v--;
            ll dist1 = distance(u, v);
            ll dist2 = distance(u, special.u) + special.w + distance(special.v, v);
            ll dist3 = distance(u, special.v) + special.w + distance(special.u, v);

            printf("%lld\n", min({dist1, dist2, dist3}));
        }

        for(int i = 0 ; i < n ; i++){
            adj[i].clear();
        }
    }
    
    return 0;
}