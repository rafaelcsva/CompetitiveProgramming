//06, 05, 2018, 11:48:55 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
vector< vector<int> > adj;
const int N = int(2e5 + 100);
int cor[N];
int tim[N];

int isCycle(int x, int f, int caller, int &comp){
    cor[x] = 1;
    int r = 1;
    comp++;
    tim[x] = comp;
    
    if(adj[x].size() != 2){
        r = 0;
    }
    
    for(int i = 0 ; i < adj[x].size() ; i++){
        int u = adj[x][i];

        if(u == f){
            continue;
        }
        
        if(cor[u] == 0)
            r &= isCycle(u, x, caller, comp);
    
    }

    return r;
}

int main(){
    int n, m;

    cin >> n >> m;

    adj.resize(n + 1);
    
    for(int i = 0 ; i < m ; i++){
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;

    for(int i = 1 ; i <= n ; i++){
        int comp = 0;
        
        if(cor[i] == 0 && isCycle(i, i, i, comp) && adj[i].size() != 0 && comp > 2){
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}