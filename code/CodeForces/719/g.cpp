#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e3) + 10;
ll dis1[N][N], dis2[N][N];
const ll inf = ll(1e18);
ll tab[N][N];
ll w;
int vi[4] = {0, 0, 1, -1};
int vj[4] = {1, -1, 0, 0};
int n, m;

bool ok(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m && tab[x][y] != -1;
}

ll add(int x, int y){
    return w;
}

void bfs1(){
    priority_queue< pair< ll, pair< int, int > > > pq;
    dis1[1][1] = 0LL;
    pq.push({0LL, {1, 1}});

    while(!pq.empty()){
        auto u = pq.top().second;
        auto d = -pq.top().first;
        pq.pop();

        if(d > dis1[u.first][u.second]) continue;

        for(int i = 0 ; i < 4 ; i++){
            int x = u.first + vi[i];
            int y = u.second + vj[i];

            if(ok(x, y) && dis1[x][y] > dis1[u.first][u.second] + add(u.first, u.second)){
                dis1[x][y] = dis1[u.first][u.second] + add(u.first, u.second);
                pq.push({-dis1[x][y], {x, y}});
            }
        }
    }
}

void bfs2(){
    priority_queue< pair< ll, pair< int, int > > > pq;
    dis2[n][m] = 0LL;
    pq.push({0LL, {n, m}});

    while(!pq.empty()){
        auto u = pq.top().second;
        auto d = -pq.top().first;
        pq.pop();

        if(d > dis2[u.first][u.second]) continue;

        for(int i = 0 ; i < 4 ; i++){
            int x = u.first + vi[i];
            int y = u.second + vj[i];

            if(ok(x, y) && dis2[x][y] > dis2[u.first][u.second] + add(x, y)){
                dis2[x][y] = dis2[u.first][u.second] + add(x, y);
                pq.push({-dis2[x][y], {x, y}});
            }
        }
    }
}

int main(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            dis1[i][j] = dis2[i][j] = inf;
        }
    }

    scanf("%d %d %lld", &n, &m, &w);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            scanf("%lld", &tab[i][j]);
        }
    }

    bfs1();
    bfs2();

    ll best = dis1[n][m];
    // printf("%lld\n", best);

    ll b1 = inf, b2 = inf;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1;  j <= m ; j++){
            if(tab[i][j] > 0){
                b1 = min(b1, dis1[i][j] + tab[i][j]);
                b2 = min(b2, dis2[i][j] + tab[i][j]);
            }
        }
    }

    best = min(best, b1 + b2);

    printf("%lld\n", best < inf ? best : -1);

    return 0;
}