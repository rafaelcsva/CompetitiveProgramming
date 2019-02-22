//21, 11, 2018, 12:52:16 Rafaelcs cpp
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

struct Edge{
    int to, from, passenger, cost, day;
};

const int N = 1010;
const int V = 31 * 3, D = 11;
Edge edges[N];
int adj[V][V][D + 10];
int n, d, m;
int z[V];
pii father[V][D + 10];
queue< pii > q;

int in(int v){
    return 2 * v;
}

int out(int v){
    return 2 * v + 1;
}

bool bfs(){
    for(int i = 1 ; i <= n ; i++){
        for(int day = 0 ; day <= d ; day++){
            father[in(i)][day] = father[out(i)][day] = {-1, -1};
        }

        q.push({in(i), -1});
    }

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        if(u.second == -1){
            if(adj[u.first][u.first + 1][0] && father[u.first + 1][0].first == -1){
                // printf("(%d, %d)\n", u.first + 1, out(u.first / 2));
                father[u.first + 1][0] = {u.first, 0};
                q.push({u.first + 1, 0});

                continue;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int day = u.second ; day <= d ; day++){
                if(adj[u.first][out(i)][day] && father[out(i)][day + 1].first == -1){
                    father[out(i)][day + 1] = {u.first, u.second};
                    q.push({out(i), day + 1});
                }
            }
        }
    }

    for(int day = 0 ; day <= d ; day++){
        if(father[out(n)][day].first != -1){
            return true;
        }
    }

    return false;
}

int edmonds_karp(){
    int max_flow = 0;

    while(bfs()){
        int mn = 1e9;
        pii cur = {0, 0};

        for(int day = 0 ; day <= d ; day++){
            if(father[out(n)][day].first != -1){
                cur = {out(n), day};    
                break;   
            }
        }

        pii tmp = cur;
        // printf("pegando min (%d, %d)\n", cur.first, cur.second);

        while(father[cur.first][cur.second].first != -1){
            int lt = max(0, cur.second - 1);

            mn = min(mn, adj[father[cur.first][cur.second].first][cur.first][lt]);
            cur = father[cur.first][cur.second];
            // printf("(%d, %d) %d\n", cur.first, cur.second, father[cur.first][cur.second].second);
            // sleep(2);
        }
        // printf("o min eh %d\n", mn);

        max_flow += mn;

        // printf("maxflow = %d\n", max_flow);

        cur = tmp;

        while(father[cur.first][cur.second].first != -1){
            int lt = max(0, cur.second - 1);

            adj[father[cur.first][cur.second].first][cur.first][lt] -= mn;
            adj[cur.first][father[cur.first][cur.second].first][lt] += mn;
            
            cur = father[cur.first][cur.second];
        }
    }

    return max_flow;
}

bool can(int mid){
    int tot = 0;

    for(int i = 1 ; i <= n ; i++){
        adj[in(i)][out(i)][0] = z[i];
        tot += z[i];
    }

    for(int i = 0 ; i < m ; i++){
        if(edges[i].cost <= mid){
            adj[out(edges[i].to)][out(edges[i].from)][edges[i].day] = edges[i].passenger;
        }
    }

    // printf("aqui\n");
    int flow = edmonds_karp();
    // printf("terminei!\n");

    memset(adj, 0, sizeof adj);

    return flow >= tot;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    int test = 1;

    scanf("%d", &t);

    while(t--){
        
        scanf("%d %d %d", &n, &d, &m);

        for(int i = 0 ; i < m ; i++){
            scanf("%d %d %d %d %d", &edges[i].to, &edges[i].from, &edges[i].passenger, &edges[i].cost, &edges[i].day);
        }

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &z[i]);
        }

        int lo = 1, hi = int(1e5);
        int r = -1;

        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            // printf("tentando com %d\n", mid);

            if(can(mid)){
                r = mid;
                hi = mid - 1;
            } else{
                lo = mid + 1;
            }
        }

        printf("Case #%d: ", test++);
        
        if(r == -1){
            printf("Impossible\n");
        }else{
            printf("%d\n", r);
        }
    }

    return 0;
}