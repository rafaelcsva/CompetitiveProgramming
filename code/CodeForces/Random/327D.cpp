//31, 07, 2018, 10:28:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 510;
char tab[N][N];
int n, m;

typedef struct{
    char c;
    int i, j;
}Command;

typedef pair<int, pii>  pipii;
priority_queue< pipii >pq;
vector< Command > operations;
int vi[] = {0, -1, 0, 1};
int vj[] = {-1, 0, 1, 0};
bool marked[N][N];

bool ok(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

int sum_adj(int i, int j){
    int qtd = 0;

    for(int x = 0 ; x < 4 ; x++){
        int ti = vi[x] + i;
        int tj = vj[x] + j;

        if(ok(ti, tj) && tab[ti][tj] == 'B'){
            qtd++;
        }
    }

    return qtd;
}

void dfs(int i, int j, int ti, int tj){
    operations.push_back({'B', i + 1, j + 1});
    tab[i][j] = 'B';
    marked[i][j] = true;

    for(int k = 0 ; k < 4 ; k++){
        int tmpi = i + vi[k], tmpj = j + vj[k];

        if(ok(tmpi, tmpj) && tab[tmpi][tmpj] == '.' && !marked[tmpi][tmpj]){
            dfs(tmpi, tmpj, ti, tj);
        }
    }

    if(i != ti || j != tj){
        operations.push_back({'D', i + 1, j + 1});
        operations.push_back({'R', i + 1, j + 1});
        tab[i][j] = 'R';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("\n%c", &tab[i][j]);
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(tab[i][j] == '.' && !marked[i][j]){
                dfs(i, j, i, j);
            }
        }
    }
    
    // int score = 0;

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < m ; j++){
    //         printf("%c", tab[i][j]);

    //         if(tab[i][j] == 'B'){
    //             score += 100;
    //         }else if(tab[i][j] == 'R'){
    //             score += 200;
    //         }
    //     }
    //     printf("\n");
    // }
    
    // printf("scored %d\n", score);
    
    printf("%lu\n", operations.size());

    for(Command u : operations){
        printf("%c %d %d\n", u.c, u.i, u.j);
    }

    return 0;
}