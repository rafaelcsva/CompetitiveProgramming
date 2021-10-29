#include <bits/stdc++.h>

using namespace std;

const int N = 9;
int alc[N];
vector< int > adj[N];
map< vector< int >, int > dis;
queue< vector< int > > q;

void bfs(vector< int > root){
    dis[root] = 0;
    q.push(root);
    
    while(!q.empty()){
        auto u = q.front();
        q.pop();

        memset(alc, -1, sizeof alc);

        for(int i = 0 ; i < u.size() ; i++){
            alc[u[i]] = i;
        }

        int emptvertex = -1;
        for(int i = 0 ; i < N ; i++){
            if(alc[i] == -1){
                emptvertex = i;
                break;
            }
        }

        assert(emptvertex != -1);

        for(auto v: adj[emptvertex]){
            auto tmp = u;
            tmp[alc[v]] = emptvertex;

            if(dis.count(tmp) == 0){
                dis[tmp] = dis[u] + 1;
                q.push(tmp);
            }
        }
    }
}

int main(){
    int m;

    scanf("%d", &m);

    for(int i = 0 ; i < m ; i++){
        int ui, vi;
        scanf("%d %d", &ui, &vi);

        ui--, vi--;
    
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }

    vector< int > root;
    vector< int > dest;

    for(int i = 0 ; i < N - 1 ; i++){
        int xi;

        scanf("%d", &xi);

        xi--;
        root.push_back(xi);
        dest.push_back(i);
    }

    bfs(root);

    if(dis.count(dest) == 0){
        printf("-1\n");
    }else{
        printf("%d\n", dis[dest]);
    }

    return 0;
}