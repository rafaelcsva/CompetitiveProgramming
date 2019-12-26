#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = 1010;
ll a[N];
ll mt[N][N];
int n;

bool is_possible(ll val){
	a[1] = val;

	for(int i = 2 ; i <= n ; i++){
		a[i] = mt[1][i] / a[1];
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(i == j) continue;

			if(a[i] * a[j] != mt[i][j]){
				return false;
			}
		}
	}	

	return true;
}

int main(){
	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			scanf("%lld", &mt[i][j]);
		}
	}

	for(ll i = 1LL ; i * i <= mt[1][2] ; i++){
		if(mt[1][2] % i == 0){
			ll div1 = mt[1][2] / i;

			if(is_possible(i)){
				for(int i = 1 ; i <= n ; i++){
					printf("%lld ", a[i]);
				}

				return 0;
			}

			if(is_possible(div1)){
				for(int i = 1 ; i <= n ; i++){
					printf("%lld ", a[i]);
				}

				return 0;
			}
		}
	}

	assert(false);

	return 0;
}