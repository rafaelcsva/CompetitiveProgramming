#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
int n, m;
int a[N], b[N];
ll c[N], d[N];
ll dis[N];
vector< pair< int, pair< ll, ll > > > adj[N];
const ll inf = ll(1e18);
priority_queue< pair< ll, int > > pq;
const ll E = 100LL;

ll dijkstra(ll x){
    for(int i = 1 ; i <= n ; i++){
        dis[i] = inf;
    }

    dis[1] = x;
    pq.push({-dis[1], 1});

    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        // printf("-> %d %lld %lld\n", u.second, -u.first, dis[u.second]);
        if(-u.first > dis[u.second]) continue;

        for(auto v: adj[u.second]){
            // printf("v: %d\n", v.first);
            if(dis[v.first] > dis[u.second] + v.second.first + v.second.second / (x + 1LL)){
                dis[v.first] = dis[u.second] + v.second.first + v.second.second / (x + 1LL);
                pq.push({-dis[v.first], v.first});
            }
        }
    }

    return dis[n];
}

ll dijkstra2(ll x){
    for(int i = 1 ; i <= n ; i++){
        dis[i] = inf;
    }

    dis[1] = x;
    pq.push({-dis[1], 1});

    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        // printf("-> %d %lld %lld\n", u.second, -u.first, dis[u.second]);
        if(-u.first > dis[u.second]) continue;

        for(auto v: adj[u.second]){
            // printf("v: %d\n", v.first);
            if(dis[v.first] > dis[u.second] + v.second.first + v.second.second / (dis[u.second] + 1LL)){
                dis[v.first] = dis[u.second] + v.second.first + v.second.second / (dis[u.second] + 1LL);
                pq.push({-dis[v.first], v.first});
            }
        }
    }

    return dis[n];
}

ll solve(ll x){
    ll val = dijkstra(x);
    
    return val;
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= m ; i++){
        scanf("%d %d %lld %lld", &a[i], &b[i], &c[i], &d[i]);
        adj[a[i]].push_back({b[i], {c[i], d[i]}});
        adj[b[i]].push_back({a[i], {c[i], d[i]}});
    }

    ll lo = 0LL, hi = ll(1e9) + 10LL;

    while(hi - lo > E){
        ll mid1 = (2LL * lo + hi) / 3LL;
        ll mid2 = (lo + 2LL * hi) / 3LL;
        ll val1 = solve(mid1);
        ll val2 = solve(mid2);
        // printf("%lld %lld %lld %lld %lld %lld\n", lo, hi, mid1, mid2, val1, val2);

        if(val1 >= inf){
            printf("-1\n");
            return 0;
        }

        if(val1 > val2){
            lo = mid1;
        }else{
            hi = mid2;
        }
    }

    ll ans = inf;

    for(ll s = lo ; s <= hi ; s++){
        // printf("%lld %lld\n", s, solve(s));
        ans = min(ans, dijkstra2(s));
    }

    printf("%lld\n", ans);

    return 0;
}