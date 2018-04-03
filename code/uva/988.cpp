#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
vector<vector<int> >adj;
vector<int>top_sort;
int cor[N];
int p[N];

void dfs(int x){
    cor[x] = 1;

    for(int i = 0 ; i < adj[x].size() ; i++){
        int v = adj[x][i];

        if(cor[v] == 0){
            dfs(v);
        }
    }

    top_sort.push_back(x);
}

int main (){
    int n;
    bool print = false;

    ios::sync_with_stdio(false);

    while(cin >> n){
        adj.clear();
        adj.resize(n);
        memset(p, 0, sizeof p);
        memset(cor, 0, sizeof cor);

        if(print)
            cout << '\n';

        for(int i = 0 ; i < n ; i++){
            int m;

            cin >> m;

            for(int j = 0 ; j < m ; j++){
                int v;

                cin >> v;

                adj[i].push_back(v);
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(cor[i] == 0){
                dfs(i);
            }
        }

        p[0] = 1;

        for(int i = n - 1 ; i >= 0 ; i--){
            int u = top_sort[i];

            for(int j = 0 ; j < adj[u].size() ; j++){
                int v = adj[u][j];

                p[v] += p[u];
            }
        }

        int r = 0;

        for(int i = 0 ; i < n ; i++){
            if(adj[i].size() == 0){
                r += p[i];
            }
        }

        cout << r << '\n';

        print = true;

        top_sort.clear();
    }

    return 0;
}