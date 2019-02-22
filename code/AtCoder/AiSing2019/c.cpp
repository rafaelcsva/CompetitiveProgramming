//12, 01, 2019, 10:16:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int H = 410, W = 410, N = H * W, D = 4;
bool marked[N];
string tab[H];
int h, w;
char colors[2] = {'.', '#'};
vector< int > adj[N];
int bel[N];
int comp_num;
ll qtd[N][2];
int vi[D] = {-1, 1, 0, 0};
int vj[D] = {0, 0, -1, 1};

bool ok(int x, int y){
    return 0 <= x && x < h && 0 <= y && y < w;
}

void dfs(int u, int color){
    marked[u] = true;

    int ii = u / w;
    int jj = u % w;
    qtd[comp_num][color]++;

    for(int i = 0 ; i < D ; i++){
        int xi = vi[i] + ii;
        int xj = vj[i] + jj;

        if(ok(xi, xj)){
            int v = xi * w + xj;
            
            if(tab[xi][xj] == colors[!color] && !marked[v]){
                dfs(v, !color);
            }
        } 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;

    for(int i = 0 ; i < h ; i++){
        cin >> tab[i];
    }    

    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            int v = i * w + j;

            if(tab[i][j] == '#' && !marked[v]){
                comp_num++;
                dfs(v, 1);
            }
        }
    }

    ll tot = 0LL;

    for(int i = 1 ; i <= comp_num ; i++){
        tot += qtd[i][0] * qtd[i][1];
    }

    cout << tot << endl;

    return 0;
}