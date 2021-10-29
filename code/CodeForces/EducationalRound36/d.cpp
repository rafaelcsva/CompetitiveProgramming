#include <bits/stdc++.h>

using namespace std;

const int N = 510;
vector< int > adj[N];
int color[N];
vector< pair< int, int > > ecand;
int n, m;

int dfs(int u){
    color[u] = 1;

    for(auto v: adj[u]){
        if(color[v] == 0){
            auto r = dfs(v);

            if(r == -2){
                return r;
            }

            if(r != -1){
                ecand.push_back({u, v});
                if(r == u){
                    r = -2;
                }

                return r;
            }
        }else if(color[v] == 1){
            ecand.push_back({u, v});
            return v;
        }
    }

    color[u] = 2;

    return -1;
}

bool dfs_rmv(int u, pair< int, int > re_edg){
    color[u] = 1;

    for(auto v: adj[u]){
        if(make_pair(u, v) == re_edg) continue;

        if(color[v] == 0){
            if(dfs_rmv(v, re_edg)){
                return true;
            }
        }else if(color[v] == 1){
            // printf("rmv %d, %d dont works!\n", re_edg.first, re_edg.second);
            return true;
        }
    }

    color[u] = 2;

    return false;
}

bool can(pair< int, int > redge){
    memset(color, 0, sizeof color);
    bool ans = true;

    for(int i = 1 ; i <= n ; i++){
        if(color[i] == 0){
            ans &= !dfs_rmv(i, redge);
        }
    }

    return ans;
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
    }

    for(int i = 1 ; i <= n ; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }

    if(ecand.size() == 0){
        printf("YES\n");
    }else{
        bool ans = false;

        for(auto u: ecand){
            // printf("trying with %d, %d\n", u.first, u.second);
            ans |= can(u);
        }

        if(ans){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }


    return 0;
}