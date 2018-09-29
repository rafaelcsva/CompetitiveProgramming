//08, 08, 2018, 16:07:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

vector< vector< int > > adj;
const int N = int(2e5 + 10);
vector< int > marked;
vector< vector< ll > > vertices;
int st[N], en[N];
map< pii, ll > mp;
bool vis[N], vis1[N];
int flag[N];
int father[N];
int point[N];
bool is_free[N];
vector< pii > edges;
ll sz[N];
int cycle = 1;

int dfs(int u, int p){
    vis[u] = true;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(v == p)
            continue;

        if(flag[v])
            continue;

        if(vis[v]){
            flag[u] = v;
            marked.push_back(u);
            
            return v;
        }

        int r = dfs(v, u);

        if(r != 0){
            marked.push_back(u);
            flag[u] = r;

            if(r != u)
                return r;
            else    
                return 0;
        }
    }

    return 0;
}

void tour(int u, ll &cnt, int head){
    vis1[u] = true;
    point[u] = head;
    cnt++;
    st[u] = vertices[head].size();
    
    if(flag[u]){
        vertices[head].push_back(u);
    }

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(father[u] == v)
            continue;

        if(flag[u] == flag[v] && flag[u] != 0){
            vertices[head].push_back(v);
        }else{
            // printf("%d eh meu pai (%d) agora eh %d\n", u, v, father[v]);
            father[v] = u;
            ll first = cnt;

            // printf("%d->%d\n", u, v);
            tour(v, cnt, head);

            mp[{u, v}] = cnt - first;
        }
    }

    en[u] = int(vertices[head].size()) - 1;
}

ll pref(int u){
    int ft = point[u];

    if(st[u] > en[u]){
        return 0LL;
    }

    // if(st[u] < 0 || en[u] >= vertices[ft].size()){
    //     printf("error\n");
    //     exit(0);
    // }
    if(st[u] == 0LL){
        return vertices[ft][en[u]];
    }else{
        // if(st[u] < 0 || en[u] >= vertices[ft].size()){
        //     printf("error\n");
        //     exit(0);
        // }
        return vertices[ft][en[u]] - vertices[ft][st[u] - 1];
    }
}

ll pref_out(int u){
    ll a = pref(u);
    int ft = point[u];
    // if(u == 6){
    //     printf("valor = %d\n", vertices[ft][vertices[ft].size() - 1]);
    // }
    return vertices[ft][vertices[ft].size() - 1] - a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        adj.resize(n + 1);
        vertices.resize(n + 1);

        for(int i = 0 ; i < m ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);

            edges.push_back({u, v});
        }

        for(int i = 1 ; i <= n ; i++){
            if(!vis[i]){
                dfs(i, i);
            }
        }
        
        for(int i = 0 ; i < marked.size() ; i++){
            int u = marked[i];
            ll cnt = 0;
            // printf("%d belongs to a cycle true(%d)\n", u, flag[u]);
            cycle++;
            if(!vis1[u]){
                vis1[u] = true;
                father[u] = u;
                point[u] = u;
                
                tour(u, cnt, u);

                sz[u] = cnt;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            ll cnt = 0;

            if(!vis1[i] && adj[i].size() == 1){
                is_free[i] = true;
                vis1[i] = true;
                father[i] = i;
                point[i] = i;
                
                tour(i, cnt, i);

                sz[i] = cnt;
            }
        }
        
        for(int i = 1 ; i <= n ; i++){
            if(point[i] == i){
                for(int j = 0 ; j < vertices[i].size() ; j++){
                    int u = vertices[i][j];

                    if(point[u] != i){
                        vertices[i][j] = sz[point[u]];
                    }else{
                        vertices[i][j] = 0;
                    }

                    if(j){
                        vertices[i][j] += vertices[i][j - 1];
                    }
                }
            }
        }

        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i].first, v = edges[i].second;

            if(is_free[point[u]]){
                if(father[u] == v){
                    swap(u, v);
                }
                
                printf("%lld\n", mp[{u, v}] * (sz[point[u]] - mp[{u, v}]));
            }else if(flag[u] == flag[v] && flag[u] != 0){
                printf("%lld\n", sz[point[u]] * sz[point[v]]);
            }
            else{
                // printf("vai dar ruim\n");
                if(father[u] == v){
                    // printf("swaped (%d, %d)\n", u, v);
                    swap(u, v);
                }

                ll c1 = 0LL, c2 = 0LL, c3 = 0LL;

                c1 = mp[{u, v}] * (sz[point[u]] - mp[{u, v}]);
                c2 = pref(v) * (sz[point[u]] - mp[{u, v}]);
                // if(i == 5){
                // printf("o pref eh %lld (%d) o size eh %lld, n vertices = %lu\n", pref_out(v), v, sz[father[u]], vertices[father[v]].size());
                // }
                
                c3 = mp[{u, v}] * pref_out(v);

                printf("%lld\n", c1 + c2 + c3);
            }
        }
        
        vertices.clear();
        adj.clear();
        marked.clear();
        edges.clear();
        mp.clear();

        memset(vis1, false, sizeof vis1);
        memset(vis, false, sizeof vis);
        memset(flag, 0, sizeof flag);
        memset(father, 0, sizeof father);
        memset(is_free, false, sizeof is_free);
        memset(point, 0, sizeof point);
    }

    return 0;
}