#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

typedef pair< int, int >	pii;
const int N = 310;
int a[N];
map< pii, ll > mp[N];
const ll mod = 998244353LL;
int n;
int tot = 0;

ll solve(int i, int sum1, int sum2){
	if(i == n){
		int sum3 = (tot - sum1 - sum2);

		if(sum1 == 0 || sum2 == 0 || sum3 == 0){
			return false;
		}

		vector< int > v;

		v.push_back(sum1);
		v.push_back(sum2);
		v.push_back(sum3);

		sort(v.begin(), v.end());

		return v[2] < v[0] + v[1];
	}

	if(mp[i].count({sum1, sum2}) != 0){
		return mp[i][{sum1, sum2}];
	}

	mp[i][{sum1, sum2}] = (solve(i + 1, sum1 + a[i], sum2) + solve(i + 1, sum1, sum2 + a[i]) + solve(i + 1, sum1, sum2)) % mod;

	return mp[i][{sum1, sum2}];
}

int main(){
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		tot += a[i];
	}

	printf("%lld\n", (solve(0, 0, 0) ) % mod);

	return 0;
}