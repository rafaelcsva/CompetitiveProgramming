//03, 10, 2018, 17:51:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll n, m, k;

bool can(ll mid){
    ll an = n;
    ll am = m;

    if(k * mid - 1LL >= am){
        return true;
    }

    an -= k * mid;
    am -= (k * mid - 1LL);

    ll cnt = am / (k - 1LL);

    if(am % (k - 1LL)){
        cnt++;
    }

    cnt--;

    if(cnt + am > an){
        return false;
    }else{
        return true;
    }
}  

const int N = 2, M = 40;
int val[N];

const ll mod = 1e9 + 9;

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

    cin >> n >> m >> k;

    ident.mat[0][0] = ident.mat[1][1] = 1;
    base.mat[0][0] = 2;
    base.mat[0][1] = 2;
    base.mat[1][1] = 1;

    fi.mat[0][0] = 2LL * k;
    fi.mat[1][0] = k;

    ll lo = 1LL, hi = n;
    ll r = -1LL;

    while(lo <= hi){
        ll mid = (lo + hi) / 2LL;

        if(can(mid)){
            r = mid;
            hi = mid - 1LL;
        }else{
            lo = mid + 1LL;
        }
    }

    // cout << r << endl;

    if(r > 1){
        base = fast_pow(base, r - 2);
        base = base * fi;

        ll tot = base.mat[0][0];
        tot %= mod;

        tot += m - k * (r - 1LL);

        tot %= mod;
        
        cout << tot << endl;
    }else{
        cout << m << endl;
    }

    return 0;
}