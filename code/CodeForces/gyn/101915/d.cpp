//28, 11, 2018, 09:20:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 23;
int adj[N][N];
int vis[N];
int match[N];

int aug(int u){
    if(vis[u] != -1){
        return 0;
    }

    vis[u] = 1;

    for(int i = 1 ; i < N ; i++){
        if(adj[u][i]){
            if(match[i] == -1 || aug(match[i])){
                match[i] = u;
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;
    
    while(t--){
        int p, n;

        cin >> p >> n;

        for(int i = 1 ; i <= p ; i++){
            for(int j = 1 ; j <= p ; j++){
                adj[i][j] = 1;
            }
        }

        for(int i = 0 ; i < n ; i++){
            int ui, vi;

            cin >> ui >> vi;

            adj[ui][vi] = 0;
        }

        int mcbm = 0;

        memset(match, -1, sizeof match);

        for(int i = 1 ; i <= p ; i++){
            memset(vis, -1, sizeof vis);

            if(aug(i)){
                mcbm++;
            }
        }

        printf("%d\n", 2 * p - mcbm);

        memset(adj, 0, sizeof adj);
    }

    return 0;
}