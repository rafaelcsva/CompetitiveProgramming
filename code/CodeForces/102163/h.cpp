//17, 04, 2019, 18:03:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 100);
int mt = 1;
int comp[N];
vector< int > adj[N];

void dfs(int u){
    comp[u] = mt;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(comp[v] == 0){
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n, m, q;

        cin >> n >> m >> q;

        for(int i = 0 ; i < m ; i++){
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 1 ; i <= n ; i++){
            if(comp[i] == 0){
                dfs(i);
                mt++;
            }
        }

        while(q--){
            int u, v;

            cin >> u >> v;

            cout << (comp[u] == comp[v]) ;
        }

        cout << endl;

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
            comp[i] = 0;
        }
    }

    return 0;
}