//04, 02, 2019, 19:51:03 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< ll, int > pli;

const int N = int(1e5 + 10), K = int(205);
int used[N][K];
ll dp[N][K];
int bel[N];
int color[N];
ll b[N];
vector< int > topological_sort;
vector< int > adj[N], adj_rev[N], new_adj[N];
enum color{white, black};
const ll mod = 1000000021LL;
const ll inf = ll(1e18);
int test;
vector< pli > number_component[N];
const ll off_space = 10;
int comp;

void dfs(int u, vector< int > adj[], bool push = false){
    color[u] = black;
    bel[u] = comp;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(color[v] == white){
            dfs(v, adj, push);
        }
    }

    if(push){
        topological_sort.push_back(u);
    }
}

ll get(int u, int mid, int k);

ll solve(int u, int k){
    if(k < 0LL){
        return -inf;
    }

    // printf("-> %d\n", u);
    ll &ans = dp[u][k];

    if(used[u][k] == test){
        return ans;
    }

    used[u][k] = test;
    ans = 0LL;

    int lo = 0, hi = int(number_component[u].size()) - 1;

    // while(hi - lo >= off_space){
    //     int mid1 = (lo * 2 + hi) / 3;
    //     int mid2 = (lo + hi * 2) / 3;

    //     ll val1 = get(u, mid1, k);
    //     ll val2 = get(u, mid2, k);

    //     if(val1 > val2){
    //         hi = mid2;
    //     }else{
    //         lo = mid1;
    //     }
    // }

    // printf("-> %d\n", u);

    for(int i = lo ; i <= hi ; i++){
        // printf("--> %d %d\n", u, i);
        // if(i > k){
        //     break;
        // }

        int r = 0LL;

        if(i > 0){
            r = number_component[u][i - 1].second;
        }
        // printf("r = %d %d %d\n", r, u, i);
        if(r > k){
            break;
        }

        ans = max(ans, get(u, r, k));
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    for(test = 1 ; test <= t ; test++){
        int n, m, k;

        scanf("%d %d %d", &n, &m, &k);

        for(int i = 1 ; i <= n ; i++){
            scanf("%lld", &b[i]);
        }

        for(int i = 0 ; i < m ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            adj_rev[v].push_back(u);
        }

        for(int i = 1 ; i <= n ; i++){
            if(color[i] == white){
                dfs(i, adj, true);
            }
        }

        memset(color, white, sizeof color);

        comp = 1;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(color[topological_sort[i]] == white){
                dfs(topological_sort[i], adj_rev);
                comp++;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            // printf("%d ++\n", bel[i]);
            number_component[bel[i]].push_back({b[i], 0});
        }

        for(int i = 1 ; i <= n ; i++){
            sort(number_component[i].begin(), number_component[i].end());
        }

        for(int i = 1 ; i < comp ; i++){
            vector< pli > tmp;
            ll last = number_component[i][0].first;
            ll acumulator = last;
            int cnt = 1;

            for(int j = 1 ; j < number_component[i].size() ; j++){
                if(number_component[i][j].first != last){
                    last = number_component[i][j].first;
                    tmp.push_back({acumulator, cnt});

                    if(tmp.size() > 1){
                        tmp[int(tmp.size()) - 1].second += tmp[int(tmp.size()) - 2].second;
                    }

                    acumulator = last;
                    cnt = 1;
                }else{
                    // acumulator += number_component[i][j].first;
                    cnt++;
                }
            }

            if(acumulator != 0LL){
                tmp.push_back({acumulator, cnt});

                if(tmp.size() > 1){
                    tmp[int(tmp.size()) - 1].second += tmp[int(tmp.size()) - 2].second;
                }
            }

            // printf("%lu\n", tmp.size());
        
            // number_component[i].clear();
            number_component[i] = tmp;
            // printf("%lu\n", number_component[i].size());
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                int v = adj[i][j];

                if(bel[i] != bel[v]){
                    new_adj[bel[i]].push_back(bel[v]);
                    // printf("%d->%d\n", bel[i], bel[v]);
                }
            }
        }

        ll best = 0LL;

        for(int i = 1 ; i <= n ; i++){
            if(number_component[i].size() > 0){
                // printf("called for %d\n", i);
                best = max(best, solve(i, k));
            }
        }

        printf("%lld\n", best % mod);

        for(int i = 1 ; i <= n ; i++){
            number_component[i].clear();
            new_adj[i].clear();
            adj[i].clear();
            adj_rev[i].clear();
        }

        topological_sort.clear();
        memset(color, 0, sizeof color);
    }
    
    return 0;
}

ll get(int u, int mid, int k){
    if(mid > k){
        return -inf;
    }

    ll sum = ll(number_component[u][int(number_component[u].size()) - 1].second - mid) * number_component[u][mid].first;

    assert(mid < number_component[u].size());
    ll best = -inf;

    for(int i = 0 ; i < new_adj[u].size() ; i++){
        int v = new_adj[u][i];

        best = max(best, solve(v, k - mid));
    }

    if(new_adj[u].size() == 0){
        best = 0LL;
    }

    return sum + best;
}
