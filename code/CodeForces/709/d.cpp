#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 610;

const ll inf = ll(1e18);
ll dis[N][N];
int u[N * N], v[N * N];
ll l[N * N];
vector< pair< pair< int, int >, ll > > edges;
vector< pair< int, ll > > g[N];
bool taked[N * N];

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n + 1 ; i++){
        for(int j = i + 1 ; j <= n + 1 ; j++){
            dis[i][j] = dis[j][i] = inf;
        }
    }

    for(int i = 0 ; i < m ; i++){
        int u, v;
        ll w;

        scanf("%d %d %lld", &u, &v, &w);
    
        dis[u][v] = w;
        dis[v][u] = w;
        
        edges.push_back({{u, v}, w});
    }

    int q;

    scanf("%d", &q);

    ll M = 0LL;

    for(int i = 0 ; i < q ; i++){
        scanf("%d %d %lld", &u[i], &v[i], &l[i]);

        g[u[i]].push_back({v[i], l[i]});
        M = max(M, l[i]);
    }

    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    // printf("%d\n", M);

    for(int i = 1 ; i <= n ; i++){
        if(g[i].size() == 0) continue;

        for(int j = 1 ; j <= n ; j++){
            dis[j][n + 1] = inf;

            for(auto u: g[i]){
                dis[j][n + 1] = min(dis[j][n + 1], dis[j][u.first] + M - u.second);
            }
        }

        // for(int d = 1 ; d <= n ; d++){
        //     printf("(%d) d: %lld %lld %lld %d\n", d, dis[d][n + 1], dis[d][d], M - g[i][0].second, g[i][0].first);
        // }
        // printf("----\n");

        for(int j = 0 ; j < edges.size() ; j++){
            auto e = edges[j];
            bool frag = false;

            if(dis[i][e.first.first] + e.second + dis[e.first.second][n + 1] <= M){
                taked[j] = true;
            }

            if(dis[i][e.first.second] + e.second + dis[e.first.first][n + 1] <= M){
                taked[j] = true;
            }
        }
    }

    int cnt = 0;

    for(int j = 0 ; j < edges.size() ; j++){
        if(taked[j]){
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}