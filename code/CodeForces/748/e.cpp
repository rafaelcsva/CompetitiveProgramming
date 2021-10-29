#include <bits/stdc++.h>

using namespace std;

const int N = int(4e5) + 10;
int dis[N];
int son[N];
vector< int > adj[N];

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        for(int i = 0 ; i < n - 1 ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue< int > q;

        for(int i = 1 ; i <= n ; i++){
            son[i] = adj[i].size();
            if(son[i] <= 1){
                q.push(i);
                dis[i] = 1;
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v: adj[u]){
                son[v]--;

                if(dis[v] == 0 && son[v] <= 1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }

        int ans = 0;

        for(int i = 1 ; i <= n ; i++){
            ans += (dis[i] <= k);
            son[i] = 0;
            dis[i] = 0;
            adj[i].clear();
        }

        printf("%d\n", n - ans);
    }

    return 0;
}