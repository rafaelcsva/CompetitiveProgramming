//12, 05, 2018, 18:32:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = int(2e5 + 100);
int st[2][N], en[2][N];
vector<pii>edges;
vector<vector<int> > adj[2];
int pai[2][N];
int cnt;

void dfs(int x, int f, int t){
    st[t][x] = cnt;

    for(int i = 0 ; i < adj[t][x].size() ; i++){
        int u = adj[t][x][i];

        if(u == f)
            continue;

        pai[t][u] = x;
        cnt++;
        dfs(u, x, t);
    }

    en[t][x] = cnt;
}

bool contain(int a, int b, int t){
    return st[t][a] <= st[t][b] && en[t][a] >= en[t][b];
}

bool ver(int x, pii b, int t){
    if(contain(x, b.first, t) && !contain(x, b.second, t) || !contain(x, b.first, t) && contain(x, b.second, t)){
        return true;
    }else{
        return false;
    }
}

bool ok1(pii a, pii b){
    if(pai[1][b.first] == b.second){
        if(!ver(b.first, a, 1)){
            return false;
        }

        return true;
    }else{
        if(!ver(b.second, a, 1)){
            return false;
        }

        return true;
    }
}
bool ok(pii a, pii b){
    if(pai[0][a.first] == a.second){
        if(!ver(a.first, b, 0)){
            // cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << ' ' << st[0][a.first] << ' ' << st[1][a.second] << endl;
            return false;
        }
        
        return ok1(a, b);
    }else{
        if(!ver(a.second, b, 0)){

            //cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << ' ' << st[0][a.second] << ' ' << en[1][a.second] << endl;
            return false;
        }

        return ok1(a, b);
    }
}

int main(){
    int t;

    ios::sync_with_stdio(false);

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        adj[0].resize(n + 1);
        adj[1].resize(n + 1);
        
        for(int i = 0 ; i < n - 1 ; i++){
            int u, v;

            cin >> u >> v;

            edges.push_back({u, v});
            adj[0][u].push_back(v);
            adj[0][v].push_back(u);
        }

        for(int i = 0 ; i < n - 1 ; i++){
            int u, v;

            cin >> u >> v;

            adj[1][u].push_back(v);
            adj[1][v].push_back(u);
            edges.push_back({u, v});
        }

        dfs(1, 1, 0);
        cnt = 0;
        dfs(1, 1, 1);
        
        for(int i = 0 ; i < n - 1 ; i++){
            int add = 0;

            for(int j = n - 1 ; j < 2 * (n - 1) ; j++){
                if(ok(edges[i], edges[j])){
                    add++;
                }
            }

            cout << add << char(i == n - 2 ? '\n' : ' ');
        }


        cnt = 0;

        adj[0].clear();
        adj[1].clear();
        edges.clear();
    }

    return 0;
}