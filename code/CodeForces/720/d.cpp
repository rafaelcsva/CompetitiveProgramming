#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
vector< pair< int, int > > adj[N];
vector< int > comp[N];
vector< pair< int, int > >rem;
vector< pair< int, int > > add;
int vis[N];

void dfs(int u, int ft, int frag){
    // printf("u: %d\n", u);
    int adjsz = adj[u].size() - !frag;

    for(auto &e: adj[u]){
        if(e.first == ft && !frag){
            e.second = 0;
        }

        if(e.first == ft) continue;

        if(adjsz > 2){
            adjsz--;
            e.second = 0;
            rem.push_back({u, e.first});
        }
        dfs(e.first, u, e.second);
    }
}

void dfs1(int u, int ft, int compi){
    int adjsz = 0;
    vis[u] = 1;

    for(auto &e: adj[u]){
        if(e.second){
            adjsz++;
        }
        if(!e.second || ft == e.first) continue;

        dfs1(e.first, u, compi);
    }

    if(adjsz <= 1){
        comp[compi].push_back(u);

        if(adjsz == 0){
            comp[compi].push_back(u);
        }
    }
}

bool compar(pair< int, int > i, pair< int, int > j){
    return adj[i.first].size() > adj[j.first].size();
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0  ; i < n - 1 ; i ++){
            int ui, vi;

            scanf("%d %d", &ui, &vi);

            adj[ui].push_back({vi, 1});
            adj[vi].push_back({ui, 1});
        }

        for(int i = 1 ; i <= n ; i++){
            sort(adj[i].begin(), adj[i].end(), compar);
        }

        dfs(1, 1, 1);
        int compi = 0;

        for(int i = 1 ; i <= n ; i++){
            if(!vis[i]){
                dfs1(i, i, compi);
                compi++;
            }
        }

        pair< int, int > cur = {comp[0][0], comp[0][1]};

        for(int i = 1 ; i < compi ; i++){
            pair< int, int > p = {comp[i][0], comp[i][1]};

            add.push_back({p.second, cur.first});
            cur.first = p.first;
        }

        printf("%lu\n", rem.size());
    
        for(int i = 0 ; i < rem.size() ; i++){
            printf("%d %d %d %d\n", rem[i].first, rem[i].second, add[i].first, add[i].second);
        }

        rem.clear();
        add.clear();

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
            vis[i] = 0;
            comp[i].clear();
        }
        comp[0].clear();
    }

    return 0;
}