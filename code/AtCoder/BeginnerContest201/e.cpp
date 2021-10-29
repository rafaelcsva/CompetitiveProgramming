#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long   ll;

const int D = 61;
const int N = int(2e5) + 10;

const ll mod = ll(1e9) + 7LL;
ll qtd[D];
vector< pair< int, ll > > adj[N];
ll ans;
int n;

void dfs1(int u, int v, ll acc){
    for(ll i = 0 ; i < D ; i++){
        ll e = 1LL << i;

        if(acc & e){
            qtd[i]++;
        }
    }
    // printf("%d have %lld\n", u, acc);

    for(auto e: adj[u]){
        if(e.first == v){
            continue;
        }

        dfs1(e.first, u, acc ^ e.second);
    }
}

void dfs2(int u, int v, ll acc){
    for(ll i = 0 ; i < D ; i++){
        ll e = 1LL << i;
        ll sb = 0LL;

        if(acc & e){
            sb = ll(n) - qtd[i];
        }else{
            sb = qtd[i];
        }

        // printf("bit %lld has %lld adds %lld\n", i, sb, 1LL << sb);
        ans += ((1LL << i) % mod) * sb;
        // tmp += (1LL << i);

        ans %= mod;
    }
    // printf("%d adds %lld\n", u, tmp);

    for(auto e: adj[u]){
        if(e.first == v){
            continue;
        }

        dfs2(e.first, u, acc ^ e.second);
    }
}

int main(){
    scanf("%d", &n);

    for(int i = 0 ; i < n - 1 ; i++){
        int ui, vi;
        ll wi;

        scanf("%d %d %lld", &ui, &vi, &wi);
    
        adj[ui].push_back({vi, wi});
        adj[vi].push_back({ui, wi});
    }

    dfs1(1, 1, 0LL);
    dfs2(1, 1, 0LL);

    // printf("ans = %lld\n", ans);
    ans *= ll(500000004);
    ans %= mod;

    printf("%lld\n", ans);

    return 0;
}