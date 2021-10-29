#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(5e5) + 10;
double dp[N];
double calc[N];
double preflog[N];
vector< int > adj[N];
const double eps = double(1e-13);
const ll mod = ll(1e9) + 7LL;
ll fat[N];

double calog(int x){
    if(x <= 1){
        return 0;
    }
    // printf("x: %d\n", x);
    return preflog[x];
}

double solve(int u, int ft){
    // printf("u: %d\n", u);
    dp[u] = 0.0;

    for(auto v: adj[u]){
        if(v == ft){
            continue;
        }

        dp[u] += solve(v, u);
    }

    if(int(adj[u].size()) - (u != ft) == 0){
        return dp[u] = 0.0;
    }

    dp[u] += calog(int(adj[u].size()) - (u != ft));
    // printf("%d %lf\n", u, dp[u]);

    return dp[u];
}

void solve1(int u, int ft, double add = 0.0){
    calc[u] = dp[u] + add - calog(int(adj[u].size()) - (u != ft)) + calog(adj[u].size());
    // printf("-> %d %lu %lu %lf\n", u, int(adj[u].size()) - (u != ft), adj[u].size(), - calog(int(adj[u].size()) - (u != ft)) + calog(adj[u].size()));

    auto pss = calc[u] - calog(adj[u].size()) + calog(int(adj[u].size()) - 1);

    for(auto v: adj[u]){
        if(v == ft){
            continue;
        }

        solve1(v, u, pss - dp[v]);
    }
}

ll solve2(int u, int ft){
    int cnt = 0;
    ll ans = 1LL;

    for(auto v: adj[u]){
        if(v == ft){
            continue;
        }

        cnt++;
        ans *= solve2(v, u);
        ans %= mod;
    }

    ans = ans * fat[cnt];
    ans %= mod;

    return ans;
}

int main(){
    fat[0] = fat[1] = 1LL;
    for(int i = 2 ; i < N ; i++){
        preflog[i] = log2(i) + preflog[i - 1];
        fat[i] = ll(i) * fat[i - 1];
        fat[i] %= mod;
        // printf("%lf\n", preflog[i]);
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

        solve(1, 1);

        solve1(1, 1);

        pair< double, int > a1, a2;

        a1 = a2 = {-1.0, -1};

        for(int i = n ; i >= 1 ; i--){
            printf("%d %lf %lf\n", i, calc[i], dp[i]);
            if(calc[i] - a1.first > eps){
                a2 = a1;
                a1 = {calc[i], i};
            }else if(calc[i] - a2.first > eps){
                a2 = {calc[i], i};
            }
        }

        if(k == 1){
            printf("%d %lld\n", a1.second, solve2(a1.second, a1.second));
        }else{
            printf("%d %lld\n", a2.second, solve2(a2.second, a2.second));
        }

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }
    }

    return 0;
}
