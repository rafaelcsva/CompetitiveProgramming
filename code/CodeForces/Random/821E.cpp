//16, 10, 2018, 14:53:48 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9 + 7;
const int N = 20;

struct matrix{
    ll mat[N + 4][N + 4];
    
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
    
matrix fast_pow(matrix &base, ll x){
    if(x == 1LL){
        return base;
    }
    
    if(x == 0){
        return ident;
    }
    
    matrix a = fast_pow(base, x / 2LL);
    a = a * a;
    
    if(x & 1LL){
        a = a * base;
    }
    
    return a;
}

const int M = 110;
ll n, k;
ll a[M], b[M];
int c[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0 ; i < N ; i++){
        ident.mat[i][i] = 1LL;
    }

    scanf("%lld %lld", &n, &k);
    
    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld %d", &a[i], &b[i], &c[i]);
        b[i] = min(b[i], k);
    }

    in.mat[0][0] = 1LL;

    for(int i = 0 ; i < n ; i++){
        memset(&base, 0, sizeof(matrix));

        for(int j = 0 ; j <= c[i] ; j++){
            base.mat[j][j] = 1LL;
            if(j != 0){
                base.mat[j][j - 1] = 1LL;
            }

            if(j != c[i]){
                base.mat[j][j + 1] = 1LL;
            }
        }

        base = fast_pow(base, b[i] - a[i]);
        in = base * in;
    }

    printf("%lld\n", in.mat[0][0]);

    return 0;
}