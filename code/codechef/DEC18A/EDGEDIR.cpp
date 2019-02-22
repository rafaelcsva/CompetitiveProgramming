//11, 12, 2018, 16:32:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
vector< pii >adj[N];
int cur_set;
set< int > edges;
pii desc[N];
int choosed[N];
int marked[N];
int color[N];
int dir_edge[N];
int cur_deg[N];
int run_exec = 1;
int n, m;
int deg[N];
int discarded[N];
stack< int > p;
int resp[N];
const int mx_set_size = 100;

void run_dfs(int u){
    // printf("U: %d\n", u);
    marked[u] = run_exec;
    cur_set++;

    for(int i = 0 ; i < adj[u].size() ; i++){
        if(cur_set == mx_set_size){
            break;
        }

        int v = adj[u][i].first;
        int ed = adj[u][i].second;

        if(discarded[ed]){
            continue;
        }

        if(marked[v] != run_exec){
            choosed[ed] = run_exec;
            run_dfs(v);
        }
    }
}

void run_alg(){
    memset(deg, 0, sizeof deg);
    memset(cur_deg, 0, sizeof cur_deg);

    for(int i = 0 ; i < m ; i++){
        if(choosed[i] == run_exec){
            deg[desc[i].first]++;
            deg[desc[i].second]++;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(deg[i] == 1){
            p.push(i);
        }
    }

    bool is_ok = false;

    if(cur_set & 1){
        is_ok = true;
    }

    // printf("psize = %lu\n", p.size());

    while(!p.empty()){
        int u = p.top();
        p.pop();

        if(!is_ok){
            for(int i = 0 ; i < adj[u].size() ; i++){
                int v = adj[u][i].first;
                int num = adj[u][i].second;

                if(choosed[num] != run_exec && !discarded[num]){
                    is_ok = true;
                    cur_deg[u]++;

                    // printf("%d, %d %d\n", u, v, cur_deg[u]);
                    choosed[num] = run_exec;

                    if(desc[num].first == u){
                        dir_edge[num] = 1;
                    }

                    discarded[num] = true;
                    break;
                }
            }
        }

        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i].first;
            int num = adj[u][i].second;

            if(choosed[num] == run_exec && !discarded[num]){
                // printf("in %d %d %d\n", u, v, num);
                if(cur_deg[u] & 1){
                    if(desc[num].first == u){
                        dir_edge[num] = 1;
                    }

                    cur_deg[u]++;
                }else{
                    if(desc[num].first != u){
                        dir_edge[num] = 1;
                    }
                    cur_deg[v]++;
                }

                deg[v]--;
                deg[u]--;

                if(deg[v] == 1){
                    p.push(v);
                }

                discarded[num] = true;
                break;
            }
        }
    }

    // for(int i = 1 ; i <= n ; i++){
    //     printf("%d ", deg[i]);
    // }
    // printf("\n");
    for(int i = 0 ; i < m ; i++){
        if(choosed[i] == run_exec){
            edges.erase(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        memset(dir_edge, 0, sizeof dir_edge);
        memset(discarded, false, sizeof discarded);

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < m ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
            desc[i] = {u, v};
            // printf("%d %d %d\n", i, u, v);
            edges.insert(i);
        }
        // return 0;
        if((m & 1) == 0){
            while(edges.size() > 0){
                // printf("sz: %lu\n", edges.size());
                int first = *edges.begin();

                run_dfs(desc[first].first);
                run_alg();

                cur_set = 0;

                run_exec++;
            }

            for(int i = 0 ; i < m ; i++){
                if(dir_edge[i]){
                    swap(desc[i].first, desc[i].second);
                }
                // printf("%d, %d\n", desc[i].first, desc[i].second);
                resp[desc[i].second]++;
            }

            bool ok = true;

            for(int i = 1 ; i <= n ; i++){
                if(resp[i] & 1){
                    // printf("fail on %d deg = %d\n", i, resp[i]);
                    ok = false;
                    break;
                }
            }

            assert(ok);

            if(ok){
                for(int i = 0 ; i < m ; i++){
                    char c = i == (m - 1) ? '\n' : ' ';
                    printf("%d%c", dir_edge[i], c);
                }
            }else{
                printf("-1\n");
            }
        }else{
            printf("-1\n");
        }

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }
    }

    return 0;
}