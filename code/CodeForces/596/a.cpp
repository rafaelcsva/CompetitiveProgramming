#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, p;

	cin >> n >> p;

	ll step = 1;
	ll cur = n - p;

	while(cur > 0LL){
		if(cur < step){
			break;
		}

		ll b = __builtin_popcount(cur);
		// cout << "b = " << b << endl;

		if(b <= step){
			cout << step << '\n';
			return 0;
		}

		cur -= p;
		step++;
	}

	cout << -1 << '\n';

	return 0;
}