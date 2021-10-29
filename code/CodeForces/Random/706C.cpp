#include <bits/stdc++.h>

using namespace std;

const int N = 510;
char tab[N][N];
int n, m;
// bool gone[N][N];
queue< pair< int, int > > q;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                scanf("\n%c", &tab[i][j]);
         
                if(i == 0){
                    tab[i][j] = 'X';
                }else if(tab[i][j] == 'X'){
                    q.push({i, j});
                }
            }
        }
        // printf("sai!\n");

        while(!q.empty()){
            auto u = q.front();
            q.pop();

            int i = u.first;
            int j = u.second;
            // printf("%d %d\n", i, j);
            // fflush(stdout);
            if(j != m - 1 && tab[i][j + 1] == 'X'
                || (j != 0 && tab[i][j - 1] == 'X')
                ){
                continue;
            }

            if(tab[i - 1][j] != 'X'){
                tab[i - 1][j] = 'X';
                q.push({i - 1, j});
            }

            if(i != n - 1 && tab[i + 1][j] != 'X'){
                tab[i + 1][j] = 'X';
                q.push({i + 1, j});
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                printf("%c", tab[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}