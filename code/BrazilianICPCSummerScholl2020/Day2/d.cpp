#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1010);
int x[N], f[N];

struct FlowEdge {
    int v, u;
    ll cap, flow = 0LL;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = ll(1e18);
    vector< FlowEdge > edges;
    vector< vector< int > > adj;
    int n, m = 0;
    int s, t;
    vector< int > level, ptr;
    queue< int > q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, ll cap){
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0LL);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int id: adj[v]){
                if(edges[id].cap - edges[id].flow < 1){
                    continue;
                }
                if(level[edges[id].u] != -1){
                    continue;
                } 
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }

        return level[t] != -1;
    }

    ll dfs(int v, ll pushed){
        if(pushed == 0){
            return 0;
        }
        if(v == t){
            return pushed;
        }
        for(int &cid = ptr[v] ; cid < int(adj[v].size()) ; cid++){
            int id = adj[v][cid];
            int u = edges[id].u;
            if(level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1){
                continue;
            }
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if(tr == 0){
                continue;
            }
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow(){
        ll f = 0LL;
        while(true){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);

            if(!bfs()){
                break;
            }

            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(s, flow_inf)){
                f += pushed;
            }
        }

        return f;
    }
};

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    Dinic dondoka(n + 2, n, n + 1);

    for(int i = 0 ; i < n ; i++){
        int d = 1;

        for(int j = 0 ; j < k ; j++){
            int vi;

            scanf("%d", &vi);

            x[i] |= d * vi;
            d <<= 1LL;
        }

        scanf("%d", &f[i]);

        if(f[i]){
            dondoka.add_edge(dondoka.s, i, 1);
        }else{
            dondoka.add_edge(i, dondoka.t, 1);
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue;

            if((x[i] & x[j]) == x[i] && f[i] == 1){
                // printf("%d-%d\n", i + 1, j + 1);
                dondoka.add_edge(i, j, n + 2);
            }
        }
    }

    printf("%lld\n", dondoka.flow());

    for(int i = 0 ; i < n ; i++){
        int d = dondoka.level[i] != -1 ? 1 : 0;

        if(d != f[i]){
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}
