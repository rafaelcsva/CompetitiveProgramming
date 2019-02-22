//28, 11, 2018, 07:53:17 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 10;
int dis[N][N][N];
vector< pii > pos;
char tab[N][N];
int vi[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int vj[] = {2, -2, 2, -2, 1, -1, 1, -1};
queue< pii > q;
int dp[1 << N][N];
int used[1 << N][N];
int test = 1;

bool ok(int i, int j){
    return 0 <= i && i < 8 && 0 <= j && j < 8 && tab[i][j] != 'K' && tab[i][j] != 'p';
}

void run(int u){
    q.push(pos[u]);
    dis[u][pos[u].first][pos[u].second] = 0;

    while(!q.empty()){
        pii v = q.front();
        q.pop();

        for(int i = 0 ; i < 8 ; i++){
            int xi = v.first + vi[i], xj = v.second + vj[i];

            if(ok(xi, xj)){
                if(dis[u][xi][xj] == -1){
                    dis[u][xi][xj] = dis[u][v.first][v.second] + 1;
                    q.push({xi, xj});
                }
            }
        }
    }
}

int solve(int mask, int cur){
    int sz = int(pos.size());

    if(mask == (1 << sz) - 1){
        return 0;
    }

    int &ans = dp[mask][cur];

    if(used[mask][cur] == test){
        return ans;
    }
    
    used[mask][cur] = test;

    ans = 1e9;

    for(int i = 0 ; i < pos.size() ; i++){
        int e = 1 << i;

        if((mask & e) == 0){
            // printf("aqui\n");
            if(dis[cur][pos[i].first][pos[i].second] != -1){
                
                ans = min(ans, solve(mask | e, i) + dis[cur][pos[i].first][pos[i].second]);
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    while(t--){
        memset(dis, -1, sizeof dis);

        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0 ; j < 8 ; j++){
                scanf("\n%c", &tab[i][j]);

                if(tab[i][j] == 'k'){
                    pos.push_back({i, j});
                }
            }
        }

        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0 ; j < 8 ; j++){
                if(tab[i][j] == 'P'){
                    pos.push_back({i, j});
                }
            }
        }

        for(int i = 0 ; i < pos.size() ; i++){
            run(i);
        }

        int r = solve(1, 0);
        // printf("%d\n", r);

        if(r <= n){
            printf("Yes\n");
        }else{
            printf("No\n");
        }

        pos.clear();
        test++;
    }

    return 0;
}