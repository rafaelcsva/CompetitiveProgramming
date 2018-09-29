//13, 08, 2018, 12:37:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6 + 2;
vector< vector < int > > adj;
int vi[] = {-2, -2, 2, 2, -1, -1, 1, 1};
int vj[] = {1, -1, 1, -1, -2, 2, 2, -2};
int n, m;
int match[N];
bool vis[N];
const int MX = int(2e3 + 1);

bool ok(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

int aug(int u){
    if(vis[u]){
        return 0;
    }

    vis[u] = 1;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;        
        }
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(match, -1, sizeof match);
    
    scanf("%d %d", &n, &m);

    if(n * m < MX){
        adj.resize(n * m);

        int edges = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                for(int k = 0 ; k < 8 ; k++){
                    int ti = vi[k] + i, tj = vj[k] + j;

                    if(ok(ti, tj)){
                        edges += 1;
                        adj[i * m + j].push_back(ti * m + tj);
                    }
                }
            }
        }

        // printf("o grafo tem %d arestas\n", edges);
        int mcbm = 0;
        
        for(int i = 0 ; i < n * m ; i += 2){
            memset(vis, 0, sizeof vis);
            if(aug(i)){
                mcbm++;
            }
        }
        printf("%d\n", n * m - mcbm);
    }else{
        printf("%d\n", (n * m + 1) / 2);
    }
    
    return 0;
}