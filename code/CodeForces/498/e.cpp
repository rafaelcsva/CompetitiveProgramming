//16, 07, 2018, 12:53:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

vector<vector<int> > adj;

const int N = int(2e5 + 10);
int st[N], en[N];
int v[N];
int pt = -1;

void dfs(int u){
    v[++pt] = u;
    st[u] = pt;
    
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];
        dfs(v);
    }

    en[u] = pt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    
    cin >> n >> q;

    adj.resize(n + 1);

    for(int i = 2 ; i <= n ; i++){
        int x;

        cin >> x;
        adj[x].push_back(i);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(1);

    while(q--){
        int u, k;

        cin >> u >> k;

        if(en[u] - st[u] + 1 < k){
            cout << -1 << endl;
        }else{
            cout << v[st[u] + k - 1] << endl;
        }
    }
    
    return 0;
}