//15, 10, 2018, 10:35:36 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const int N = 11;

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

ll s[N], a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    for(int i = 0 ; i < N ; i++){
        ident.mat[i][i] = 1LL;
    }

    scanf("%d", &t);

    while(t--){
        ll n, r, k;

        scanf("%lld %lld %lld", &n, &r, &k);

        for(int i = 0 ; i < r ; i++){
            scanf("%lld", &s[i]);
        }

        for(int i = 0 ; i < r ; i++){
            scanf("%lld", &a[i]);
        }

        if(n * k <= r){
            ll sum = 0LL;
            int taked = 0;

            for(int i = 1 ; i <= r ; i++){
                if(taked == n)
                    break;

                if(i % k == 0LL){
                    sum += s[i];
                }

                sum %= mod;
                taked++;
            }

            printf("%lld\n", sum);
        }else{
            memset(&base, 0, sizeof(matrix));
            memset(&in, 0, sizeof(matrix));

            for(int i = 0 ; i < r ; i++){
                for(int j = 0 ; j < r ; j++){
                    if(i == 0){
                        base.mat[i][j] = a[j];
                    }else{
                        base.mat[i][j] = (i == (j + 1));
                    }
                }

                in.mat[i][0] = s[r - i - 1];

                if((r - i) % k == 0){
                    if(i != 0){
                        in.mat[N - 1][0] += s[r - i - 1];
                        in.mat[N - 1][0] %= mod;
                    }
                }
            }

            ll adv = (k - r % k) % k;
            matrix aux = in;
            matrix d = fast_pow(base, adv);

            // printf("adv = %lld %lld\n", adv, in.mat[N - 1][0]);
            d.mat[N - 1][N - 1] = 1LL;
            in = d * in;
            // printf("in = %lld\n", in.mat[N - 1][0]);

            // d = d * base;
            // d.mat[N - 1][0] = d.mat[N - 1][N - 1] = 1LL;

            ll have = (r + k - 1LL) / k;

            ll need = n - have;

            matrix o = fast_pow(base, k);   
            o.mat[N - 1][0] = o.mat[N - 1][N - 1] = 1LL;

            // printf("need = %lld\n", need);
            o = fast_pow(o, need);

            // d = d * o;

            d = o * in;
            
            printf("%lld\n", (d.mat[N - 1][0] + d.mat[0][0]) % mod);      

            // base = fast_pow(base, 2LL);
            // base = base * aux;

            // printf("%lld\n", (base.mat[0][0]) % mod);  
        }
    }

    return 0;
}