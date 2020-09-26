#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 1LL << 8LL;
double linf = log(N + 10);
const int D = 20;
int dp[N + 1][N + 1][N + 1][D]; 
map< pair< ll, pair< ll, ll > >, bool > mp;

bool brute(ll a, ll b, ll x){
	if(x == 0){
		return true;
	}

	if(b > x){
		return false;
	}
	
	if(a == 0){
		return false;
	}

	if(x < 0){
		return false;
	}

	if(mp[{a, {b, x}}].count() > 0){
		return mp[{a, {b, x}}];
	}

	if(brute(a / 2, b * 3, x - a * b)){
		printf("%lld ", a * b);
		return true;
	}else{
		// printf("-->%d %d %d<--\n", a, b, x);
		if(!(brute(a / 2, b, x) || brute(a, b * 3, x))){
			// assert(false);
			return false;
		}else{
			return true;
		}
	}

	return false;
}

int main(){
	memset(dp, -1, sizeof dp);

	ll x;

	scanf("%lld", &x);

	ll a = 1LL << 60LL;
	ll b = 1;

	assert(brute(a, b, x));

	return 0;
}