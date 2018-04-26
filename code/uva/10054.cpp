//17, 04, 2018, 18:47:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector<vector<pii> > adj;
const int N = 2010;
int color[N];
list<pii>euler_tour;
int mark[N];
const int COLOR = 60;

void dfs(int u, list<pii>::iterator it){
    
    //cout << u << endl << ' ' << adj[u].size();
    for(int i = 0 ; i < adj[u].size() ; i++){
        if(adj[u][i].second){
            adj[u][i].second = 0;
            int v = adj[u][i].first;

            for(int j = 0 ; j < adj[v].size() ; j++){
                int f = adj[v][j].first;

                if(f == u && adj[v][j].second){
                    adj[v][j].second = 0;
                    break;
                }
            }

            
            dfs(v, euler_tour.insert(it, {v, u}));
        }
    }
}

int pivo = -1;

bool ok(){
    for(int i = 1 ; i <= COLOR ; i++){
        if(adj[i].size() % 2){
            return false;
        }else if(pivo == -1){
            pivo = i;
        }
    }

    return true;
}

int main(){
    int t;
    int h;
    ios::sync_with_stdio(false);
    cin >> t;
    
    for(int test = 1 ; test <= t ; test++){
        int n;

        cin >> n;
        memset(color, 0, sizeof color);
        memset(mark, 0, sizeof mark);
        adj.clear();
        adj.resize(COLOR);
        
        int size = 0;
        int h;

        for(int i = 0 ; i < n ; i++){
            int u, v;

            cin >> u >> v;
            h = u;

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }

        cout << "Case #" << test << endl;

        if(ok()){
            dfs(pivo, euler_tour.begin());

            for(list<pii>::iterator it = euler_tour.begin() ; it != euler_tour.end() ; it++){
                cout << it->first << ' ' << it->second << endl;
            }
            
        }else{
            cout << "some beads may be lost" << endl;
        }
        
        cout << endl;
        euler_tour.clear();
    }   
    
    return 0;
}