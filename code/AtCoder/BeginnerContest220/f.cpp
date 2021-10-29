#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
const int M = N << 2;
ll segtree[M];
ll lazzy[M];
int tim = 1;
int depth[N];
int arr[N];
int init[N], en[N];
vector< int > adj[N];
ll ans[N];

void dfs(int u, int ft, int dep){
    init[u] = tim;
    arr[tim] = u;
    depth[u] = dep;

    for(auto v: adj[u]){
        if(v == ft){
            continue;
        }

        tim++;
        dfs(v, u, dep + 1);
    }

    en[u] = tim;
}

void build(int node, int i, int j){
    if(i == j){
        segtree[node] = depth[arr[i]];
    }else{
        int lf = node << 1;
        int rg = lf + 1;
        int mid = (i + j) >> 1;

        build(lf, i, mid);
        build(rg, mid + 1, j);

        segtree[node] = segtree[lf] + segtree[rg];
    }
}

void push(int node, ll q){
    int lf = node << 1;
    int rg = lf + 1;

    segtree[node] += lazzy[node] * q;

    if(lf < M){
        lazzy[lf] += lazzy[node];
    }

    if(rg < M){
        lazzy[rg] += lazzy[node];
    }

    lazzy[node] = 0LL;
}

ll query(int node, int i, int j, int l, int r){
    if(lazzy[node]){
        push(node, j - i + 1LL);
    }

    if(i > r || j < l){
        return 0LL;
    }

    if(i >= l && j <= r){
        return segtree[node];
    }else{
        int lf = node << 1;
        int rg = lf + 1;
        int mid = (i + j) >> 1;

        return query(lf, i, mid, l, r) + query(rg, mid + 1, j, l, r);
    }
}

void update(int node, int i, int j, int l, int r, ll add){
    if(lazzy[node]){
        push(node, j - i + 1LL);
    }

    if(l > r){
        return;
    }

    if(i > r || j < l){
        return;
    }

    if(i >= l && j <= r){
        lazzy[node] = add;
        push(node, j - i + 1LL);
    }else{
        int lf = node << 1;
        int rg = lf + 1;
        int mid = (i + j) >> 1;

        update(lf, i, mid, l, r, add);
        update(rg, mid + 1, j, l, r, add);

        segtree[node] = segtree[lf] + segtree[rg];
    }
}

int n;

void dfs2(int u, int ft){
    if(u != ft){
        update(1, 1, n, init[u], en[u], -1);
        update(1, 1, n, 1, init[u] - 1, 1);
        update(1, 1, n, en[u] + 1, n, 1);
    }

    ans[u] = query(1, 1, n, 1, n);

    for(auto v: adj[u]){
        if(v == ft){
            continue;
        }

        dfs2(v, u);
    }

    if(u != ft){
        update(1, 1, n, init[u], en[u], 1);
        update(1, 1, n, 1, init[u] - 1, -1);
        update(1, 1, n, en[u] + 1, n, -1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1 ; i < n ; i++){
        int ui, vi;

        cin >> ui >> vi;

        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }

    dfs(1, 1, 0);

    build(1, 1, n);

    dfs2(1, 1);

    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}