#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;


int n, m;
vector<vector<pii>> adj; // adjacency list of graph

typedef long long   ll;

const int N = int(3e5);

int father[N];
vector<bool> visited;
vector<int> tin, low;
int timer;
vector< int > nwadj[N];
ll c[N];
bool is_brid[N];
int comp = 0;
int bel[N];
int bel2[N];
int cor[N];
int cor2[N];
int cor3[N];
ll sum[N];
ll dp[N];
int comp1 = 0;
bool have[N];
typedef pair< ll, ll >  pll;
vector< pll > res[N][2];

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (pii aa : adj[v]) {
        int to = aa.first;
        int ednum = aa.second;

        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                // printf("%d %d is bridge\n", to + 1, v + 1);
                is_brid[ednum] = true;
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void dfs1(int u){
    bel[u] = comp;
    // printf("%d bel to %d\n", u + 1, comp);
    cor[u] = 1;

    for(pii aa : adj[u]){
        int ednum = aa.second;
        int to = aa.first;

        if(!is_brid[ednum] && !cor[to]){
            have[comp] = true;
            dfs1(to);
        }
    }
}

int dfs2(int u, int ft){
    father[u] = ft;
    cor2[u] = 1;

    for(int v: nwadj[u]){
        if(cor2[v] == 0){
            dfs2(v, u);
        }
    }
}

void dfs3(int u){
    bel2[u] = comp1;
    // printf("%d bel to %d\n", u + 1, comp1);
    sum[comp1] += c[u];
    cor3[u] = 1;

    for(pii aa : adj[u]){
        int ednum = aa.second;
        int to = aa.first;

        if((!is_brid[ednum] || have[bel[to]]) && !cor3[to]){
            dfs3(to);
        }
    }
}

const ll inf = ll(1e15);

ll solve(int s, int t){
    // printf("s: %d\n", s);
    if(dp[s][t] != -1LL){
        return dp[s];
    }

    ll &ans = dp[s][t];

    ans = -inf;

    bool ok = false;

    for(int u: nwadj[s]){
        if(u == father[s]){
            continue;
        }

        ok = true;

        res[0][s].push_back({solve(u, 0), u});
        res[1][s].push_back({solve(u, 1), u});
    }


    if(!ok && !have[s] && t){
        return ans = -inf;
    }

    sort(res[0][s].begin(), res[0][s].end(), greater< pll >());
    sort(res[1][s].begin(), res[1][s].end(), greater< pll >());

    if(t && have[s]){
        ans = sum[s];
    }

    if(res[0][s].size() == 1){
        return ans = sum[s] + res[1][s][0];
    }

    

    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            if(res[0][s][i].second != res[1][s][j].second){
                ans = max(ans, sum[s] + res[0][s][i].second + res[1][s][j].second);
            }
        }
    }

    return ans;
}

int main(){
    memset(dp, -1LL, sizeof dp);

    scanf("%d %d", &n, &m);

    adj.resize(n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &c[i]);
    }

    for(int i = 0 ; i < m ; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        u--, v--;

        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int s;

    scanf("%d", &s);

    s--;

    find_bridges();

    for(int i = 0 ; i < n ; i++){
        if(cor[i] == 0){
            dfs1(i);
            comp++;
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(cor3[i] == 0){
            dfs3(i);
            comp1++;
        }
    }    

    for(int i = 0 ; i < n ; i++){
        for(pii aa: adj[i]){
            int to = aa.first;

            if(bel2[to] != bel2[i]){
                nwadj[bel2[i]].push_back(bel2[to]);
            }
        }
    }

    // for(int i = 0 ; i < comp1 ; i++){
    //     printf("res = %d %lld\n", i, sum[i]);
    // }
    // printf("%d bel[s] = %d %d\n", comp1, bel2[s], s);

    dfs2(bel2[s], bel2[s]);

    printf("%lld\n", max(solve(bel2[s], 0), solve(bel2[s], 1)));

    return 0;
}