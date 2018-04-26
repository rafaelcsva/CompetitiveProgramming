//23, 04, 2018, 21:27:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int h, w;
const int N = 1000;
char tab[N][N];
int mp[N][N];
int vi[] = {-1, 1, 0, 0}, vj[] = {0, 0, -1, 1};
int vis[N * N ];
vector< vector < int > > adj;
vector< int > left_set;
int color[N * N];
int match[N * N];

bool ok(int i, int j){
    return i >= 0 && i < h && j >= 0 && j < w && tab[i][j] == '*';
}

void dfs(int x, int c){
    if(c == 0){
        left_set.push_back(x);
    }

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

    while(t--){
        memset(color, 0, sizeof color);
        
        cin >> h >> w;

        int v = 0;

        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin >> tab[i][j];

                if(tab[i][j] == '*'){
                    mp[i][j] = v++;
                }
            }
        }

        adj.clear();
        adj.resize(v + 1);

        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if(tab[i][j] != '*'){
                    continue;
                }

                int u = mp[i][j];

                for(int k = 0 ; k < 4 ; k++){
                    int ti = i + vi[k], tj = j + vj[k];

                    if(ok(ti, tj)){
                        int v = mp[ti][tj];        

                        adj[u].push_back(v);
                    }
                }
            }
        }

        for(int i = 0 ; i < v ; i++){
            if(color[i] == 0)
                dfs(i, 0);
        }

        int MCBM = 0;
        memset(match, -1, sizeof match);
        
        for(int i = 0 ; i < left_set.size() ; i++){
            int u = left_set[i];

            MCBM += match_d(u);
            memset(vis, 0, sizeof vis);        
        }

        cout << v - MCBM << endl;
        left_set.clear();
    }

    return 0;
}