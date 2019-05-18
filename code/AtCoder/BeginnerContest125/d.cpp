#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	ll sum = 0LL;
	ll mn = ll(1e18);
	int cnt = 0;

	for(int i = 1 ; i <= n ; i++){
		ll ai;

		cin >> ai;

		mn = min(mn, abs(ai));

		sum += abs(ai);

		if(ai < 0LL){
			cnt++;
		}
	}

	if(cnt & 1){
		sum -= 2LL * mn;
	}

	cout << sum << endl;

	return 0;
}