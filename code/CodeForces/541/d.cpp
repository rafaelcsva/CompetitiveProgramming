//23, 02, 2019, 08:38:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2010;
char tab[N][N];
vector< int > adj[2 * N], rev[2 * N];
int color[2 * N];
int number[2 * N];
int in[2 * N];
vector< int > starters;
int father[2 * N];
int level[N * 2];
vector< pii > con;
vector< int > nvlsc[N];
queue< int > q;

int find(int x){
    if(x == father[x]){
        return x;
    }

    return father[x] = find(father[x]);
}

void join(int u, int v){
    int x = find(u);
    int y = find(v);

    if(x != y){
        if(x < y){
            father[y] = x;
        }else{
            father[x] = y;
        }
    }
}

bool dfs(int u){
    color[u] = 1;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(color[v] == 1){
            return false;
        }else if(color[v] == 0){
            if(!dfs(v)){
                return false;
            }
        }
    }

    color[u] = 2;
    return true;
}

void dfs1(int u, int nvl){
    level[u] = nvl;
    nvlsc[nvl].push_back(u);

    for(int i = 0 ; i < rev[u].size() ; i++){
        int v = rev[u][i];

        if(level[v] == 0)
            dfs1(v, nvl + 1);
    }
}

void run_topological(queue< int > &q){
    while(!q.empty()){
        int u = q.front();
        // printf("u: %d\n", u);
        q.pop();

        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i];

            in[v]--;

            if(in[v] == 0){
                q.push(v);
            }

            number[v] = max(number[v], number[u] + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < (n + m) ; i++){
        father[i] = i;
    }

    for(int i = 0 ; i < n ; i++){
        scanf("\n%s", tab[i]);
        for(int j = 0 ; j < m ; j++){
            if(tab[i][j] == '='){
                join(i, j + n);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(tab[i][j] == '<'){
                adj[find(i)].push_back(find(n + j));
                rev[find(n + j)].push_back(find(i));
                in[find(n + j)]++;
            }else if(tab[i][j] == '>'){
                adj[find(n + j)].push_back(find(i));
                rev[find(i)].push_back(find(n + j));
                in[find(i)]++;
            }
        }
    }

    bool ok = true;

    for(int i = 0 ; i < n + m ; i++){
        if(!color[find(i)]){
            ok &= dfs(find(i));
        }
    }

    if(!ok){
        printf("No\n");
    }else{
        for(int i = 0 ; i < (n + m) ; i++){
            if(i == find(i) && in[i] == 0){
                number[i] = 1;
                q.push(i);
            }
        }

        // printf("%lu\n", q.size());

        run_topological(q);

        printf("Yes\n");

        for(int i = 0 ; i < n ; i++){
            printf("%d ", number[find(i)]);
        }

        printf("\n");

        for(int i = 0 ; i < m ; i++){
            printf("%d ", number[find(i + n)]);
        }
        printf("\n");
    }
    
    return 0;
}