//23, 04, 2018, 21:27:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int h, w;
const int N = 1000;
int tab[N][N];
int vis[N * N ];
vector< vector < int > > adj;
vector< int > left_set;
int color[N * N];
int match[N * N];

bool ok(int i, int j){
    return i >= 0 && i < h && j >= 0 && j < w && tab[i][j] == '*';
}

void dfs(int x, int c){
    color[x] = c + 1;

    for(int i = 0 ; i < adj[x].size() ; i++){
        int v = adj[x][i];

        if(color[v] == 0){
            dfs(v, !c);
        }
    }
}

int match_d(int x){
    if(vis[x]){
        return 0;
    }

    vis[x] = 1;

    for(int i = 0 ; i < adj[x].size() ; i++){
        int v = adj[x][i];

        if(match[v] == -1 || match_d(match[v])){
            match[v] = x;
            return 1;
        }
    }

    return 0;
}

int main(){
    int t;

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        memset(color, 0, sizeof color);
        
        cin >> h >> w;
        
        adj.clear();
        adj.resize(h * w + h + 1);

        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin >> tab[i][j];

                if(tab[i][j]){
                    adj[i + w].push_back(j);
                    adj[j].push_back(i + w);
                }
            }
        }

        for(int i = 0 ; i < h + w ; i++){
            if(color[i] == 0)
                dfs(i, 0);
        }
        
        int MCBM = 0;
        memset(match, -1, sizeof match);
        
        for(int i = 0 ; i < h ; i++){
            int u = i + w;

            MCBM += match_d(u);
            memset(vis, 0, sizeof vis);        
        }

        cout << "Case " << test << ": a maximum of " << MCBM << " nuts and bolts can be fitted together" << endl;
    }

    return 0;
}