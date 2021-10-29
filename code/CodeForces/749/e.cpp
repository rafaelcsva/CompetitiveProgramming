#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 10;
int father[N];

int find(int x){
    if(father[x] == x){
        return x;
    }

    return father[x] = find(father[x]);
}

void join(int u, int v){
    int x = find(u);
    int y = find(v);

    if(x != y){
        if(x < y){
            father[y] = x;
        }else{
            father[x] = y;
        }
    }
}

class Edge {
public:
    int v, idx;
};

int odd[N];
vector< Edge > adj[N];
int vis[N];

bool dfs(int u, int ft, int b, vector< int > &path){
    if(u == b){
        path.push_back(b);
        return true;
    }

    for(auto e: adj[u]){
        if(e.v == ft){
            continue;
        }

        if(dfs(e.v, u, b, path)){
            odd[e.idx] = (odd[e.idx] + 1) & 1;
            path.push_back(u);
            return true;
        }
    }

    return false;
}

bool take(int u, int ft, int &ans){
    if(vis[u]){
        return false;
    }

    vis[u] = 1;
    int dg = 0;

    for(auto e: adj[u]){
        if(odd[e.idx]){
            dg++;
            // printf("odd: %d-%d\n", u, e.v);
            if(e.v == ft){
                continue;
            }

            take(e.v, u, ans);
        }
    }

    ans += (dg - 1) / 2;

    return dg != 0;
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n ; i++){
        father[i] = i;
    }

    int ed = 0;
    
    for(int i = 0 ; i < m ; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        if(find(u) != find(v)){
            join(u, v);

            // printf("%d-%d\n", u, v);
            adj[u].push_back({v, ed});
            adj[v].push_back({u, ed});
            
            ed++;
        }
    }

    int q;

    scanf("%d", &q);

    vector< vector< int > > paths;

    while(q--){
        int a, b;

        scanf("%d %d", &a, &b);

        vector< int > path;

        dfs(a, a, b, path);

        reverse(path.begin(), path.end());
        paths.push_back(path);
    }

    bool frag = true;

    for(int i = 0 ; i < ed ; i++){
        if(odd[i]){
            frag = false;
            break;
        }
    }

    if(frag){
        printf("YES\n");
        for(auto p: paths){
            printf("%lu\n", p.size());
    
            for(auto u: p){
                printf("%d ", u);
            }

            printf("\n");
        }
    }else{
        printf("NO\n");
    
        int ans = 0;

        for(int i = 1 ; i <= n ; i++){
            if(take(i, i, ans)){
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}