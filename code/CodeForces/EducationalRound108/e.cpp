#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(4e5) + 10;
map< pair< ll, ll >, int > mp;
vector< pair< int, int > > adj[N];
bool mark[N];
int vis[N];
vector< pair< int, int > > ans;

pair< int, int > dfs(int u, int dpt = 1){
    // printf("u: %d\n", u);
    vis[u] = dpt;
    pair< int, int > lef = {-1, -1};

    for(auto v: adj[u]){
        if(!vis[v.second]){
            auto r = dfs(v.second, dpt + 1);

            if(r.first != -1){
                // printf("+%d\n", u);
                ans.push_back({r.first, v.first});
            }else{
                if(lef.first != -1){
                    // printf("+%d\n", u);
                    ans.push_back({lef.first, v.first});
                    lef = {-1, -1};
                }else{
                    lef = v;
                }
            }
        }else if(vis[v.second] > vis[u]){
            if(lef.first != -1){
                ans.push_back({lef.first, v.first});
                lef = {-1, -1};
            }else{
                lef = v;
            }
        }
    }

    return lef;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        ll ai, bi, ci, di;

        scanf("%lld %lld %lld %lld", &ai, &bi, &ci, &di);

        ll a1 = (ai + bi) * di;
        ll b1 = bi * ci;
        ll g1 = __gcd(a1, b1);
        a1 /= g1, b1 /= g1;

        if(mp.count({a1, b1}) == 0){
            mp[{a1, b1}] = mp.size() + 1;
        }

        ll a2 = ai * di;
        ll b2 = bi * (ci + di);
        ll g2 = __gcd(a2, b2);
        a2 /= g2, b2 /= g2;

        if(mp.count({a2, b2}) == 0){
            mp[{a2, b2}] = mp.size() + 1;
        }

        int u = mp[{a1, b1}];
        int v = mp[{a2, b2}];

        // printf("(%lld, %lld) | (%lld, %lld)\n", a1, b1, a2, b2);

        // printf("%d <-> %d\n", u, v);
        adj[u].push_back({i + 1, v});
        adj[v].push_back({i + 1, u});
    }

    for(int i = 1 ; i <= mp.size() ; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    printf("%lu\n", ans.size());

    for(auto u: ans){
        printf("%d %d\n", u.first, u.second);
    }

    return 0;
}