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

vector< int > mx;

vector<int> Centroid(int n) {
        vector<int> centroid;
        vector<int> sz(n + 1);
        mx.resize(n + 1);

        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                mx[u] = 0;
                bool is_centroid = true;
                for (auto v : adj[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                        mx[u] = max(mx[u], sz[v]);
                }

                if (n - sz[u] > n / 2) is_centroid = false;
                mx[u] = max(mx[u], n - sz[u]);

                if (is_centroid) centroid.push_back(u);
        };
        dfs(1, -1);
        return centroid;
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

        auto centroids = Centroid(n);

        int c1, c2;

        c1 = c2 = n;
        for(int i = n ; i >= 1 ; i--){
            if(mx[i] < mx[c1]){
                c2 = c1;
                c1 = i;
            }else if(mx[i] < mx[c2]){
                c2 = i;
            }
        }

        int c;

        if(k == 1){
            c = c1;
        }else{
            c = c2;
        }

        printf("%d %lld\n", c, solve(c, c));
    
        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
            depth[i] = 0;
        }
    }

    return 0;
}