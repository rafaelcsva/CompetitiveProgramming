#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

vector< int > digits;
int test;
ll dp[20][2][10][2];
int used[20][2][10][2];
map< ll, ll > res;

ll solve(int pos, bool is_less, int last_digit, bool flag){
	if(pos < 0){
		return flag;
	}

	int &us = used[pos][is_less][last_digit][flag];
	ll &ans = dp[pos][is_less][last_digit][flag];

	if(us == test){
		return ans;
	}

	us = test;
	ans = 0LL;

	if(is_less && flag){
		ll d = 1LL;

		for(int i = 0 ; i <= pos ; i++){
			d *= 10LL;
		}

		return ans = d;
	}

	for(int d = 0 ; d <= 9 ; d++){
		if(!is_less && digits[pos] < d){
			break;
		}

		ans += solve(pos - 1, is_less || (d < digits[pos]), flag ? 0 : d, flag || (d == 4 || (last_digit == 1 && d == 3)));
	}

	return ans;
}

ll get(ll x){
	if(res.count(x) != 0){
		return res[x];
	}

	digits.clear();

	while(x){
		digits.push_back(x % 10LL);
		x /= 10LL;
	}

	test++;

	res[x] = solve(int(digits.size()) - 1, 0, 0, 0);

	return res[x];
}

int main(){
	ll n;
	ll numb = ll(2e18);
	// while(scanf("%lld", &numb))
		// printf("%lld\n", get(numb));


	while(scanf("%lld", &n) != EOF){
		ll lo = n;
		ll hi = numb;
		ll res = -1LL;
		
		while(lo <= hi){
			ll mid = (lo + hi) >> 1LL;
			ll r = get(mid);
			// printf("%lld %lld\n", mid, r);

			if(mid - r >= n){
				res = mid;
				hi = mid - max(((mid - r) - n), 1LL);
			}else{
				lo = mid + max((n - (mid - r)), 1LL);
			}
		}

		printf("%lld\n", res);
	}

	return 0;
}