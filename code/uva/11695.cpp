//22, 04, 2018, 08:42:36 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii>  pipii;
vector<pii>edges;
typedef long long ll;
const int N = 3000;
int dis[N];
int adj[N][N];
vector<vector<int> > adjList;
int test;
int n;

int dfs(int u, int f, int r){
    dis[u] = r;
    int d = r;

    for(int i = 0 ; i < adjList[u].size() ; i++){
        int v = adjList[u][i];

        if(v == f){
            continue;
        }
        
        if(adj[u][v] == test){
            d = max(dfs(v, u, r + 1), d);
        }
    }

    return d;
}

int vertex_at_distance(int d){
    for(int i = 1 ; i <= n ; i++){
        if(dis[i] == d){
            return i;
        }
    }

    while(true){
        
    }
}

bool find_center(int u, int f, int d, pii &r){
    
    if(dis[u] == d){
        if(d == 0){
            r.first = u;
        }
        
        return true;
    }
    
    for(int i = 0 ; i < adjList[u].size() ; i++){
        int v = adjList[u][i];

        if(v != f && adj[u][v] == test){
            if(find_center(v, u, d, r)){
                if(dis[u] == d / 2){
                    r.first = u;
                }else if(dis[u] == d / 2 + (d % 2)){
                    r.second = u;
                }

                return true;
            }
        }    
    }

    return false;
}

pipii find_center_diameter(int u){
    memset(dis, -1, sizeof dis);

    int d = dfs(u, u, 0);
    int m = vertex_at_distance(d);
    d = dfs(m, m, 0);
    
    pii r = {-1, -1};
    find_center(m, m, d, r);

    return {d, r};
}

void mark(int u, int v){
    adj[u][v] = adj[v][u] = test;
}

void unmark(int u, int v){
    adj[u][v] = adj[v][u] = 0;
}
void printEdges(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(adj[i][j] == test){
                printf("(%d, %d)\n", i, j);
            }
        }
    }
}

void addEd(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void remove(int u, int v){
    adjList[u].pop_back();
    adjList[v].pop_back();
}

int main(){
    int t;

    cin >> t;
    
    for(test = 1 ; test <= t ; test++){
        cin >> n;
        
        adjList.clear();
        adjList.resize(n + 1);

        for(int i = 1 ; i < n ; i++){
            int u, v;

            cin >> u >> v;
            
            edges.push_back({u, v});
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
            mark(u, v);
        }

        int mn = int(1e8);
        pii add;
        int index = 0;

        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i].first, v = edges[i].second;
            unmark(u, v);
            //printEdges();
            
            pii c1 = find_center_diameter(u).second;
            pii c2 = find_center_diameter(v).second;

            int v1[] = {c1.first, c1.second}, v2[] = {c2.first, c2.second};
            
            for(int k = 0 ; k < 1 ; k++){
                for(int j = 0 ; j < 1 ; j++){
                    
                    if(v1[k] == -1 || v2[j] == -1){
                        continue;
                    }
                    
                    addEd(v1[k], v2[j]);
                    mark(v1[k], v2[j]);
                    int r = find_center_diameter(v1[k]).first;
                    
                    if(r < mn){
                        mn = r;
                        add = {v1[k], v2[j]};
                        index = i;
                    }

                    unmark(v1[k], v2[j]);
                    remove(v1[k], v2[j]);
                }
            }

            mark(u, v);
        }
        
        cout << mn << endl;
        cout << edges[index].first << ' ' << edges[index].second << endl;
        cout << add.first << ' ' << add.second << endl;

        edges.clear();
    }

    return 0;
}