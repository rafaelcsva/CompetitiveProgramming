//06, 12, 2018, 13:38:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5100;
int mark1[N], mark2[N];
int len1[N], len2[N];
vector< vector< int > > adj, adj1;
vector< int > con;
int pt = 0;

void dfs(int u, vector< vector< int > > &adj, int len[], int mark[], int sc){
    // cout << u << endl
    len[sc]++;
    mark[u] = 1;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(!mark[v]){
            dfs(v, adj, len, mark, sc);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, e, p;

    cin >> a >> b >> e >> p;
    adj1.resize(e + 10);
    adj.resize(e + 10);
    for(int i = 0 ; i < p ; i++){
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj1[v].push_back(u);
    }

    for(int i = 0 ; i < e ; i++){
        
        memset(mark1, 0, sizeof mark1);
        dfs(i, adj, len1, mark1, i);
        
        memset(mark2, 0, sizeof mark2);
        dfs(i, adj1, len2, mark2, i);
    }

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for(int i = 0 ; i < e ; i++){
        int sz = e - len1[i];
        int sz2 = len2[i];
        // cout << i << " = " << len1[i] << endl;
        if(sz < a){
            // cout << "i = " << i  << endl;
            cnt1++;
        }

        if(sz < b){
            // cout << "I = " << i << endl;
            cnt2++;
        }

        if(sz2 > b){
            cnt3++;
        }
    }

    // assert(cnt1 == 2);
    cout << cnt1 << endl;
    cout << cnt2 << endl;
    // assert(cnt2 == 4);
    cout << cnt3 << endl;

    return 0;
}