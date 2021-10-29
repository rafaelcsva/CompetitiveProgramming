#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
vector< pair< int, ll > > adj[N];
priority_queue<pair< ll, pair< int, ll > >> pq;
ll dis[N][60];
const ll inf = ll(1e16);

void dijkstra(int node){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 60 ; j++){
            dis[i][j] = inf;
        }
    }

    dis[1][0] = 0LL;
    pq.push({0LL, {1, 0LL}});

    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        auto vert = u.second.first;
        auto wg = u.second.second;
        // printf("%d %lld %lu %lld\n", vert, wg, adj[vert].size(), dis[u.second.first][u.second.second]);
        if(-u.first > dis[u.second.first][u.second.second]){
            continue;
        }

        for(auto vv: adj[vert]){
            auto v = vv.first;
            auto w = vv.second;
            ll tr = 0LL;

            if(!wg){
                tr = w;
            }
            
            if(dis[v][tr] > dis[vert][wg] + 2LL * wg * w + w * w){
                dis[v][tr] = dis[vert][wg] + 2LL * wg * w + w * w;
                pq.push({-dis[v][tr], {v, tr}});
            }
        }
    }
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; i++){
        int ui, vi;
        ll wi;

        scanf("%d %d %lld", &ui, &vi, &wi);

        adj[ui].push_back({vi, wi});
        adj[vi].push_back({ui, wi});
    }

    dijkstra(1);

    for(int i = 1 ; i <= n ; i++){
        printf("%lld ", dis[i][0] < inf ? dis[i][0] : -1LL);
    }
    printf("\n");

    return 0;
}