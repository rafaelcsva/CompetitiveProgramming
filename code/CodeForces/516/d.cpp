//14, 10, 2018, 07:52:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair< pii , pii >   pipii;
const int N = 2010;
priority_queue< pipii > pq;
int r, c;
char tab[N][N];
pii dis1[N][N], dis2[N][N];
bool vis1[N][N], vis2[N][N];
const int T = 4;
int vi[T] = {0, 0, 1, -1};
int vj[T] = {1, -1, 0, 0};
int n, m;
const int inf = 1e9 + 10;

bool ok(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m && tab[i][j] == '.';
}

void dijkstra1(){
    pq.push({{0, 0}, {r, c}});
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            dis1[i][j] = {inf, inf};
        }
    }

    dis1[r][c] = {0, 0};

    while(!pq.empty()){
        pipii u = pq.top();
        pq.pop();
        
        pii l = u.second;

        if(vis1[l.first][l.second])
            continue;

        vis1[l.first][l.second] = true;
        int lf = -u.first.first;
        int rg = -u.first.second;

        for(int i = 0 ; i < T ; i++){
            int x = vi[i] + l.first, y = vj[i] + l.second;

            if(ok(x, y)){
                if(vis1[x][y]){
                    continue;
                }

                int ml = lf, mr = rg;

                if(i == 0){
                    mr++;
                }else if(i == 1){
                    ml++;
                }

                pii h = {ml, mr};

                if(dis1[x][y] > h){
                    dis1[x][y] = h;
                    pq.push({{-ml, -mr}, {x, y}});
                }
            }
        }
    }
}

void dijkstra2(){
    pq.push({{0, 0}, {r, c}});
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            dis2[i][j] = {inf, inf};
        }
    }

    dis2[r][c] = {0, 0};

    while(!pq.empty()){
        pipii u = pq.top();
        pq.pop();
        
        pii l = u.second;

        if(vis2[l.first][l.second])
            continue;
            
        vis2[l.first][l.second] = true;
        int lf = -u.first.second;
        int rg = -u.first.first;

        for(int i = 0 ; i < T ; i++){
            int x = vi[i] + l.first, y = vj[i] + l.second;

            if(ok(x, y)){
                if(vis2[x][y]){
                    continue;
                }

                int ml = lf, mr = rg;

                if(i == 0){
                    mr++;
                }else if(i == 1){
                    ml++;
                }

                pii h = {mr, ml};

                if(dis2[x][y] > h){
                    dis2[x][y] = h;
                    pq.push({{-mr, -ml}, {x, y}});
                }
            }
        }
    }
}

bool can(pii u, pii v){
    return u.first <= v.first && u.second <= v.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    scanf("%d %d", &n, &m);

    int x, y;

    scanf("%d %d", &r, &c);
    r--, c--;

    scanf("%d %d", &x, &y);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("\n%c", &tab[i][j]);
        }
    }

    dijkstra1();
    dijkstra2();

    int cnt = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            pii h = {x, y};
            pii v = {y, x};

            if(can(dis1[i][j], h) || can(dis2[i][j], v)){
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}