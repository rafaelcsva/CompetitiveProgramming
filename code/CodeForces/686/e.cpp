#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

vector< int > cicle;
const int N = int(2e5) + 10;
int color[N];
ll sz[N];
vector< int > adj[N];
int scicle = 0;
bool flag[N];

bool dfs1(int u, int ft){
    color[u] = 1;

    for(int v: adj[u]){
        if(v == ft) continue;

        if(color[v]){
            flag[u] = true;
            cicle.push_back(u);
            scicle = v;
            return true;
        }

        if(dfs1(v, u)){
            flag[u] = true;
            cicle.push_back(u);
            if(scicle == u){
                scicle = 0;

                return false;
            }

            return true;
        }
    }

    return false;
}

void dfs2(int u){
    color[u] = 2;
    sz[u] = 1LL;

    for(int v: adj[u]){
        // printf("%d->%d\n",u, v);
        if(color[v] == 2 || flag[v]) continue;

        // printf("%d->%d\n",u, v);
        dfs2(v);

        sz[u] += sz[v];
    }
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            int u, v;

            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(1, 1);

        for(int u: cicle){
            dfs2(u);
        }
        
        ll ans = ll(n) * ll(n - 1LL);
        
        for(int u: cicle){
            // printf("-> %d %lld\n", u, sz[u]);
            ans += sz[u] * ll(n - sz[u]);
        }

        ans >>= 1LL;

        printf("%lld\n", ans);

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
            color[i] = flag[i] = 0;
        }

        cicle.clear();
    }

    return 0;
}
