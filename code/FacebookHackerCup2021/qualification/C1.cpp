#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int c[N];

vector< int > adj[N];

int dfs(int u, int ft, int acc = 0){
    int ans = acc + c[u];

    for(auto v: adj[u]){
        if(v == ft) continue;

        ans = max(ans, dfs(v, u, acc + c[u]));
    }

    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &c[i]);
        }
        
        for(int i = 1 ; i < n ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int best1 = 0;
        int best2 = 0;

        for(auto u: adj[1]){
            int d = dfs(u, 1);

            if(d >= best1){
                best2 = best1;
                best1 = d;
            }else{
                best2 = max(best2, d);
            }
        }

        printf("Case #%d: %d\n", test, best1 + best2 + c[1]);

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }
    }

    return 0;
}