#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

struct FlowEdge {
    int v, u;
    int cap, flow = 0;

    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 1e9;
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

    void clear(){
        edges.clear();

        adj.clear();
        level.clear();
        ptr.clear();

        adj.resize(n);
        level.resize(n);
        ptr.resize(n);

        m = 0;
    }

    void add_edge(int v, int u, int cap){
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs(){
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int id: adj[v]){
                if(edges[id].cap - edges[id].flow < 1)
                    continue;
                if(level[edges[id].u] != -1){
                    continue;
                }
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int pushed){
        if(pushed == 0){
            return 0;
        }
        if(v == t){
            return pushed;
        }
        for(int &cid = ptr[v]; cid < (int)adj[v].size() ; cid++){
            int id = adj[v][cid];
            int u = edges[id].u;
            if(level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1){
                continue;
            }
            int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if(tr == 0){
                continue;
            }
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int flow(){
        int f = 0;
        while(true){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if(!bfs()){
                break;
            }
            fill(ptr.begin(), ptr.end(), 0);
            while(int pushed = dfs(s, flow_inf)){
                f += pushed;
            }
        }
        return f;
    }
};

const int N = 5010;
pii edges[N];
int n, m;
vector< int > ans;

bool can(int x, Dinic &ronaldo, bool get_ans = false){
    for(int i = 1 ; i <= n ; i++){
        ronaldo.add_edge(ronaldo.s, i, x);
    }

    for(int i = 1 ; i <= m ; i++){
        // if(get_ans)
        //     printf("m em %d \n", ronaldo.m);
        ronaldo.add_edge(edges[i].first, i + n, 1);
        ronaldo.add_edge(edges[i].second, i + n, 1);
    }

    for(int i = 1 ; i <= m ; i++){
        ronaldo.add_edge(i + n, ronaldo.t, 1);
    }

    int r = ronaldo.flow();
    // printf("for %d have %d\n", x, r);
    bool doI = (r >= m);

    if(get_ans){
        int d = 1;

        for(int i = n ; i < n + 2 * m ; i += 2){
            // printf("query em %d <%d, %d>\n", i * 2, ronaldo.edges[i * 2].cap, ronaldo.edges[i * 2].flow);

            if(ronaldo.edges[i * 2].flow == 0){
                swap(edges[d].first, edges[d].second);
            }
            d++;
        }
    }

    ronaldo.clear();

    return doI;
}

int main(){
    scanf("%d %d", &n, &m);

    Dinic ronaldo(n + m + 4, n + m + 2, n + m + 3);

    for(int i = 1 ; i <= m ; i++){
        scanf("%d %d", &edges[i].first, &edges[i].second);
    }

    int lo = 0, hi = m;
    int r = -1;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        if(can(mid, ronaldo)){
            r = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    can(r, ronaldo, true);

    printf("%d\n", r);

    for(int i = 1 ; i <= m ; i++){
        printf("%d %d\n", edges[i].first, edges[i].second);
    }

    return 0;
}