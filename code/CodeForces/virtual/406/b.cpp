//23, 07, 2018, 16:50:53 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, long long> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 150100;
int color[N];
vector<vector<int> > adj;

pii dfs(int x){
    pii r = {0, 1};
    color[x] = 1;

    for(int i = 0 ; i < adj[x].size() ; i++){
        int u = adj[x][i];
        r.first++;

        if(!color[u]){
            pii d = dfs(u);
            r.second += d.second;
            r.first += d.first;
        }
    }

    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);

    for(int i = 0 ; i < m ; i++){
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1 ; i <= n ; i++){
        if(!color[i]){
            pii r = dfs(i);

            if((r.second * (r.second - 1LL)) / 2LL != r.first / 2LL){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    
    return 0;
}