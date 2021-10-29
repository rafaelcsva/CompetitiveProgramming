#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

struct Edge {
    public:
    int u, v;
    ll w;
};

bool compar(Edge a, Edge b){
    return a.w < b.w;
}

vector< Edge > edges;

const int N = int(2e5) + 10;
int father[N];

int find(int u){
    if(father[u] == u){
        return u;
    }

    return father[u] = find(father[u]);
}

void join(int a, int b){
    int x = find(a);
    int y = find(b);

    if(x != y){
        if(x > y){
            father[y] = x;
        }else{
            father[x] = y;
        }
    }
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; i++){
        int ui, vi;
        ll ci;

        scanf("%d %d %lld", &ui, &vi, &ci);
    
        edges.push_back({ui, vi, ci});
    }

    for(int i = 1 ; i <= n ; i++){
        father[i] = i;
    }

    sort(edges.begin(), edges.end(), compar);

    ll ans = 0LL;

    for(auto e: edges){
        // printf("%d %d %d %d\n", e.u, e.v, find(e.u), find(e.v));
        if(find(e.u) != find(e.v)){
            join(e.u, e.v);
        }else{
            ans += max(0LL, e.w);
        }
    }

    printf("%lld\n", ans);

    return 0;
}