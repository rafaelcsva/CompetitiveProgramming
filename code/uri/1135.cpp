//06, 09, 2018, 08:26:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, ll> pii;
typedef unsigned long long ull;

const int N = 1e5 + 100; // Nº de vertices
const int LOGN = 30; // Log do Nº de vertices para a sparse table.
// L = Profundidade do vertice visitado no passo idx, E = Vertice visitado no passo idx, H = primeira aparicao de cada vertice
int L[2 * N], E[2 * N], H[N], idx;
int RMQ[2 * N][LOGN]; // Sparse table
vector< vector< pii > > adj; // Lista de Adjacência
ll dis[N];

void dfs(int cur, int depth, ll weight){
    dis[cur] = weight;
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;

    for(int i = 0 ; i < adj[cur].size() ; i++){
        int v = adj[cur][i].first;
        ll w = adj[cur][i].second;

        if(H[v] == -1){
            dfs(v, depth + 1, weight + w);
            E[idx] = cur;
            L[idx++] = depth;
        }
    }
}

void buildRMQ(int n){// Constroi a sparse table (O(nlogn))
    idx = 0;
    
    memset(H, -1, sizeof H);

    dfs(0, 0, 0LL); // O(n)

    n *= 2;
    
    for(int i = 0 ; i < n ; i++){
        while(i >= 2 * N){
            
        }
        RMQ[i][0] = i;
    }

    for(int i = 1 ; (1 << i) <= n ; i++){ // O(logn)
        for(int j = 0 ; j + (1 << i) - 1 < n ; j++){ // O(n)
            int sz = 1 << (i - 1);
            
            if(L[RMQ[j][i - 1]] < L[RMQ[j + sz][i - 1]]){
                RMQ[j][i] = RMQ[j][i - 1];
            }else{
                RMQ[j][i] = RMQ[j + sz][i - 1];
            }
        }
    }
}

int query(int u, int v){// Retorna o LCA de u e v, O(1)
    int i = H[u], j = H[v];
    
    if(i > j){
        swap(i, j);
    }

    int sz = (int)floor(log(ld(j - i + 1)) / (log(2.0L)));
    
    if(L[RMQ[i][sz]] < L[RMQ[j - (1 << sz) + 1][sz]]){
        return E[RMQ[i][sz]];
    }else{
        return E[RMQ[j - (1 << sz) + 1][sz]];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;

    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }
        
        adj.resize(n + 1);

        for(int i = 1 ; i <= n - 1 ; i++){
            int u, w;

            scanf("%d %d", &u, &w);

            adj[i].push_back({u, w});
            adj[u].push_back({i, w});
        }

        buildRMQ(n);

        scanf("%d", &q);
        
        while(q--){
            char c = q == 0 ? '\n' : ' ';
            int u, v;

            scanf("%d %d", &u, &v);

            int lc = query(u, v);

            printf("%lld%c", dis[u] + dis[v] - 2LL * dis[lc], c);
        }

        adj.clear();
    }

    return 0;
}