#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

const int N = 410;
pair< int, int > father[N];
int dis[N];
bool mark[N * N];
vector< pii > adj[N];
int n, m;

int bfs(int mk){
    memset(dis, -1, sizeof dis);    
    queue< int > q;

    q.push(1);
    dis[1] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(v.second == mk) continue;
        
            if(dis[v.first] == -1){
                dis[v.first] = dis[u] + 1;
                father[v.first] = {u, v.second};

                q.push(v.first);
            }
        }
    }

    return dis[n];
}

int main(){
    memset(father, -1, sizeof father);

    scanf("%d %d", &n, &m);
    
    for(int i = 0 ; i < m ; i++){
        int si, ti;

        scanf("%d %d", &si, &ti);

        adj[si].push_back({ti, i});
    }

    int dis = bfs(-1);

    if(dis == -1){
        for(int i = 0 ; i < m ; i++){
            printf("-1\n");
        }
        return 0;
    }

    int cur = n;

    while(cur != 1){
        // printf("cur: %d\n", cur);
        mark[father[cur].second] = true;
        cur = father[cur].first;
    }

    for(int i = 0 ; i < m ; i++){
        if(!mark[i]){
            printf("%d\n", dis);
        }else{
            printf("%d\n", bfs(i));
        }
    }

    return 0;
}