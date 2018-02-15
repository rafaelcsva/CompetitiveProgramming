#include <bits/stdc++.h>

using namespace std;

typedef long long int	ll;

int main (){
	ll n, k;
	
	ios::sync_with_stdio(false);
	
	cin >> n >> k;	

	ll q = n / k;
	
	cout << ((q * (q - 1)) * k) / 2 + q * (n % k) << '\n';
	
	return 0;
}
