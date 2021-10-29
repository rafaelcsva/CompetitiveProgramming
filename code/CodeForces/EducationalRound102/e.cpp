#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair< pair< ll, ll >, pair< pair< ll, ll >, int > > pii;
const int N = int(2e5) + 10;
vector< pair< int, ll > > adj[N];
priority_queue< pii > pq;
int dis[N];

void dijkstra(int node){
    pq.push({{0LL, 0LL}, {{0LL, 0LL}, 1}});

    while(!pq.empty()){
        auto u = pq.top();
        int v = u.second.second;
        ll mx = -u.second.first.first;
        ll mn = -u.second.first.second;
        ll mdis = -u.first.first;
        if()
    }
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; i++){
        int ui, vi;
        ll wi;
    
        scanf("%d %d %lld", &ui, &vi, &wi);
        adj[ui].push_back({vi, wi});
        adj[vi].push_back({ui, wi});
    }


}