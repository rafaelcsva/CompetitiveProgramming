//05, 02, 2019, 18:56:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll a[N];
int n;
ll k;
ll dp[N][2];
vector< int > adj[N], new_adj[N];
const ll mod = ll(1e9) + 7;

class Node{
    public:
        int father;
        ll val;
        int merged = false;
        int deg = 0;
        bool has_k_subtree = false;
};

Node nodes[N];
vector< int > nvl[N];
int num_edges = 0;

void dfs(int u, int father, int deep, vector< int > adj[]){
    nodes[u].father = father;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(v == father){
            continue;
        }

        dfs(v, u, deep + 1, adj);
    }

    nvl[deep].push_back(u);
}

ll mpow(ll base, ll n){
    ll start = 1LL;

    for(int i = 1 ; i <= n ; i++){
        start *= base;
        start %= mod;
    }

    return start;
}

void get_new_graph(int u, int last){
    if(u != last){
        if(!nodes[u].merged){
            // printf("%d->%d\n", last, u);
            new_adj[last].push_back(u);
            new_adj[u].push_back(last);
            num_edges++;
            last = u;
        }
    }

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(v == nodes[u].father){
            continue;
        }

        get_new_graph(v, last);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %lld", &n, &k);
    
    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &nodes[i].val);
    }

    for(int i = 1 ; i < n ; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, 0, adj);

    for(int i = N - 1 ; i >= 1 ; i--){
        for(int j = 0 ; j < nvl[i].size() ; j++){
            int v = nvl[i][j];

            if(nodes[v].val == 0LL || nodes[v].val == k){
                continue;
            }

            nodes[v].merged = true;
            nodes[nodes[v].father].val ^= nodes[v].val;
        }

        nvl[i].clear();
    }

    nvl[0].clear();

    for(int i = 1 ; i <= n ; i++){
        if(!nodes[i].merged){
            if(nodes[i].val != 0LL && nodes[i].val != k){
                printf("0\n");
                return 0;
            }
        }
    }

    get_new_graph(1, 1);

    if(k == 0){
        printf("%lld\n", mpow(2LL, num_edges));
    }else{
        dfs(1, 1, 0, new_adj);

        for(int i = N - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j < nvl[i].size() ; j++){
                int u = nvl[i][j];
                // printf("u: %d\n", u);

                if(nodes[u].val == k){
                    dp[u][1] = 1LL;
                }else{
                    dp[u][0] = 1LL;
                }

                for(int k = 0 ; k < new_adj[u].size() ; k++){
                    int v = new_adj[u][k];

                    if(v == nodes[u].father){
                        continue;
                    }

                    ll tmp = dp[u][1];

                    dp[u][1] = ((dp[u][1] * dp[v][1]) % mod + (dp[u][1] * dp[v][0]) % mod + (dp[u][0] * dp[v][1]) % mod) % mod;
                    dp[u][0] = ((dp[u][0] * dp[v][1]) % mod + (dp[u][0] * dp[v][0]) % mod + (tmp * dp[v][1]) % mod) % mod;
                }
            }
        }

        printf("%lld\n", dp[1][1]);
    }
    
    return 0;
}