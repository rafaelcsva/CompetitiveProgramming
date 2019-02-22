#include <bits/stdc++.h>
    
using namespace std;
    
typedef long long   ll;
    
const int N = 45, M = int(1e5 + 100);
const ll mod = 1e9 + 7;
typedef pair< int, int >    pii;
    
pii qu[M];
ll resp[M];
    
void MOD(ll &x){
    if(x > mod){
        x %= mod;
    }
}
    
void MOD1(ll &x){
    if(x > mod){
        x -= mod;
    }
}
    
struct matrix{
    ll mat[N][N];
    
    matrix operator *(matrix &other){
        matrix r;
    
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                r.mat[i][j] = 0LL;
    
                for(int k = 0 ; k < N ; k++){
                    r.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                    MOD(r.mat[i][j]);
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
    
const int D = 4;
int v[D] = {0, 1, 2, 3};
int mp[N];
    
void take_digits(int &d1, int &d2, int &d3, int x){
    d1 = x % 10;
    x /= 10;
    d2 = x % 10;
    x /= 10;
    d3 = x % 10;
}
    
bool valid(int x){
    int d1, d2, d3;
    
    take_digits(d1, d2, d3, x);
    
    set<int>st;
    
    st.insert(d1);
    st.insert(d2);
    st.insert(d3);
    
    return st.size() == 3 || st.find(0) != st.end();
}
    
bool can_transform(int x1, int x2){
    int d1, d2, d3;
    
    take_digits(d1, d2, d3, x2);
    
    for(int d = 0 ; d < 10 ; d++){
        int num = d1 * 10 + d2 * 100 + d;
    
        if(num == x1){
            return true;
        }
    }
    
    return false;
}
    
int main(){
    int t;
    
    int s = 0;
    
    for(int i = 0 ; i < D ; i++){
        for(int j = 0 ; j < D ; j++){
            for(int k = 0 ; k < D ; k++){
                int num = i * 100 + j * 10 + k;
    
                if(valid(num)){
                    mp[s++] = num;
                }
            }
        }
    }
    // printf("tenho %d\n", s);
    for(int i = 0 ; i < s ; i++){
        ident.mat[i][i] = 1LL;
    
        if(!valid(mp[i])){
            continue;
        }
        
        in.mat[i][0] = 1LL;
        // printf("%d eh valido!\n", mp[i]);
    
        for(int j = 0 ; j < s ; j++){
            if(!valid(mp[j])){
                continue;
            }
    
            if(can_transform(mp[i], mp[j])){
                base.mat[i][j] = 1LL;
            }
        }
    }
    
    scanf("%d", &t);
    
    for(int i = 0 ; i < t ; i++){
        int n;
        
        scanf("%d", &n);
        
        qu[i] = {n, i};
    }
    
    sort(qu, qu + t);
    
    int past = 3;
    
    matrix x;
    matrix r = ident;
    
    for(int i = 0 ; i < t ; i++){
        int n = qu[i].first;
    
        if(n < 3){
            int r = 4;
    
            if(n > 1){
                r *= 4;
            }
    
            resp[qu[i].second] = r;
        }else{
            if(n - past){
                x = fast_pow(base, n - past);
        
                r = r * x;
                past = n;
            }
            
            x = r * in;
            
            ll sum = 0LL;
    
            for(int k = 0 ; k < N ; k++){
                sum += x.mat[k][0];
                MOD1(sum);
            }
    
            resp[qu[i].second] = sum;
        }
    }
    
    for(int i = 0 ; i < t ; i++){
        printf("%lld\n", resp[i]);
    }
    
    return 0;
}   