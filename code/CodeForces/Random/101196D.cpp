//25, 03, 2019, 18:53:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, ll> pii;
typedef unsigned long long ull;
typedef pair< ll, pii > pipii;

const int N = 5000;
map< string, int > mp;
int father[N];
vector< pii > adj[N];
ll total_cost;
set< int > con[2];
set< pii > edges;
int taked = 1;

int find(int x){
    if(x == father[x]){
        return x;
    }

    return father[x] = find(father[x]);
}

void join(pii u, int par){
    int x = find(1);
    int y = find(u.second);

    if(x != y){
        if(x < y){
            father[y] = x;
        }else{
            father[x] = y;
        }

        total_cost += u.first;
        taked++;
        con[par].insert(u.second);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    mp["English"] = 1;

    int id = 1;

    for(int i = 1 ; i <= n ; i++){
        string si;

        cin >> si;

        id++;

        mp[si] = id;
    }

    for(int i = 1 ; i <= id ; i++){
        father[i] = i;
    }

    for(int i = 0 ; i < m ; i++){
        string ui, vi;
        ll ci;

        cin >> ui >> vi >> ci;

        int u = mp[ui];
        int v = mp[vi];

        adj[u].push_back({v, ci});
        adj[v].push_back({u, ci});
    }

    con[0].insert(1);
    int par = 0;

    while(taked != n + 1 && con[par].size() >= 1){
        for(int u: con[par]){
            for(int i = 0 ; i < adj[u].size() ; i++){
                edges.insert({adj[u][i].second, adj[u][i].first});
            }
        }

        for(pii u: edges){
            join(u, !par);
        }

        con[par].clear();
        edges.clear();

        par = !par;
    }

    if(taked != n + 1){
        cout << "Impossible" << endl;
    }else{
        cout << total_cost << endl;
    }
    
    return 0;
}