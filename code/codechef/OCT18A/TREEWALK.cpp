//11, 10, 2018, 22:22:43 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353LL;
const int N = 210;

struct matrix{
    ll mat[N][N];
    
    matrix operator *(matrix &other){
        matrix r;
    
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                r.mat[i][j] = 0LL;
    
                for(int k = 0 ; k < N ; k++){
                    r.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                    r.mat[i][j] %= mod;
                }
            }
        }
    
        return r;
    }
};
    
matrix base, ident, in;
    
matrix fast_pow(matrix &base, int x){
    if(x == 1){
        return base;
    }
    
    if(x == 0){
        return ident;
    }
    
    matrix a = fast_pow(base, x / 2);
    a = a * a;
    
    if(x & 1){
        a = a * base;
    }
    
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n - 1 ; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        base.mat[u][v] = 1;
        base.mat[v][u] = 1;
    }

    // printf("sai aqui oh!\n");
    int r, k;

    scanf("%d %d", &r, &k);

    base = fast_pow(base, k);

    for(int i = 1 ; i <= n ; i++){
        char c = i == n ? '\n' : ' ';
        printf("%lld%c", base.mat[r][i], c);
    }
    
    return 0;
}