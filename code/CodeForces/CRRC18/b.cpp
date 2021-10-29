#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

const int N = 502;
pii p[N * N];
int tab[N][N];
int vis[N][N];
int vi[4] = {0, 0, -1, 1};
int vj[4] = {1, -1, 0, 0};

bool bfs(int n){
    queue< pii > q;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(tab[i][j] == 2){
                vis[i][j] = 1;
                q.push({i, j});
            }else{
                vis[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        auto u = q.front();
        q.pop();

        if(u.first == 0 || u.first == n - 1 || u.second == 0 || u.second == n - 1){
            return true;
        }

        for(int d = 0 ; d < 4 ; d++){
            int x = u.first + vi[d];
            int y = u.second + vj[d];

            if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && tab[x][y]){
                vis[x][y] = 1;
                q.push({x, y});
            }
        }
    }

    q.pop();

    return false;
}

void make_tab(int pos, int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            tab[i][j] = tab[i][j] == 2 ? 2 : 0;
        }
    }

    for(int i = 1 ; i <= pos ; i++){
        tab[p[i].first][p[i].second] = 1;
    }
}

int main(){
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0 ; i < m ; i++){
        int xi, yi;

        scanf("%d %d", &xi, &yi);

        tab[xi][yi] = 2;
    }

    for(int i = 1 ; i <= k ; i++){
        scanf("%d %d", &p[i].first, &p[i].second);
    }

    int ans = 0;

    int lo = 0, hi = k;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        make_tab(mid, n);

        if(bfs(n)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}