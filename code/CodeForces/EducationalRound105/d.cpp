#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > pipii;
const int N = 510;
int a[N][N];
int we[N * N];
pii father[N * N];
priority_queue< pipii > pq;
vector< pii > edges;
vector< int > adj[N * N];

int find(int a){
    if(father[a].first == a){
        return a;
    }

    return father[a].first = find(father[a].first);
}

void join(int a, int b){
    auto x = find(a);
    auto y = find(b);

    if(x != y){
        if(father[x].second > father[y].second){
            father[y].first = x;
        }else{
            father[x].first = y;
        }
    }
}

void check(int u, int lt = -1){
    if(lt != -1){
        // printf("%d %d %d\n",u, lt, we[u]);
        assert(we[u] < lt);
    }

    for(auto v: adj[u]){
        check(v, we[u]);
    }
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            scanf("%d", &a[i][j]);
            pq.push({-a[i][j], {i, j}});
        }
        we[i] = a[i][i];
    }

    for(int i = 1 ; i <= n ; i++){
        father[i] = {i, a[i][i]};
    }

    int lt = n;

    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();

        int w = -u.first;
        auto v = u.second;
        if(find(v.first) != find(v.second)){
            int tmp = lt;

            if(we[find(v.first)])
            lt++;
            we[lt] = w;
            father[lt] = {lt, w};
            edges.push_back({find(v.first), lt});
            edges.push_back({find(v.second), lt});
            adj[lt].push_back(find(v.second));
            adj[lt].push_back(find(v.first));
            join(v.first, lt);
            join(v.second, lt);
        }
    }

    // check(lt);

    // assert(lt - 1 == edges.size());
    printf("%d\n", lt);

    int ansi = 0;
    int ansb = 0;

    for(int i = 1 ; i <= lt ; i++){
        printf("%d ", we[i]);

        if(we[i] > ansb){
            ansb = we[i];
            ansi = i;
        }
    }
    printf("\n%d\n", ansi);

    for(auto e: edges) {
        printf("%d %d\n", e.first, e.second);
    }

    return 0;
}