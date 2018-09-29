//11, 08, 2018, 17:48:58 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1010;
int tab[N][N];
bool lin[N], col[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, v;

    scanf("%d %d %d", &n, &k, &v);

    for(int i = 1, j = n ; i <= n ; i++, j--){
        printf("1 %d %d\n", i, j);
        fflush(stdout);

        int x;

        scanf("%d", &x);

        tab[i][j] = x;
    }

    for(int i = 2, j = n ; i <= n ; i++, j--){
        printf("1 %d %d\n", i, j);
        fflush(stdout);

        int x;

        scanf("%d", &x);

        tab[i][j] = x;
    }

    printf("1 %d %d\n", 1, n - 1);
    fflush(stdout);

    int x;

    scanf("%d", &x);

    tab[1][n - 1] = x;

    printf("1 %d %d\n", n - 1, 1);

    fflush(stdout);

    scanf("%d", &x);

    tab[n - 1][1] = x;

    if(tab[1][n] < tab[1][n - 1]){
        lin[1] = true;
    }

    if(tab[n][1] < tab[n - 1][1]){
        col[1] = true;
    }

    for(int i = 2, j = n ; i <= n ; i++, j--){
        if(tab[i][j] < tab[i - 1][j]){
           col[j] = true;
        }

        if(tab[i][j] < tab[i][j - 1]){
            lin[i] = true;
        }
    }

    return 0;
}