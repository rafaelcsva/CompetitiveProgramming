//05, 10, 2018, 10:48:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;


const int N = 2, M = 40;
int val[N];

const ll mod = 1e9 + 7;

struct matrix{
    ll mat[N][N];
    
    matrix operator *(matrix &other){
        matrix ans;
        
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                ans.mat[i][j] = 0LL;
                
                for(int k = 0 ; k < N ; k++){
                    ans.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                    ans.mat[i][j] %= mod;
                }
            }
        }
        
        return ans;
    }
};

matrix base, ident, fi;

matrix fast_pow(matrix &base, ll p){
    if(p == 0LL){
        return ident;
    }
    
    if(p == 1LL){
        return base;
    }
    
    matrix r = fast_pow(base, p / 2LL);
    
    r = r * r;
    
    if(p & 1LL){
        r = r * base;
    }
    
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b, n, x;

    scanf("%lld %lld %lld %lld", &a, &b, &n, &x);

    base.mat[0][0] = a;
    base.mat[0][1] = b;
    base.mat[1][1] = 1;
    ident.mat[0][0] = ident.mat[1][1] = 1;
    
    fi.mat[0][0] = x;
    fi.mat[1][0] = 1;

    base = fast_pow(base, n);

    base = base * fi;

    printf("%lld\n", base.mat[0][0]);

    return 0;
}