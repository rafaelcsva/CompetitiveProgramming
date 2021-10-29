#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = 998244353LL;
const int N = int(2e5) + 10;
int in[N];
int f[N];
int marked[N];
vector< int > adj[N];

void dfs(int u, bool &ok){
    marked[u] = 1;

    for(auto v: adj[u]){
        if(marked[v]){
            if(marked[v] == 2){
                ok = false;
            }
            continue;
        }

        // printf("v: %d\n", v);
        dfs(v, ok);
    }

    marked[u] = 2;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &f[i]);

        in[f[i]]++;
        adj[i].push_back(f[i]);
    }

    ll ans = 1LL;

    for(int i = 1 ; i <= n ; i++){
        if(in[i] == 0){
            bool ok = true;
            dfs(i, ok);

            if(ok){
                ans <<= 1LL;
                ans %= mod;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(!marked[i]){
            bool ok = true;
            dfs(i, ok);

            if(ok){
                ans <<= 1LL;
                ans %= mod;
            }
        }
    }

    printf("%lld\n", (ans - 1LL + mod) % mod);

    return 0;
}
