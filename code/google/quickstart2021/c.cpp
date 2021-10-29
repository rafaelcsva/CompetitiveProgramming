#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = 310;
ll g[N][N];
bool marked[N][N];
priority_queue< pair< int, pair< int, int > > > pq;
int vi[4] = {-1, 1, 0, 0};
int vj[4] = {0, 0, -1, 1};

bool ok(int x, int y, int r, int c){
    return 0 <= x && x < r && 0 <= y && y < c;
}

int main(){
    int t;
    int test = 1;

    scanf("%d", &t);

    while(t--){
        int r, c;

        scanf("%d %d", &r, &c);

        ll mx = 0;

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                scanf("%lld", &g[i][j]);
                mx = max(mx, g[i][j]);
            }
        }

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                pq.push({g[i][j], {i, j}});
            }
        }

        ll ans = 0LL;
        // printf("%lu\n", pq.size());
        while(!pq.empty()){
            auto u = pq.top().second;
            auto d = pq.top().first;
            pq.pop();

            if(d < g[u.first][u.second]){
                continue;
            }

            // printf("%d %d\n", u.first, u.second);

            for(int i = 0 ; i < 4 ; i++){
                int x = vi[i] + u.first;
                int y = vj[i] + u.second;

                if(ok(x, y, r, c) && !marked[x][y]){
                    marked[x][y] = true;
                    if(g[x][y] < g[u.first][u.second]){
                        ans += g[u.first][u.second] - 1 - g[x][y];
                        g[x][y] = g[u.first][u.second] - 1;
                    }

                    pq.push({g[x][y], {x, y}});
                }
            }
        }

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                marked[i][j] = false;
            }
        }

        printf("Case #%d: %lld\n", test++, ans);
    }

    return 0;
}