#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e6) + 10;
int father[N];
vector< int > adj[N];
int a[N], b[N];
int want[N], change[N];
priority_queue< pair< int, int > > q;
bool vis[N];
int bel[N];
bool taked[N];
const ll mod = ll(1e9) + 7LL;
bool has_sons[N];
int deep[N];

void dfs(int u, int ft, int dp = 0){
    father[u] = ft;
    deep[u] = dp;

    for(auto v: adj[u]){
        if(ft != v){
            has_sons[u] = true;
            dfs(v, u, dp + 1);
        }
    }
}

ll solve(int u){
    bool is_tail = true;
    ll sons = 0LL;
    ll ans = 1LL;

    for(auto v: adj[u]){
        if(v == father[u]){
            continue;
        }

        if(bel[v] == bel[u]){
            is_tail = false;
        }

        sons++;
        auto r = solve(v);
        ans = (ans * r) % mod;
    }
    // printf("r: %d %d\n", u, is_tail);
    if(is_tail){
        return ((sons + 1LL) * ans) % mod;
    }

    return ans;
}

int main(){
    memset(bel, -1, sizeof bel);

    int t;

    scanf("%d", &t);

    while(t--){
        int n, s;
        
        scanf("%d %d", &n, &s);

        for(int i = 1 ; i <= n - 1 ; i++){
            int ui, vi;

            scanf("%d %d", &ui, &vi);
        
            adj[ui].push_back(vi);
            adj[vi].push_back(ui);
        }

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
        }

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &b[i]);
        }

        dfs(1, 1);

        for(int i = 1 ; i <= n ; i++){
            if(!has_sons[i]){
                q.push({deep[i], i});
                // printf("pushed %d\n", i);
            }
        }

        bool ver = true;
        int comp = 0;

        while(!q.empty()){
            auto u = q.top().second;
            q.pop();

            if(bel[u] != -1) continue;

            int cur = 0;

            do {
                if(bel[u] != -1){
                    ver = false;
                    break;
                }

                bel[u] = comp;

                if(want[a[u]]){
                    want[a[u]]--;
                    cur--;
                }else{
                    change[a[u]]++;
                }

                if(change[b[u]]){
                    change[b[u]]--;
                }else{
                    want[b[u]]++;
                    cur++;
                }
            
                // printf("%d ", u);
                if(u == 1){
                    ver = (cur == 0);
                    break;
                }

                u = father[u];
            }while(cur != 0);
            // printf("\n-----\n");

            if(!ver) break;

            if(!vis[u]){
                q.push({deep[u], u});
            }

            comp++;
        }

        if(ver){
            if(s == 1){
                printf("1\n");
            }else{
                printf("%lld\n", solve(1));
            }
        }else{
            printf("0\n");
        }

        for(int i = 1 ; i <= n ; i++){
            vis[i] = false;
            taked[i] = false;
            want[b[i]] = change[a[i]] = 0;
            bel[i] = -1;
            adj[i].clear();
            has_sons[i] = false;
        }

        while(!q.empty()){
            q.pop();
        }
    }

    return 0;
}
