#include <bits/stdc++.h>

using namespace std;

vector< vector< int > > paths;

template <class T = int>
class MCMF {
public:
    struct Edge {
        int to;
        T cap, cost;
        bool mark = false;
        Edge(int a, int b, int c) : to(a), cap(b), cost(c){}
    };

    MCMF(int size){
        n = size;
        edges.resize(n);
        pot.assign(n, 0);
        dist.resize(n);
        visit.assign(n, false);
    }

    pair< T, T > mcmf(int src, int sink){
        pair< T, T > ans(0, 0);
        while(SPFA(src, sink)){
            auto flow = augment(src, sink);
            // printf("add %d, %d\n", flow.first, flow.first * flow.second);
            ans.first += flow.first;
            ans.second += flow.first * flow.second;
        }
        return ans;
    }

    void addEdge(int from, int to, T cap, T cost){
        edges[from].push_back(list.size());
        list.push_back(Edge(to, cap, cost));
        edges[to].push_back(list.size());
        list.push_back(Edge(from, 0, -cost));
    }

    int n;
    vector< vector< int > > edges;
    vector< Edge > list;
    vector< int > from;
    vector< T > dist, pot;
    vector< bool > visit;

    pair< T, T > augment(int src, int sink){
        pair< T, T > flow = {list[from[sink]].cap, 0};
        for(int v = sink; v != src ; v = list[from[v] ^ 1].to){
            // printf("%d\n", list[from[v] ^ 1].to);
            flow.first = min(flow.first, list[from[v]].cap);
            flow.second += list[from[v]].cost;
        }
        // printf("--\n");
        for(int v = sink ; v != src ; v = list[from[v] ^ 1].to){
            list[from[v]].cap -= flow.first;
            list[from[v] ^ 1].cap += flow.first;
        }
        return flow;
    }

    queue< int > q;
    bool SPFA(int src, int sink){
        T INF = numeric_limits< T >::max();
        dist.assign(n, INF);
        from.assign(n, -1);
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            int on = q.front();
            q.pop();
            visit[on] = false;
            for(auto e: edges[on]){
                auto ed = list[e];
                if(ed.cap == 0) continue;
                T toDist = dist[on] + ed.cost + pot[on] - pot[ed.to];
                if(toDist < dist[ed.to]){
                    dist[ed.to] = toDist;
                    from[ed.to] = e;
                    if(!visit[ed.to]){
                        visit[ed.to] = true;
                        q.push(ed.to);
                    }
                }
            }
        }

        return dist[sink] < INF;
    }
};

void dfs(int u, vector< int > &v, MCMF< int > &m){
    // printf("u: %d\n", u);
    for(auto e: m.edges[u]){
        if(e & 1) continue;
    
        auto &ed = m.list[e];

        if(ed.cap == 0 && !ed.mark){
            // printf("walk (%d) -> (%d)\n", u, ed.to);
            ed.mark = true;
            dfs(ed.to, v, m);
            break;
        }
    }

    if((u & 1) == 0){
        v.push_back(u / 2);
    }
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    MCMF< int > michaelJackson(2 * n + 2);

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    a--, b--, c--;

    int source = 2 * c + 1, sink = 2 * n;

    for(int i = 0 ; i < m ; i++){
        int xi, yi, li;

        scanf("%d %d %d", &xi, &yi, &li);

        xi--, yi--;

        michaelJackson.addEdge(2 * xi + 1, 2 * yi, 1, li);
        michaelJackson.addEdge(2 * yi + 1, 2 * xi, 1, li);
    }

    for(int i = 0 ; i < n ; i++){
        michaelJackson.addEdge(i * 2, i * 2 + 1, 1, 0);
    }

    michaelJackson.addEdge(a * 2 + 1, sink, 1, 0);
    michaelJackson.addEdge(b * 2 + 1, sink, 1, 0);

    auto u = michaelJackson.mcmf(source, sink);

    if(u.first != 2){
        printf("-1\n");
        return 0;
    }

    vector< int > v1, v2;
    dfs(source, v1, michaelJackson);
    v1.push_back(source / 2);
    dfs(source, v2, michaelJackson);
    v2.push_back(source / 2);

    paths.push_back(v1);
    paths.push_back(v2);

    vector< vector< int > > mpaths;

    for(auto u: paths){
        vector< int > path;

        for(auto e: u){
            if(e < n){
                path.push_back(e);
            }
        }
        mpaths.push_back(path);
    }

    // printf("%lu\n", mpaths.size());
    if(mpaths[0][0] != a){
        swap(mpaths[0], mpaths[1]);
    }

    // assert(mpaths[0][0] == a && mpaths[1][0] == b && *mpaths[0].rbegin() == c && *mpaths[1].rbegin() == c);
    mpaths[1].pop_back();
    reverse(mpaths[1].begin(), mpaths[1].end());

    printf("%d %d\n", int(mpaths[0].size()) + int(mpaths[1].size()) - 1, u.second);

    for(auto x: mpaths[0]){
        printf("%d ", x + 1);
    }
    for(auto x: mpaths[1]){
        printf("%d ", x + 1);
    }
    printf("\n");

    return 0;
}