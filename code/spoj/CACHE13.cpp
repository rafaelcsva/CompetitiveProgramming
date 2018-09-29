//11, 09, 2018, 18:29:07 Rafaelcs cpp
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

matrix ident, base, en;

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

    base.mat[0][0] = 2, base.mat[0][1] = 2;
    base.mat[1][0] = 2, base.mat[1][1] = 3;

    for(int i = 0 ; i < N ; i++){
        ident.mat[i][i] = 1LL;
        en.mat[i][0] = 6LL;
    }

    ll n;

    scanf("%lld", &n);

    base = fast_pow(base, n - 1LL);

    base = base * en;

    printf("%lld\n", (base.mat[0][0] + base.mat[1][0]) % mod);

    return 0;
}