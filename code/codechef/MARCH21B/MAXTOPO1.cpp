#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(5e5) + 10;
int depth[N];
int father[N];
const ll mod = ll(1e9) + 7LL;
vector< int > adj[N];
vector< int > path;
ll fat[N];
int sz[N];

void dfs(int u, int ft){
    father[u] = ft;
    for(auto v: adj[u]){
        if(v == ft){
            continue;
        }

        depth[v] = depth[u] + 1;
        father[v] = u;
        dfs(v, u);
    }
}

ll fast_expo(ll x, ll e){
    ll r = 1LL;
    ll b = x;

    while(e){
        if(e & 1LL){
            r = (r * b) % mod;
        }

        b = (b * b) % mod;
        e >>= 1LL;
    }

    return r;
}

ll inv(ll x){
    return fast_expo(x, mod - 2LL);
}

ll solve(int u, int ft){
    sz[u] = 1;
    ll r = 1LL;
    ll minv = 1LL;
    int cnt = 0;

    for(auto v: adj[u]){
        if(v == ft){
            continue;
        }

        r *= solve(v, u);
        r %= mod;
        cnt += sz[v];
        sz[u] += sz[v];

        minv *= inv(fat[sz[v]]);
        minv %= mod;
    }

    r *= fat[cnt];
    r %= mod;

    r *= minv;
    r %= mod;

    return r;
}

int main(){
    fat[0] = 1LL;

    for(ll i = 1 ; i < N ; i++){
        fat[i] = ll(i) * fat[i - 1];
        fat[i] %= mod;
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        for(int i = 1 ; i < n ; i++){
            int ui, vi;
            
            scanf("%d %d", &ui, &vi);

            adj[ui].push_back(vi);
            adj[vi].push_back(ui);
        }

        dfs(1, 1);

        pair< int, int > ft = {0, 1};

        for(int i = 1 ; i <= n ; i++){
            ft = max(ft, {depth[i], i});
        }

        dfs(ft.second, ft.second);

        ft = {0, 1};

        for(int i = 1 ; i <= n ; i++){
            ft = max(ft, {depth[i], i});
        }

        vector< int > path;
        int st = ft.second;

        while(st != father[st]){
            path.push_back(st);
            st = father[st];
        }

        path.push_back(st);

        ft = {0, 1};

        vector< pair< ll, int > > con;
        for(int i = 1 ; i <= n ; i++){
            con.push_back({solve(i, i), i});
        }

        sort(con.begin(), con.end(), greater< pair< ll, int > >());
        printf("%d %lld\n", con[k - 1].second, con[k - 1].first);
    
        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
            depth[i] = 0;
        }
    }

    return 0;
}
