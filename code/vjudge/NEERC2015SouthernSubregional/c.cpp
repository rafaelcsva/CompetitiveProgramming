#include <bits/stdc++.h>

using namespace std;

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

int decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

const int N = int(3e5 + 10);
vector< vector< int > > adj;
vector< string > ve, vu;
map< string, string > prop[N];
map< string, vector< int > > headcon[N];
map< int, int > headconpos[N];

int main(){
    int n;

    scanf("%d", &n);

    adj.resize(n);

    for(int i = 0 ; i < n ; i++){
        int pi, ki;

        cin >> pi >> ki;

        for(int j = 0 ; j < ki ; j++){
            string t[2];
            string a;

            cin >> a;
            int ind = 0;

            for(int i = 0 ; i < a.length() ; i++){
                if(a[i] == '='){
                    ind++;
                }else{
                    t[ind].push_back(a[i]);
                }
            }

            prop[i][t[0]] = t[1]; 
        }

        if(i != 0){
            adj[pi - 1].push_back(i);
        }
    }

    init(adj);

    for(int i = 0 ; i < n ; i++){
        for(auto u: prop[i]){
            headcon[head[i]][u.first].push_back(depth[i]);
            headconpos[head[i]][depth[i]] = i;
        }
    }

    int q;

    cin >> q;

    while(q--){
        int u;
        string propn;

        cin >> u >> propn;

        u--;

        int curdep = depth[u];
        string ans = "N/A";

        while(true){
            auto ve = headcon[head[u]][propn];

            auto id = upper_bound(ve.begin(), ve.end(), curdep) - ve.begin();

            if(id > 0){
                int vert = headconpos[head[u]][ve[id - 1]];

                ans = prop[vert][propn];

                break;
            }

            if(u == 0){
                break;
            }

            u = parent[head[u]];
            curdep = depth[u];
        }

        cout << ans << endl;
    }

    return 0;
}