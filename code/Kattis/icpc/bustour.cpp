#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int dis[N][N];
int dp1[N][1 << N];
int dp2[N][1 << N];
int n, m;

int solve(int u, int msk){
    if(msk & (1 << u)){
        msk ^= (1 << u);
    }

    if(msk == 0){
        return dis[u][0];
    }

    int &ans = dp1[u][msk];

    if(ans != -1){
        return ans;
    }

    ans = int(1e9);

    for(int j = 0 ; j < n ; j++){
        int e = 1 << j;

        if((msk & e)){
            ans = min(ans, solve(j, msk ^ e) + dis[u][j]);
        }
    }

    return ans;
}

int solve2(int u, int msk){
    if(msk & (1 << u)){
        msk ^= (1 << u);
    }

    if(msk == 0){
        return dis[u][n - 1];
    }

    int &ans = dp2[u][msk];

    if(ans != -1){
        return ans;
    }

    ans = int(1e9);

    for(int j = 0 ; j < n ; j++){
        int e = 1 << j;

        if((msk & e)){
            ans = min(ans, solve2(j, msk ^ e) + dis[u][j]);
        }
    }

    // printf("ans = %d\n", ans);
    return ans;
}

int test = 1;

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        memset(dis, -1, sizeof dis);
        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);

        vector< int > v;

        for(int i = 0 ; i < m ; i++){
            int ui, vi, ti;

            scanf("%d %d %d", &ui, &vi, &ti);

            dis[ui][vi] = dis[vi][ui] = (dis[ui][vi] == -1 ? ti : min(dis[ui][vi], ti));
        }

        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(i == j){
                        dis[i][j] = 0;
                    }

                    if(dis[i][k] == -1 || dis[k][j] == -1){
                        continue;
                    }

                    dis[i][j] = dis[i][j] == -1 ? dis[i][k] + dis[k][j] : min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int ans = int(1e9);

        for(int mask = 0 ; mask < (1 << n) ; mask++){
            int tot = __builtin_popcount(mask);

            if(mask & 1){
                continue;
            }

            if(mask & (1 << (n - 1))){
                continue;
            }

            if(tot == (n - 2) / 2){    
                int nmask = ((mask ^ ((1 << n) - 1)) ^ 1) ^ (1 << (n - 1));
                // printf("test: %d\n", mask);

                for(int u = 0 ; u < n ; u++){
                    for(int e = 0 ; e < n ; e++){
                        ans = min(ans, solve(u, mask) + solve2(u, nmask) + solve2(e, mask) + solve(e, nmask));
                    }
                }
            }
        }

        printf("Case %d: %d\n", test++, ans);
    }

    return 0;
}