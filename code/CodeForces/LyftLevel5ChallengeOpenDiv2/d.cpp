//04, 11, 2018, 18:16:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2000;
vector< vector< int > > adj;
bool mark[N];
bool mark2[N];
int r;

void dfs(int u, int ft){
    if(mark[u]){
        r = u;
        return;
    }

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(v != ft){
            dfs(v, u);

            if(r != -1){
                break;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n;
        r = -1;

        cin >> n;

        adj.resize(n + 3);

        for(int i = 1 ; i < n ; i++){
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }  

        int k1;

        cin >> k1;

        for(int i = 0 ; i < k1 ; i++){
            int u;

            cin >> u;

            mark[u] = true;
        }

        int k2;

        cin >> k2;

        int ques;

        for(int i = 0 ; i < k2 ; i++){
            int u;

            cin >> u;

            ques = u;
            mark2[u] = true;
        }

        cout << "B " << ques << endl;

        int x;

        cin >> x;

        if(mark[x]){
            cout << "C " << x << endl;
        }else{
            dfs(x, x);

            cout << "A " << r << endl;
            
            cin >> x;

            if(mark2[x]){
                cout << "C " << r << endl;
            }else{
                cout << "C -1" << endl;
            }
        }

        adj.clear();
        memset(mark, 0, sizeof mark);
        memset(mark2, 0, sizeof mark2);
    }

    return 0;
}