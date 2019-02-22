//27, 11, 2018, 18:32:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
vector< int > ts;
enum Color{WHITE, BLACK};
int color[N];
vector< int > adj[N], rev[N], nadj[N];
int bel[N], sz[N];
int dp[N];
int used[N];
int comp[N];
int test = 1;

void dfs(int u){
    color[u] = BLACK;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(color[v] == WHITE){
            dfs(v);
        }
    }

    ts.push_back(u);
}

void dfs_rev(int u, int comp){
    bel[u] = comp;
    // cout << comp << " ++" << endl; ./
    sz[comp]++;
    // cout << " = " << sz[comp] << endl;

    for(int i = 0 ; i < rev[u].size() ; i++){
        int v = rev[u][i];

        if(bel[v] == WHITE){
            dfs_rev(v, comp);
        }
    }
}

int solve(int u){
    int &ans = dp[u];

    if(used[u] == test){
        return ans;
    }

    used[u] = test;
    ans = sz[u];

    for(int i = 0 ; i < nadj[u].size() ; i++){
        int v = nadj[u][i];
        // printf("%d->%d\n", u, v);

        ans = max(ans, sz[u] + solve(v));
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < m ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            rev[v].push_back(u);
        }

        for(int i = 1 ; i <= n ; i++){
            if(color[i] == WHITE){
                dfs(i);
            }
        }

        int comp_v = 0;
        // cout << "sz = " << ts.size() << endl;

        for(int i = n - 1 ; i >= 0 ; i--){
            int u = ts[i];

            if(bel[u] == WHITE){
                dfs_rev(u, ++comp_v);
            }
        }

        // for(int i = 1 ; i <= comp_v ; i++){
        //     cout << "i: " << i << " - " << sz[i] << endl;
        // }

        // for(int i = 1 ; i <= n ; i++){
        //     cout << bel[i] << " ";
        // }
        // cout << endl;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                int v = adj[i][j];

                if(bel[i] != bel[v]){
                    nadj[bel[i]].push_back(bel[v]);
                    // printf("%d->%d\n", bel[i], bel[v]);
                }
            }
        }
        // printf("acabei aqui oh\n");

        int best = 0;

        // cout << sz[1] << " " << comp_v << endl;

        for(int i = 1 ; i <= comp_v ; i++){
            best = max(best, solve(i));
        }

        printf("%d\n", best);

        memset(bel, 0, sizeof bel);
        memset(color, 0, sizeof color);
        memset(sz, 0, sizeof sz);
        memset(dp, 0, sizeof dp);
        
        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
            rev[i].clear();
            nadj[i].clear();
        }

        ts.clear();
        test++;
    }

    return 0;
}