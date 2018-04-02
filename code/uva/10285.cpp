#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int tab[N][N];
int r, c;
int vi[] = {0, 0, -1, 1}, vj[] = {1, -1, 0, 0};
vector<int>top_sort;
int cor[N * N];
int l[N * N];

bool ok(int i, int j){
    return i >= 0 && i < r && j >= 0 && j < c;
}

void dfs(int x){
    int i = x / c, j = x % c;
    cor[x] = 1;

    for(int k = 0 ; k < 4 ; k++){
        int ti = i + vi[k], tj = j + vj[k];

        if(ok(ti, tj)){
            if(tab[ti][tj] < tab[i][j] && cor[ti * c + tj] == 0){
                dfs(ti * c + tj);
            }
        }
    }

    top_sort.push_back(x);
}

int main (){
    int t;
    ios::sync_with_stdio(false);
    
    cin >> t;

    while(t--){
        string s;
        memset(cor, 0, sizeof cor);
        cin >> s;

        cin >> r >> c;

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                cin >> tab[i][j];
                l[i * c + j] = 1;
            }
        }

        for(int i = 0 ; i < r * c ; i++){
            if(cor[i] == 0){
                dfs(i);
            }
        }

        for(int x = r * c - 1 ; x >= 0 ; x--){
            int i = top_sort[x] / c, j = top_sort[x] % c;

            for(int k = 0 ; k < 4 ; k++){
                int ti = i + vi[k], tj = j + vj[k];

                if(ok(ti, tj)){
                    int v = ti * c + tj;

                    if(tab[ti][tj] < tab[i][j]){
                        l[v] = max(l[v], l[top_sort[x]] + 1);
                    }
                }
            }
        }
        
        int res = -1;
        
        for(int x = 0 ; x < r * c ; x++){
            res = max(res, l[x]);
        }

        cout << s << ": " << res <<  endl;

        top_sort.clear();
    }

    return 0;
}