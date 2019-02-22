//15, 12, 2018, 13:06:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6);
const ll mod = 998244353LL;

ll fast_pow(ll n, int x){
    if(x == 1){
        return n;
    }

    if(x == 0){
        return 1LL;
    }

    ll lf = fast_pow(n, x / 2LL);

    lf *= lf;
    lf %= mod;

    if(x & 1){
        lf *= n;
    }

    return lf % mod;
}

int test = 1;
int taked[N];
int qtd[2];
int color[N];
vector< int > adj[N];

bool dfs(int u, int cl){
    // printf("%d\n", u);
    qtd[cl]++;
    taked[u] = test;
    color[u] = cl;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(taked[v] != test){
            if(!dfs(v, !cl)){
                return false;
            }
        }else{
            if(color[v] == color[u]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < m ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        ll tot = 1LL;
        
        for(int i = 1 ; i <= n ; i++){
            ll tmp = 0LL;

            if(taked[i] != test){
                qtd[0] = qtd[1] = 0;
                if(!dfs(i, 0)){
                    tot = 0LL;
                    break;
                }

                // printf("%d %d\n", qtd[0], qtd[1]);
                tmp += fast_pow(2LL, qtd[0] - 1LL);
                tmp %= mod;
                tmp += fast_pow(2LL, qtd[1]);
                tmp %= mod;
                tmp += fast_pow(2LL, qtd[0] - 1LL);
                tmp %= mod;

                tot *= tmp;
                tot %= mod;
            }
        }

        printf("%lld\n", tot);

        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
        }

        test++;
    }

    return 0;
}