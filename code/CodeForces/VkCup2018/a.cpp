#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main (){
	ll l, r;
	
	ios::sync_with_stdio(false);
	
	cin >> l >> r;	
	ll cnt = 0LL;
	
	for(ll x = 1LL ; x <= r ; x *= 2LL){
		for(ll y = 1LL ; x * y <= r ; y *= 3LL){
			if(x * y >= l){
				cnt++;
			}
		}
	}
	
	cout << cnt << '\n';

	return 0;
}
