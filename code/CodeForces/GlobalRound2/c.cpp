//06, 04, 2019, 09:00:27 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 510;
int a[N][N];
int b[N][N];
int mark[N][N];
int n, m;

bool process(int i, int j){
    mark[i][j] = false;
    int find_col = -1;

    for(int k = j + 1 ; k < m ; k++){
        if(mark[i][k]){
            find_col = k;
            mark[i][k] = false;
            break;
        }
    }

    if(find_col == -1){
        return false;
    }

    int find_row = -1;

    for(int k = i + 1 ; k < n ; k++){
        if(mark[k][j]){
            find_row = k;
            mark[k][j] = false;
            break;
        }
    }

    if(find_row == -1){
        return false;
    }

    mark[find_row][find_col] = !mark[find_row][find_col];

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d", &b[i][j]);

            mark[i][j] = (a[i][j] != b[i][j]);
        }
    }

    bool ok = true;

    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            if(mark[i][j]){
                if(!process(i, j)){
                    printf("No\n");
                    return 0;
                }
            }
        }
    }

    printf("Yes\n");
    
    return 0;
}