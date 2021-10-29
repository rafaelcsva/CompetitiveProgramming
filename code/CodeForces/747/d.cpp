#include <bits/stdc++.h>

using namespace std;

class Edge {
    public:
    int u, v, dir;
    string s;

    Edge(int u, int v,int dir, string s): u(u), v(v), dir(dir), s(s){}
};

const int N = int(2e5) + 10;
vector< Edge > adj[N];
string bel[N];

string neg(string s){
    return s == "crewmate" ? "imposter" : "crewmate";
}

int solve(int u, vector< int > &v){
    v.push_back(u);

    int ans = 0;

    if(bel[u] == "imposter"){
        ans++;
    }
    
    // assert(bel[u] == "imposter" || bel[u] == neg("imposter"));
    for(auto e: adj[u]){
        if(e.dir == 1){
            string gv = bel[u] == "crewmate" ? e.s : neg(e.s);

            if(bel[e.v] == ""){
                bel[e.v] = gv;

                int d = solve(e.v, v);

                if(d == -1){
                    return -1;
                }

                ans += d;
            }else if(bel[e.v] != gv){
                return -1;
            }
        }else{
            string gv = bel[u] == e.s ? "crewmate" : "imposter";

            if(bel[e.v] == ""){
                bel[e.v] = gv;

                int d = solve(e.v, v);

                if(d == -1){
                    return -1;
                }

                ans += d;
            }else if(bel[e.v] != gv){
                return -1;
            }
        }
    }

    return ans;
}

int main(){
    int t;

    cin >> t;

    while(t--){
        int n, m;

        cin >> n >> m;

        for(int i = 0 ; i < m ; i++){
            int u, v;
            string s;
        
            cin >> u >> v >> s;

            adj[u].push_back(Edge(u, v, 1, s));
            adj[v].push_back(Edge(v, u, -1, s));
        }

        bool frag = false;
        int ans = 0;

        for(int i = 1 ; i <= n ; i++){
            if(bel[i] == ""){
                vector< int > ve;
                bel[i] = "crewmate";
                int ansi = solve(i, ve);
  
                for(auto u: ve){
                    bel[u] = "";
                }              

                bel[i] = "imposter";
                int ansj = solve(i, ve);     

                if(max(ansi, ansj) == -1){
                    frag = true;
                    break;
                }              

                ans += max(ansi, ansj);                                     
            }
        }

        if(frag){
            cout << -1 << "\n";
        }else{
            cout << ans << "\n";
        }

        for(int i = 1 ; i <= n ; i++){
            bel[i] = "";
            adj[i].clear();
        }
    }
 
    return 0;
}