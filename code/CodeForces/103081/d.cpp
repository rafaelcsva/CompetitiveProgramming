#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
    int v, wi, idx;
};

const int N = int(1e5) + 20;
vector< Edge > adj[N];
const int inf = int(1e9);

priority_queue< pair< int, int > > pq;
int dis[N];

void dijkstra(){
    pq.push({0, 0});

    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();

        if(-u.first > dis[u.second]){
            continue;
        }

        for(auto e: adj[u.second]){
            if(dis[e.v] > e.wi + dis[u.second]){
                dis[e.v] = e.wi + dis[u.second];
                pq.push({-dis[e.v], e.v});
            }
        }
    }
}

int main(){
    for(int i = 1 ; i < N ; i++){
        dis[i] = inf;
    }

    int n, s, l, u;

    scanf("%d %d %d %d", &n, &s, &l, &u);

    for(int d = 0 ; d < s ; d++){
        int ui, vi;
        int wi;

        scanf("%d %d %d", &ui, &vi, &wi);

        adj[ui].push_back({vi, wi, d});
        adj[vi].push_back({ui, wi, d});
    }

    dijkstra();

    set< int > take_edges;

    for(int i = 0 ; i < n ; i++){
        // printf("entering %d\n", i);
        for(auto e: adj[i]){
            // printf("add %d\n", e.idx);
            if(2 * dis[i] < u || dis[i] + e.wi + dis[e.v] <= u){
                take_edges.insert(e.idx);
            }
        }
    }

    printf("%lu\n", take_edges.size());

    return 0;
}