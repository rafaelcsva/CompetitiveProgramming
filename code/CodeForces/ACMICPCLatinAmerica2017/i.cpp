//06, 09, 2018, 08:26:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5; // Nº de vertices
const int LOGN = 20; // Log do Nº de vertices para a sparse table.
// L = Profundidade do vertice visitado no passo idx, E = Vertice visitado no passo idx, H = primeira aparicao de cada vertice
int L[2 * N], E[2 * N], H[N], idx;
int LCA[2 * N][LOGN]; // Sparse table para consulta do LCA
int father[2 * N][LOGN]; // Sparce table para consulta dos parentes de um no
int bel[N];
int greatest[2 * N][LOGN];
vector< vector< pii > > adj; // Lista de Adjacência
map< pii, bool > mark;
map< pii, int > val;

struct Edge{
    int u, v, w;

    bool operator <(Edge &other){
        return this->w < other.w;
    }
};

vector< Edge > edges;

void dfs(int cur, int depth){
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;

    for(int i = 0 ; i < adj[cur].size() ; i++){
        int v = adj[cur][i].first;
        int w = adj[cur][i].second;
        
        if(H[v] == -1){
            father[v][0] = cur;
            greatest[v][0] = w;
            dfs(v, depth + 1);
            E[idx] = cur;
            L[idx++] = depth;
        }
    }
}

void buildRMQ(int n){// Constroi a sparse table (O(nlogn))
    idx = 0;
    memset(H, -1, sizeof H);

    dfs(0, 0); // O(n)

    n *= 2;
    
    for(int i = 0 ; i < n ; i++){
        LCA[i][0] = i;
    }

    for(int i = 1 ; (1 << i) <= n ; i++){ // O(logn)
        for(int j = 0 ; j + (1 << i) - 1 < n ; j++){ // O(n)
            int sz = 1 << (i - 1);
            
            if(L[LCA[j][i - 1]] < L[LCA[j + sz][i - 1]]){
                LCA[j][i] = LCA[j][i - 1];
            }else{
                LCA[j][i] = LCA[j + sz][i - 1];
            }
        }
    }
}

void buildParent(int n){ // Constroi a sparce table para consulta dos pais
    for(int k = 1 ; k < LOGN ; k++){
        for(int i = 0 ; i < n ; i++){
            father[i][k] = father[father[i][k - 1]][k - 1];
        }
    }
}

void buildGreatest(int n){
    buildParent(n);
    
    for(int k = 1 ; k < LOGN ; k++){
        for(int i = 0 ; i < n ; i++){
            greatest[i][k] = max(greatest[i][k - 1], greatest[father[i][k - 1]][k - 1]);
        }
    }
}

int query_parent(int u, int k){ // retorna o k'esimo pai do nó u
    int cur = u;

    for(int i = 0 ; i < LOGN ; i++){
        int e = 1 << i;

        if(k & e){
            cur = father[cur][i];
        }
    }

    return cur;
}

int query(int u, int v){// Retorna o LCA de u e v, O(1)
    int i = H[u], j = H[v];
    
    if(i > j){
        swap(i, j);
    }

    int sz = (int)floor(log(ld(j - i + 1)) / (log(2.0L)));

    if(L[LCA[i][sz]] < L[LCA[j - (1 << sz) + 1][sz]]){
        return E[LCA[i][sz]];
    }else{
        return E[LCA[j - (1 << sz) + 1][sz]];
    }
}

int query_greatest(int u, int v){
    if(u == v){
        return 0;
    }

    int depthu = L[H[u]], depthv = L[H[v]];

    int diff = depthu - depthv;

    int cur = u;
    int best = 0;

    for(int i = 0 ; i < LOGN ; i++){
        int e = 1 << i;

        if(diff & e){
            best = max(best, greatest[cur][i]);
            cur = father[cur][i];
        }
    }

    return best;
}

int find(int x){
    if(bel[x] == x){
        return x;
    }

    return bel[x] = find(bel[x]);
}

bool join(int i, int j){
    int x = find(i);
    int y = find(j);

    if(x != y){
        if(x < y){
            bel[y] = x;
        }else{
            bel[x] = y;
        }

        return true;
    }

    return false;
}

int main(){
    int n, r;

    scanf("%d %d", &n, &r);
    
    adj.resize(n + 10);

    for(int i = 0 ; i < n ; i++){
        bel[i] = i;
    }

    for(int i = 0 ; i < r ; i++){
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        u--, v--;

        edges.push_back({u, v, w});
        val[{u, v}] = val[{v, u}] = w;
    }

    sort(edges.begin(), edges.end());

    int tot = 0;

    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;

        if(join(u, v)){
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            tot += w;
            mark[{u, v}] = mark[{v, u}] = true;
        }
    }

    buildRMQ(n);
    buildGreatest(n);

    int q;

    scanf("%d", &q);

    while(q--){
        int u, v;

        scanf("%d %d", &u, &v);

        u--, v--;
        
        if(!mark[{u, v}]){
            int l = query(u, v);

            int b = max(query_greatest(u, l), query_greatest(v, l));

            printf("%d\n", tot + val[{u, v}] - b);
        }else{
            printf("%d\n", tot);
        }
    }

    return 0;
}