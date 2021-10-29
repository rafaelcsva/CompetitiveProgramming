#include <bits/stdc++.h>

using namespace std;

template <class T = int>
class MCMF {
public:
    struct Edge {
        int to;
        T cap, cost;
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
            flow.first = min(flow.first, list[from[v]].cap);
            flow.second += list[from[v]].cost;
        }
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

vector< int > v;

int getId(int num){
    return lower_bound(v.begin(), v.end(), num) - v.begin();
}

const int N = 1010;
int s[N], t[N], c[N];

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n ; i++){

        scanf("%d %d %d", &s[i], &t[i], &c[i]);

        t[i] += s[i];
        v.push_back(s[i]);
        v.push_back(t[i]);
    }

    v.push_back(numeric_limits< int >::max());
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));

    MCMF< int > flamengo((int)v.size());

    for(int i = 0 ; i < n ; i++){
        int id1 = getId(s[i]);
        int id2 = getId(t[i]);

        flamengo.addEdge(id1, id2, 1, -c[i]);
    }

    for(int i = 1 ; i < v.size() ; i++){
        flamengo.addEdge(i - 1, i, k, 0);
    }

    auto u = flamengo.mcmf(0, int(v.size()) - 1);

    for(int i = 0 ; i < n ; i++){
        printf("%d ", !flamengo.list[i * 2].cap);
    }
    printf("\n");

    return 0;
}