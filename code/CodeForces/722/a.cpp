#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
vector< int > adj[N];
ll dp[N][2];
int used[N][2];
int test = 1;
ll l[N][2];

ll solve(int u, int ft, int cho){
    ll &ans = dp[u][cho];

    if(used[u][cho] == test){
        return ans;
    }

    used[u][cho] = test;
    ll add0 = 0LL;
    ll add1 = 0LL;

    if(u != ft){
        add0 = abs(l[u][0] - l[ft][cho]);
        add1 = abs(l[u][1] - l[ft][cho]);
    }

    ans = 0LL;

    for(auto v: adj[u]){
        if(v == ft) continue;

        add0 += solve(v, u, 0);
        add1 += solve(v, u, 1);
    }

    ans = max(add0, add1);
    // printf("u: %d, %d %lld\n", u, cho, ans);

    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%lld %lld", &l[i][0], &l[i][1]);
        }

        for(int i = 1 ; i < n ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        printf("%lld\n", solve(1, 1, 0));
        test++;

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }
    }

    return 0;
}