//05, 09, 2018, 12:21:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5100;
vector< vector< int > > adj;
int mark[N];

pii dfs(int u, int ft, int mod, int steps){
    if(mod == 2){
        if(steps == mark[u] ){
            return {u, 0};
        }else if(steps == mark[u] + 1){
            return {u, ft};
        }
    }

    if(mod == 1){
        mark[u] = steps;
    }

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(v != ft){
            pii r = dfs(v, u, mod, steps + 1);

            if(r.first != 0){
                return r;
            }
        }
    }

    return {0, 0};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }
        
        adj.resize(n + 2);

        for(int i = 0 ; i < n - 1 ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int l;

        scanf("%d", &l);
        
        for(int i = 0 ; i < l ; i++){
            int u, v;

            scanf("%d %d", &u, &v);
            
            dfs(u, u, 1, 0);
            pii r = dfs(v, v, 2, 0);

            if(r.second == 0){
                printf("The fleas meet at %d.\n", r.first);
            }else{
                if(r.first > r.second){
                    swap(r.first, r.second);
                }

                printf("The fleas jump forever between %d and %d.\n", r.first, r.second);
            }
        }

        adj.clear();
    }

    return 0;
}