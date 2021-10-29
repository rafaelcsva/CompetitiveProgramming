#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
int dis[N][N];
vector< pair< int, int > > adj[N];
priority_queue< pair< int, int > > pq;
const int inf = int(1e9);
int out[N];

void dijkstra(int root){
    for(int i = 0 ; i < N ; i++){
        dis[root][i] = inf;
    }

    dis[root][root] = 0;
    pq.push({0, root});

    while(!pq.empty()){
        auto u = pq.top();
        // printf("%d\n", u.second);
        pq.pop();

        if(-u.first != dis[root][u.second]){
            // printf("continue!\n");
            continue;
        }

        for(auto v: adj[u.second]){
            // printf("v: %d, %d\n", v.first, dis[root][v.first]);
            if(dis[root][v.first] > dis[root][u.second] + v.second){
                dis[root][v.first] = dis[root][u.second] + v.second;
                pq.push({-dis[root][v.first], v.first});
            }
        }
    }
}
int main(){
    memset(out, -1, sizeof out);
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; i++){
        int ai, bi, ci;

        scanf("%d %d %d", &ai, &bi, &ci);
        if(ai == bi){
            out[ai] = out[ai] == -1 ? ci : min(out[ai], ci); 
        }else
            adj[ai].push_back({bi, ci});
    }

    for(int i = 1 ; i <= n ; i++){
        dijkstra(i);
    }

    for(int i = 1 ; i <= n ; i++){
        int best = out[i] == -1 ? inf : out[i];

        for(int j = 1 ; j <= n ; j++){
            if(j == i) continue;

            best = min(best, dis[i][j] + dis[j][i]);
        }

        if(best == inf){
            printf("-1\n");
        }else{
            printf("%d\n", best);
        }
    }

    return 0;
}