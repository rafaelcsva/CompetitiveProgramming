//12, 11, 2018, 13:14:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< ll, int >     pil;
const int N = 3e5 + 10;
vector< pil > adj[N];
map< pii , int > mp;
int parent[N];
priority_queue< pil > pq;
ll dis[N];
const ll inf = 1e18;

void dijkstra(){
    for(int i = 0 ; i < N ; i++){
        dis[i] = inf;
    }

    dis[1] = 0LL;
    pq.push({0LL, 1});

    while(!pq.empty()){
        int u = pq.top().second;
        ll dist = -pq.top().first;
        // cout << "u = " << u << endl; 
        pq.pop();

        if(dis[u] < dist){
            continue;
        }

        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i].first;
            ll w = adj[u][i].second;
            
            if(dis[v] > dis[u] + w){
                parent[v] = u;
                dis[v] = dis[u] + w;

                pq.push({-dis[v], v});
            }
        }
    }
}

vector< int > good_edges;
int k;

void take_good(int u){
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i].first;

        if(good_edges.size() == k){
            break;
        }

        if(parent[v] == u){
            good_edges.push_back(mp[{u, v}]);
            take_good(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1 ; i <= m ; i++){
        int u, v;
        ll w;

        scanf("%d %d %lld", &u, &v, &w);

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        mp[{u, v}] = mp[{v, u}] = i;
    }

    dijkstra();

    take_good(1);

    printf("%lu\n", good_edges.size());

    for(int i = 0 ; i < good_edges.size() ; i++){
        char c = i == int(good_edges.size()) - 1 ? '\n' : ' ';

        printf("%d%c", good_edges[i], c);
    }

    return 0;
}