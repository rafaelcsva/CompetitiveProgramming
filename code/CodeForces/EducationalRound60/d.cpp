//18, 02, 2019, 13:34:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 101, M = 40;
int val[N];
ll dp[N];
const ll mod = ll(1e9) + 7;
ll n, m;

struct matrix{
    int n;
    ll mat[N][N];

    matrix operator *(matrix &other){
        matrix ans;
        ans.n = m;

        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= n ; j++){
                ans.mat[i][j] = 0LL;
                
                for(int k = 0 ; k <= n ; k++){
                    ans.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                    ans.mat[i][j] %= mod;
                }
            }
        }
        
        return ans;
    }
};

matrix ident, base, en;

matrix fast_pow(matrix &base, ll p){
    matrix r = ident;
    matrix carry = base;
    
    while(p != 0LL){

        if(p & 1LL){
            r = r * carry;
        }

        p >>= 1LL;

        carry = carry * carry;
    }
    // cout << "have " << it << " iteration!" << endl;

    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    if(n < m){
        cout << 1LL << endl;
        return 0;
    }

    for(int i = 0 ; i < m ; i++){
        dp[i] = 1LL;
    }

    dp[m] = 2LL;

    base.n = m;
    ident.n = m;
    en.n = m;

    for(int i = 0 ; i <= m ; i++){
        // cout << dp[m - i] << " --- " << endl;
        en.mat[i][0] = dp[m - i];
        ident.mat[i][i] = 1LL;

        if(i == 0){
            base.mat[i][0] = 1LL;
            base.mat[i][m - 1] = 1LL;
        }else{
            base.mat[i][i - 1] = 1LL;
        }
    }
    // cout << "aqui!\n" << endl;
    base = fast_pow(base, n - m);
    // cout << base.n << " n " << endl;
    // for(int i = 0 ; i <= m ; i++){
    //     // cout << en.mat[i][0] << "---" << endl;
    //     for(int j = 0 ; j <= m ; j++){
    //         cout << base.mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    base = base * en;

    cout << base.mat[0][0] << endl;

    return 0;
}