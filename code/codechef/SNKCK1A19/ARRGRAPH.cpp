//19, 10, 2018, 19:14:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int P = 15;
int primes[P] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
const int N = 50;
int a[N];
bool vis[N];
int n;
int tab[N + 20][N + 20];

int gcd(int i, int j){
    // printf("gcd(%d, %d) = %d\n",i, j, tab[i][j]);
    return tab[i][j];
}

void dfs(int u, int &cnt){
    vis[u] = true;
    cnt++;

    for(int i = 0 ; i < n ; i++){
        int g = gcd(a[i], a[u]);

        if(g == 1 && !vis[i]){
            dfs(i, cnt);
        }
    }
}

bool is_connected(){
    int c = 0;
    memset(vis, false, sizeof vis);

    dfs(0, c);

    // printf("c = %d\n", c);

    return c == n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    for(int i = 2 ; i <= N ; i++){
        for(int j = 2 ; j <= N ; j++){
            tab[i][j] = __gcd(i, j);
        }
    }

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }

        int change = 0;

        int p = 0;

        do{
            if(is_connected()){
                break;
            }
            change = 1;
            a[0] = primes[p];
            p++;
        }while(p <= P);

        printf("%d\n", change);

        for(int i = 0 ; i < n ; i++){
            char c = i == n - 1 ? '\n' : ' ';

            printf("%d%c", a[i], c);
        }
    }

    return 0;
}