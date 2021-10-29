#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 100;
vector< int > adj[N];
int leaf_cnt;
int bud_cnt;

bool dfs(int u, int ft){
    bool is_leaf = true;

    for(auto v: adj[u]){
        if(v == ft) continue;

        is_leaf &= !dfs(v, u);
    }

    if(is_leaf){
        leaf_cnt += (u != 1);
    }else{
        bud_cnt++;
        // printf("%d eh bud\n", u);
    }

    return is_leaf;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i < n ; i++){
            int ui, vi;

            scanf("%d %d", &ui, &vi);

            adj[ui].push_back(vi);
            adj[vi].push_back(ui);
        }

        leaf_cnt = bud_cnt = 0;

        dfs(1, 1);

        printf("%d\n", leaf_cnt - bud_cnt + 1);

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }
    }

    return 0;
}