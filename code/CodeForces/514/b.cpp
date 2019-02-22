//05, 10, 2018, 11:42:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
bool mark[N][N];
char tab[N][N];

void run(int i, int j){
    for(int k = 0 ; k < 3 ; k++){
        if(tab[i][j + k] == '.'){
            return;
        }

        if(tab[i + k][j] == '.'){
            return;
        }

        if(tab[i + k][j + 2] == '.'){
            return;
        }

        if(tab[i + 2][j + k] == '.'){
            return;
        }
    }

    for(int k = 0 ; k < 3 ; k++){
        mark[i][j + k] = true;
    
        mark[i + k][j] = true;

        mark[i + k][j + 2] = true;

        mark[i + 2][j + k] = true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    scanf("%d %d", &n, &m);
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("\n%c", &tab[i][j]);
        }
    }

    for(int i = 0 ; i <= n - 3 ; i++){
        for(int j = 0 ; j <= m - 3 ; j++){
            run(i, j);
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(tab[i][j] == '#'){
                if(!mark[i][j]){
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }

    printf("YES\n");

    return 0;
}