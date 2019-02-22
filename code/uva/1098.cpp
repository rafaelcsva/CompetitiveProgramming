//03, 10, 2018, 10:50:50 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 10;
bool ver[N][N];
int mark[N][N];
pii pt[N];
int cor[N][N];
const int T = 4;
int vi[] = {0, 0, -1, 1}, vj[] = {1, -1, 0, 0};
int test;
int n, m;

void dfs(int l, int c){
    if(l < 0 || l >= n || c < 0 || c >= m){
        return;
    }

    if(cor[l][c] == test || ver[l][c]){
        return;
    }

    cor[l][c] = test;

    for(int i = 0 ; i < T ; i++){
        dfs(l + vi[i], c + vj[i]);
    }
}

int backtrack(int l, int c, int steps, int taked){
    if(l < 0 || l >= n || c < 0 || c >= m){
        return 0;
    }

    if(ver[l][c]){
        return 0;
    }
    ver[l][c] = true;

    if(mark[l][c]){
        if((mark[l][c] * m * n) / 4 != steps){
            ver[l][c] = false;
            return 0;
        }
    }

    for(int i = 1 ; i <= 3 ; i++){
        if(!ver[pt[i].first][pt[i].second]){
            int mn = abs(l - pt[i].first) + abs(c - pt[i].second);

            if((mn + steps) > (i * m * n) / 4){
                ver[l][c] = false;
                return 0;
            }
        }
    }

    if(l == 0 && c == 1){
        ver[l][c] = false;
        return taked == (n * m);
    }

    test++;
    dfs(0, 1);
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!ver[i][j]){
                if(cor[i][j] != test){
                    ver[l][c] = false;
                    return 0;
                }
            }
        }
    }

    int tot = 0;

    for(int i = 0 ; i < T ; i++){
        tot += backtrack(l + vi[i], c + vj[i], steps + 1, taked + 1);
    }

    ver[l][c] = false;

    return tot;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(scanf("%d %d", &n, &m) != EOF){
        if(n == 0 && m == 0){
            break;
        }

        for(int i = 1 ; i <= 3 ; i++){
            int l, c;

            scanf("%d %d", &l, &c);

            mark[l][c] = i;

            pt[i] = {l, c};
        }

        printf("Case %d: %d\n", t++, backtrack(0, 0, 1, 1));

        memset(mark, 0, sizeof mark);
        memset(ver, false, sizeof ver);
    }

    return 0;
}