//15, 11, 2018, 10:07:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< vector< int > > adj;
map< string, int >mp;
const int N = 210;
int test = 1;
int used[N][2];
pii dp[N][2];

pii solve(int u, bool us){
    pii &ans = dp[u][us];

    if(used[u][us] == test){
        return ans;
    }

    ans = {0, false};
    used[u][us] = test;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        pii d = solve(v, false);

        ans.first += d.first;
        ans.second |= d.second;
    }

    if(!us){
        pii se = {1, false};

        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i];

            pii d = solve(v, true);
            
            se.first += d.first;
            se.second |= d.second;
        }

        if(ans.first < se.first){
            ans = se;
        }else if(ans.first == se.first){
            ans.second = true;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    while(true){
        cin >> n;

        adj.resize(n + 10);

        if(n == 0)
            break;

        string boss;

        cin >> boss;

        mp[boss] = 0;
        int id = 1;

        for(int i = 1 ; i < n ; i++){
            string u, v;

            cin >> u >> v;

            int idxu, idxv;

            if(mp.count(u) == 0){
                mp[u] = id++;
            }

            if(mp.count(v) == 0){
                mp[v] = id++;
            }

            idxu = mp[u];
            idxv = mp[v];

            adj[idxv].push_back(idxu);
        }

        pii r = solve(0, 0);

        cout << r.first << " ";

        if(!r.second){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        
        mp.clear();
        adj.clear();
        test++;
    }

    return 0;
}