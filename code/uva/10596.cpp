//23, 04, 2018, 20:44:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 300;
vector< vector<int> > adj;
int vis[N];

void dfs(int x){
    vis[x] = 1;

    for(int i = 0 ; i < adj[x].size() ; i++){
        int v = adj[x][i];

        if(!vis[v]){
            dfs(v);
        }
    }
}

bool allIsEven(int n){
    bool ok = true;

    for(int i = 0 ; i < n ; i++){
        ok &= !(adj[i].size() % 2);
    }

    return ok;
}

void mark(int n){
    for(int i = 0 ; i < n ; i++){
        if(adj[i].size()){
            dfs(i);
            break;
        }
    }
}

bool check(int n){
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < adj[i].size() ; j++){
            int v = adj[i][j];

            if(!vis[v]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int n, r;

    ios::sync_with_stdio(false);

    while(cin >> n >> r){
        memset(vis, 0, sizeof vis);

        adj.clear();
        adj.resize(n + 1);

        for(int i = 0 ; i < r ; i++){
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool ok = allIsEven(n);
        
        if(ok){
            mark(n);
            ok = check(n);
        }
        
        ok &= (r > 0);
        
        if(ok){
            cout << "Possible" << endl;
        }else{
            cout << "Not Possible" << endl;
        }
    }

    return 0;
}