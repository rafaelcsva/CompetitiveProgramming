//20, 06, 2018, 08:22:55 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
vector< vector<pii> >adj;
const int N = int(1e5);
int n, m, k;
int dis[N];
const int INF = int(1e9);
priority_queue<pii>pq;

int dijkstra(){
    for(int i = 0 ; i < N ; i++){
        dis[i] = INF;
    }
    
    dis[1] = 0;

    pq.push_back({dis[1], 1});

    while(!pq.empty()){
        int u = pq.top().second;
        int w = -(pq.top().first);

        for(int i = 0 ; i < adj[u].size() ; i++){
            int q = w / h;

            
        }
    }

    return dis[n];
}

int main(){
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 0 ; i < m ; i++){
        int u, v, w;

        scanf("%d%d%d", &u, &v, &w);

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    printf("%d\n", dijkstra());

    return 0;
}