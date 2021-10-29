#include <bits/stdc++.h>

using namespace std;

const int N = int(2e3) + 10;
vector< int > adj[N];
int color[N];

void dfs(int u, int cl, int &ans){
    ans++;
    color[u] = cl;
    // printf("%d %d %d\n", u, color[u], cl);
    // fflush(stdout);

    for(auto v: adj[u]){
        if(color[v] != cl){
            dfs(v, cl, ans);
        }
    }
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; i++){
        int ui, vi;

        scanf("%d %d", &ui, &vi);

        adj[ui].push_back(vi);
    }

    int totans = 0;

    for(int i = 1 ; i <= n ; i++){
        int ans = 0;

        dfs(i, i, ans);

        totans += ans;
    }

    printf("%d\n", totans);

    return 0;
}