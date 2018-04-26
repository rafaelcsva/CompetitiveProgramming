#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3000;
typedef pair<int, int> pii;
int dis[N][N];
const int INF = int(1e8);
int n, m;

void print(int i, int j){
    cout << "(" << i << ", " << j << ")" << endl;
}

int findMax(int i){
    int x = -1;

    for(int j = 0 ; j < 2 * n ; j++){
        x = max(x, dis[i][j]);
    }
    cout << x << endl;
    return x;
}

int main(){
    int t;
    int test = 1;

    ios::sync_with_stdio(false);

    cin >> t;

    while(t--){
        cin >> n >> m;

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                dis[i][j] = INF;
            }
        }

        for(int i = 0 ; i < m ; i++){
            int u, v;

            cin >> u >> v;

            dis[u][n] = 1;
            dis[n][u] = 1;
            dis[v][n] = 1;
            dis[n][v] = 1;
            n++;
        }

        int ma = INF;

        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            int second = 0, first = 0;

            for(int k = 0 ; k < n - m ; k++){
                if(i == k){
                    continue;
                }
                
                if(dis[i][k] >= first){
                    second = first;
                    first = dis[i][k];
                }else if(second < dis[i][k]){
                    second = dis[i][k];
                }
            }
    
            ma = min(second + first, ma);
        }
        
        cout << "Case #" << test++ << ":" << endl;
        cout << ma / 2 << endl << endl;
    }

    return 0;
}