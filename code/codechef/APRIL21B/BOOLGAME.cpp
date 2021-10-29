#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 63;
vector< ll > dp[N][N];
ll memo[N][N];
bool used[N][N], usedm[N][N];
vector< pair< int, ll > > con[N];
ll g[N];
int n, m, k;

ll sum(int i, int l){
    auto &us = usedm[i][l];
    auto &ans = memo[i][l];

    if(us){
        return ans;
    }

    us = true;
    ans = 0LL;

    for(auto u: con[i]){
        if(u.first <= l){
            ans += u.second;
        }
    }

    return ans;
}

bool compar(ll a, ll b){
    return a > b;
}

vector< ll > solve(int i, int l){
    auto &us = used[i][l];
    auto &ans = dp[i][l];

    if(us){
        return ans;
    }

    auto d = sum(i, l);

    if(i == n + 1){
        return {d};
    }

    ans.clear();
    us = true;

    auto lf = solve(i + 1, l + 1);
    for(auto &u: lf){
        u += g[i] + d;
    }

    auto rg = solve(i + 1, 0);

    for(auto &u: rg){
        u += d;
    }

    vector< ll > mg(lf.size() + rg.size());

    merge(lf.begin(), lf.end(), rg.begin(), rg.end(), mg.begin(), compar);

    for(int i = 0 ; i < min(k, (int)mg.size()) ; i++){
        ans.push_back(mg[i]);
    }

    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d", &n, &m, &k);

        for(int i = 1 ; i <= n ; i++){
            scanf("%lld", &g[i]);
        }

        for(int i = 1 ; i <= m ; i++){
            int ui, vi;
            ll di;

            scanf("%d %d %lld", &ui, &vi, &di);

            con[vi + 1].push_back({vi - ui + 1, di});
        }

        auto r = solve(1, 0);

        for(auto u: r){
            printf("%lld ", u);
        }

        printf("\n");

        for(int i = 1 ; i <= m + 1 ; i++){
            con[i].clear();
        }

        memset(used, false, sizeof used);
        memset(usedm, false, sizeof usedm);
    }

    return 0;
}