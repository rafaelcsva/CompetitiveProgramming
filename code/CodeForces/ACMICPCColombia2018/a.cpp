#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;

const int N = 5, M = 40;
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

ll MOD(ll val){
    return (val % mod + mod) % mod;
}

int vt[N] = {16, 9, 4, 1, 0};
int ve[N] = {72658, 4388, 265, 16, 1};

int main(){
    ll n;
    
    for(int i = 0 ; i < N ; i++){
        ident.mat[i][i] = 1LL;
        base.mat[0][i] = vt[i];
        en.mat[i][0] = ve[i];
    }

    for(int i = 1, j = 0 ; i < N ; i++, j++){
        base.mat[i][j] = 1LL;
    }

    scanf("%lld", &n);

    if(n < M){
        int t = n / 10;

        int sum = 0;

        for(int k = N - 1 ; t >= 0 ; t--, k--){
            sum += ve[k];
        }

        printf("%d\n", sum);
    }else{
        ll p = (n - 40LL) / 10LL;

        base = fast_pow(base, p);

        base = base * en;

        ll sum = 0LL;

        for(int i = 0 ; i < N ; i++){
            sum += base.mat[i][0];
            sum = MOD(sum);
        }

        if(n % 10LL >= 5LL){
            sum -= base.mat[N - 1][0];
            sum = MOD(sum);
        }

        printf("%lld\n", sum);
    }
	// val[0] = 1;
	
	// for(int i = 1 ; i < N ; i++){
	// 	for(int j = i - 1, k = 0 ; j >= 0 ; j--, k++){
	// 		val[i] += v[k] * val[j];
	// 	}
	// }
	
	// int sum = 0;
	
	// for(int i = 0 ; i < N ; i++){
	// 	sum += val[i];
	// 	printf("%d %d\n", i, val[i]);
	// }
	
	// printf("%d\n", sum);
	
	return 0;
}