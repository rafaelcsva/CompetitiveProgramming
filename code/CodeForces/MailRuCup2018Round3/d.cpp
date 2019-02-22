//25, 11, 2018, 15:39:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
vector< int > adj[N];

vector< pii > ct;
int in[N], en[N];
int per[N];
int pt = 1;
int pre[N];

void dfs(int u, int ft){
    in[u] = pt;
    per[pt] = u;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(v == ft){
            continue;
        }

        pt++;

        dfs(v, u);
    }

    en[u] = pt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    for(int i = 2 ; i <= n ; i++){
        int pi;

        cin >> pi;
        adj[pi].push_back(i);
        adj[i].push_back(pi);
    }

    dfs(1, 1);

    for(int i = 1 ; i <= n ; i++){
        int sz = en[i] - in[i] + 1;
        if(sz == 1){
            pre[in[i]] = 1;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        pre[i] += pre[i - 1];
    }

    for(int i = 1 ; i <= n ; i++){
        int sz = en[i] - in[i] + 1;
        int k = pre[en[i]] - pre[in[i] - 1];
        // cout << i << " " << en[i] << " " << in[i] << endl;
        // cout << "K = " << k << endl;

        ct.push_back({k, sz});
    }

    sort(ct.begin(), ct.end());

    int cur = 0;
    int ini = 0;

    for(int i = 1 ; i <= n ; i++){
        int mn = 0;

        while(ini < ct.size() && cur < i){
            mn = max(mn, ct[ini].first);
            // cout << ini << endl;
            cur++;
            ini++;
        }

        cout << mn << " ";
    }

    cout << endl;

    return 0;
}