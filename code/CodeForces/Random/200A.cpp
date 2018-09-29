#include <bits/stdc++.h>
using namespace std;

typedef long long	ll;

int main() {
	ll a, b;
	
	cin >> a >> b;
	
	ll q = a / b;
	
	ll sum = q;
	a -= b * q;
	
	if(a)
		sum += 1LL + a / (b - a);
	
	cout << sum << endl;
	
	return 0;
}