//30, 10, 2018, 22:45:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 50 * 50;
int color[N];
bool marked[N][N];
int val[N][N];
vector< int > adj[N];
vector< pii > vert[N];
int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};

bool ok(int i, int j, int n, int m){
    return i >= 0 && i < n && j >= 0 && j < m;
}

void get_vertice(int num, int i, int j, char cl, vector <string> &board){
    int n = board.size();
    int m = board[0].length();

    vert[num].push_back({i, j});
    marked[i][j] = true;
    val[i][j] = num;

    for(int k = 0 ; k < 4 ; k++){
        int xi = i + vi[k];
        int xj = j + vj[k];

        if(ok(xi, xj, n, m)){
            if(!marked[xi][xj] && board[xi][xj] == cl){
                get_vertice(num, xi, xj, cl, board);
            }
        }
    }
}

bool is_adj(vector< pii > &a, vector< pii > &b){
    for(int i = 0 ; i < a.size() ; i++){
        for(int j = 0 ; j < b.size() ; j++){
            int dis = abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second);

            if(dis == 1){
                return true;
            }
        }
    }

    return false;
}

void dfs(int vert){
    bool mark[10];
    memset(mark, false, sizeof mark);

    for(int i = 0 ; i < adj[vert].size() ; i++){
        int u = adj[vert][i];

        if(color[u] != -1){
            mark[color[u]] = true;
        }
    }

    int mn = -1;

    for(int i = 0 ; i < 10 ; i++){
        if(!mark[i]){
            mn = i;
            break;
        }
    }

    color[vert] = mn;

    for(int i = 0 ; i < adj[vert].size() ; i++){
        int u = adj[vert][i];

        if(color[u] == -1){
            dfs(u);
        }
    }
}

class BoardCoveringDiv2{
    public:
        vector <string> make(vector <string> board){
            int n = board.size();
            int m = board[0].length();

            int sz = 0;

            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(board[i][j] != '#' && !marked[i][j]){
                        get_vertice(sz, i, j, board[i][j], board);
                        sz++;
                    }
                }
            }

            for(int i = 0 ; i < sz ; i++){
                for(int j = i + 1 ; j < sz ; j++){
                    if(is_adj(vert[i], vert[j])){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }

            memset(color, -1, sizeof color);

            dfs(0);

            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(board[i][j] != '#'){
                        board[i][j] = char(color[val[i][j]] + '0');
                    }
                }
            }

            return board;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}