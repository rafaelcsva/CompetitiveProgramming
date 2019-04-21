//12, 03, 2019, 10:54:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6;
int p[N];
vector< int > adj[N];
int cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        cin >> p[i];
    }

    for(int i = 0 ; i < m ; i++){
        int ui, vi;

        cin >> ui >> vi;

        adj[vi].push_back(ui);
    }

    int take = 0;
    int current = 0;

    for(int i = n ; i >= 1 ; i--){
        // cout << "current = " << current << endl;
        if(cnt[p[i]] == current && i != n){
            take++;
            // cout << "ii = " << i << endl;
            // current--;
        }else{
            // cout << "i = " << i << endl;
            for(int j = 0 ; j < adj[p[i]].size() ; j++){
                int v = adj[p[i]][j];
                // cout << "v = " << v << endl;

                cnt[v]++;
            }

            current++;
        }
    }

    cout << take << endl;
    
    return 0;
}