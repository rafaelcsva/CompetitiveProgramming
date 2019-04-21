//23, 02, 2019, 11:28:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair< int, pii >    pipii;
typedef pair< int, pipii > node;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
int dis[N][N][3];
queue< pipii > q;
int n, m;
const int inf = 1e9;
string a[N];

bool ok(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == '1';
}

void dijkstra(int x, int y){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            dis[i][j][0] = dis[i][j][1] = dis[i][j][2] = -1;
        }
    }

    dis[x][y][0] = 0;

    q.push({0, {x, y}});

    while(!q.empty()){
        pipii u = q.front();
        q.pop();

        int x = u.second.first;
        int y = u.second.second;

        if(u.first == 0){
            if(ok(x - 1, y) && ok(x - 2, y)){//up
                if(dis[x - 1][y][2] == -1){
                    dis[x - 1][y][2] = dis[x][y][0] + 1;
                    q.push({2, {x - 1, y}});
                }
            }

            if(ok(x, y + 1) && ok(x, y + 2)){//left
                if(dis[x][y + 1][1] == -1){
                    dis[x][y + 1][1] = dis[x][y][0] + 1;
                    q.push({1, {x, y + 1}});
                }
            }

            if(ok(x + 1, y) && ok(x + 2, y)){
                if(dis[x + 2][y][2] == -1){
                    dis[x + 2][y][2] = dis[x][y][0] + 1;
                    q.push({2, {x + 2, y}});
                }
            }

            if(ok(x, y - 1) && ok(x, y - 2)){
                if(dis[x][y - 2][1] == -1){
                    dis[x][y - 2][1] = dis[x][y][0] + 1;
                    q.push({1, {x, y - 2}});
                }
            }
        }else if(u.first == 1){
            if(ok(x - 1, y) && ok(x - 1, y + 1)){
                if(dis[x - 1][y][1] == -1){
                    dis[x - 1][y][1] = dis[x][y][1] + 1;
                    q.push({1, {x - 1, y}});
                }
            }

            if(ok(x, y + 1)){
                if(dis[x][y + 1][0] == -1){
                    dis[x][y + 1][0] = dis[x][y][1] + 1;
                    q.push({0, {x, y + 1}});
                }
            }

            if(ok(x + 1, y) && ok(x + 1, y + 1)){
                if(dis[x + 1][y][1] == -1){
                    dis[x + 1][y][1] = dis[x][y][1] + 1;
                    q.push({1, {x + 1, y}});
                }
            }

            if(ok(x, y - 1)){
                if(dis[x][y - 1][0] == -1){
                    dis[x][y - 1][0] = dis[x][y][1] + 1; 
                    q.push({0, {x, y - 1}});
                }
            }
        }else{
            if(ok(x - 1, y)){
                if(dis[x - 1][y][0] == -1){
                    dis[x - 1][y][0] = dis[x][y][2] + 1;
                    q.push({0, {x - 1, y}});
                }
            }

            if(ok(x, y + 1) && ok(x - 1, y + 1)){
                if(dis[x][y + 1][2] == -1){
                    dis[x][y + 1][2] = dis[x][y][2] + 1;
                    q.push({2, {x, y + 1}});
                }
            }

            if(ok(x + 1, y)){
                if(dis[x + 1][y][0] == -1){
                    dis[x + 1][y][0] = dis[x][y][2] + 1;
                    q.push({0, {x + 1, y}});
                }
            }

            if(ok(x, y - 1) && ok(x - 1, y - 1)){
                if(dis[x][y - 1][2] == -1){
                    dis[x][y - 1][2] = dis[x][y][2] + 1;
                    q.push({2, {x, y - 1}});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        cin >> n >> m;
        int x, y;

        cin >> x >> y;
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
        }

        dijkstra(x, y);

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){

                if(a[i][j] == 0){
                    cout << -1 <<  " ";
                    continue;
                }

                int mn = inf;

                if(dis[i][j][0] != -1){
                    mn = min(mn, dis[i][j][0]);
                }

                if(ok(i - 1, j)){
                    if(dis[i][j][2] != -1){
                        mn = min(dis[i][j][2], mn);
                    }
                }

                if(ok(i + 1, j)){
                    if(dis[i + 1][j][2] != -1){
                        mn = min(dis[i + 1][j][2], mn);
                    }
                }

                if(ok(i, j + 1)){
                    if(dis[i][j][1] != -1){
                        mn = min(dis[i][j][1], mn);
                    }
                }

                if(ok(i, j - 1)){
                    if(dis[i][j - 1][1] != -1){
                        mn = min(dis[i][j - 1][1], mn);
                    }
                }

                if(mn != inf){
                    cout << mn << " ";
                }else{
                    cout << -1 << " " ;
                }
            }

            cout << endl;
        }
    }
    
    return 0;
}