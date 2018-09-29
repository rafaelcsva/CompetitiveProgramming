//26, 09, 2018, 13:50:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(3e5 + 100);
int p[N];
vector< vector< int > > adj;
int father[N];
int level[N];
map< pii, int > mp;
int dis[N];
int ant[N];
set< int > ind;
queue< int > q;
int n, k, d;

void bfs(){
    memset(dis, -1, sizeof dis);

    for(int i = 0 ; i < k ; i++){
        q.push(p[i]);
        dis[p[i]] = 0;
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i];

            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                father[v] = u;
                q.push(v);
            }else{
                if(father[u] != v)
                    ind.insert(mp[{u, v}]);
            }
        }
    }
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    scanf("%d %d %d", &n, &k, &d);

    adj.resize(n + 2);

    for(int i = 0 ; i < k ; i++){
        scanf("%d", &p[i]);
    }

    for(int i = 0 ; i < n - 1; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
        adj[v].push_back(u);

        mp[{u, v}] = i + 1;
        mp[{v, u}] = i + 1;
    }
 
    bfs();

    printf("%lu\n", ind.size());

    for(set< int >::iterator it = ind.begin() ; it != ind.end() ; it++){
        printf("%d ", *it);
    }

    printf("\n");

    return 0;
}