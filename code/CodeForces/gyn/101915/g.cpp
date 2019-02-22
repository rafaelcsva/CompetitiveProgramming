//28, 11, 2018, 10:07:15 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll x[N];
vector< pii > tadj[N];
vector< pii > adj[N];
ll resp = 0LL;

void dfs(int u, int ft){
    for(int i = 0 ; i < tadj[u].size() ; i++){
        int v = tadj[u][i].first;
        ll w = tadj[u][i].second;

        if(v == ft){
            continue;
        }

        adj[u].push_back({w, v});

        dfs(v, u);
    }
}

void dfs2(int u, int ini, int en){
    if(adj[u].size() == 0){
        resp += (ll(en - ini) + 1LL) * ll(u);
        return;
    }

    int nini = upper_bound(a + ini, a + en + 1, adj[u][0].first);

    resp += ll(ini - nini) * ll(u);

    ini = nini; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n, q;

        scanf("%d %d", &n, &q);

        for(int i = 0 ; i < n - 1 ; i++){
            int ui, vi;
            ll wi;

            scanf("%d %d %d", &ui, &vi, &wi);
            tadj[ui].push_back({vi, wi});
            tadj[vi].push_back({ui, wi});
        }

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &x[i]);
        }
        
        for(int i = 1 ; i <= n ; i++){
            sort(adj[i].begin(), adj[i].end);
        }

        sort(x, x + n);

        dfs(1, 1);


    }

    return 0;
}