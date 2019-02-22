//06, 12, 2018, 12:00:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< ll, int > pli;

const int N = int(3e5 + 10);
int a[N];
vector< int > adj[N];
int father[N];
int marked[N];
vector< int > nivel[N];
ll dp[N];

void dfs(int u, int nvl){
    nivel[nvl].push_back(u);

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(father[u] == v){
            continue;
        }

        father[v] = u;
        dfs(v, nvl + 1);
    }
}

void run(int u){
    marked[u] = 1;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(marked[v]){
            continue;
        }

        if(dp[v] > 0LL){
            run(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    
    if(n == 1){
        cout << a[1] << " " << 1 << endl;
        return 0;
    }

    for(int i = 1 ; i < n ; i++){
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    ll best = -1e13;

    for(int mx = N - 1 ; mx >= 0 ; mx--){
        for(int i = 0 ; i < nivel[mx].size() ; i++){
            int u = nivel[mx][i];

            dp[u] = a[u];

            for(int x = 0 ; x < adj[u].size() ; x++){
                int t = adj[u][x];

                if(dp[t] > 0LL){
                    dp[u] += dp[t];
                }
            }

            best = max(best, dp[u]);
        }
    }

    ll k = 0;

    for(int mx = 0 ; mx < N ; mx++){
        for(int i = 0 ; i < nivel[mx].size() ; i++){
            int u = nivel[mx][i];

            if(!marked[u] && dp[u] == best){
                run(u);
                k++;
            }
        }
    }

    cout << k * best << " " << k << endl;
    
    return 0;
}