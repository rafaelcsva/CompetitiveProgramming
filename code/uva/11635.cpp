
//30, 11, 2018, 13:21:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e4 + 10, T = 600;
int dis[N][T + 10];
priority_queue< pair<int, pii > >pq;
const int inf = 1e9;
vector< pii >adj[N];
bool is_hotel[N];
bool ver[N][T + 10];
int n;

int dijkstra(){
    memset(ver, false, sizeof ver);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= T ; j++){
            dis[i][j] = inf;
        }
    }

    dis[1][0] = 0;
    pq.push({0, {1, 0}});

    while(!pq.empty()){
        pii u = pq.top().second;
        int ds = -u.first;
        pq.pop();

        if(dis[u.first][u.second] < ds){
            continue;
        }

        for(int i = 0 ; i < adj[u.first].size() ; i++){
            int v = adj[u.first][i].first;
            int w = adj[u.first][i].second;

            if(w + u.second <= T){
                if(dis[v][w + u.second] > dis[u.first][u.second]){
                    dis[v][w + u.second] = dis[u.first][u.second];
                    pq.push({-dis[u.first][w + u.second], {v, w + u.second}});
                }
            }
        }

        if(is_hotel[u.first]){
            if(dis[u.first][0] > dis[u.first][u.second] + 1){
                dis[u.first][0] = dis[u.first][u.second] + 1;
                pq.push({-dis[u.first][0], {u.first, 0}});
            }
        }
    }

    int best = -1;

    for(int i = 0 ; i <= T ; i++){
        if(dis[n][i] != inf){
            if(best == -1){
                best = dis[n][i];
            }else{
                best = min(best, dis[n][i]);
            }
        }
    }

    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true){
        scanf("%d", &n);

        if(n == 0)
            break;

        int sz;

        scanf("%d", &sz);

        for(int i = 0 ; i < sz ; i++){
            int xi;

            scanf("%d", &xi);

            is_hotel[xi] = true;
        }

        int m;

        scanf("%d", &m);

        for(int i = 0 ; i < m ; i++){
            int a, b, w;

            scanf("%d %d %d", &a, &b, &w);

            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        printf("%d\n", dijkstra());

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }

        memset(is_hotel, false, sizeof is_hotel);
    }

    return 0;
}