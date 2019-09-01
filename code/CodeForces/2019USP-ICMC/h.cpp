#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long	ll;

const int N = 9;
const ll mod = ll(1e9 + 7);

class matrix{
public:
	int n;
	ll mat[N][N];
	matrix *ident, *base;

	matrix(int n){
		this->n = n;

		ident = new matrix();
		base = new matrix();
		base->n = ident->n = n;

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				base->mat[i][j] = 0LL;
				ident->mat[i][j] = (i == j);
			}
		}
	}

	matrix(){

	}

	matrix operator *(matrix &other){
		matrix ans;

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				ans.mat[i][j] = 0LL;

				for(int k = 0 ; k < n ; k++){
					ans.mat[i][j] += this->mat[i][k] * other.mat[k][j];
					ans.mat[i][j] %= mod;
				}
			}
		}

		ans.n = n;

		return ans;
	}

	matrix pow(ll p){
		matrix r = *ident;
		matrix d = *this;

		while(p){
			if(p & 1LL){
				r = r * d;
			}

			d = (d * d);
			p >>= 1LL;
		}

		return r;
	}

	void add_clause(int lin, vector< ll > clause){
		for(int i = 0 ; i < n ; i++){
			this->mat[lin][i] = clause[i];
		}

		this->base->mat[lin][0] = clause[n];
		// printf("%lld\n", clause[n]);
	}

	matrix get_answer_matrix(ll e){
		matrix u = this->pow(e);

		return u * (*(this->base));
	}

	ll get_answer(ll e){
		matrix u = this->get_answer_matrix(e);

		ll ans = 0LL;

		for(int i = 0 ; i < n ; i++){
			ans += u.mat[i][0];

			if(ans >= mod) ans -= mod;
		}

		return ans;
	}
};

int main(){
	ll n;

	scanf("%lld", &n);

	matrix *hm = new matrix(N);

	hm->add_clause(0, {1, 1, 1, 0, 0, 0, 0, 0, 0, 3});
	hm->add_clause(1, {0, 0, 0, 1, 1, 1, 0, 0, 0, 3});
	hm->add_clause(2, {0, 0, 0, 0, 0, 0, 1, 1, 1, 3});
	hm->add_clause(3, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1});
	hm->add_clause(4, {0, 0, 0, 1, 1, 0, 0, 0, 0, 2});
	hm->add_clause(5, {0, 0, 0, 0, 0, 0, 1, 1, 1, 3});
	hm->add_clause(6, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1});
	hm->add_clause(7, {0, 0, 0, 1, 0, 0, 0, 0, 0, 1});
	hm->add_clause(8, {0, 0, 0, 0, 0, 0, 1, 1, 1, 3});

	printf("%lld\n", hm->get_answer(n - 3LL));

	return 0;
}