#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main (){
	ll a, b, c, x, y;
	
	cin >> a >> b >> c >> x >> y;
	
	ll ma = max(x, y) * 2LL;
	ll mn = ll(1e9);
	
	for(ll i = 0LL ; i <= ma ; i++){
		ll cur = i * c + max(0LL, (x - i / 2LL) * a) + max(0LL, (y - i / 2LL) * b); 
		
		mn = min(mn, cur);
	}
	
	cout << mn << endl;
	
	return 0;
}
