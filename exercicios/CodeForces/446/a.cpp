#include <bits/stdc++.h>

#define ll long long 
using namespace std;

int main (){
	ll n;
	ll m1 = -1, m2 = -1;
	ll s = 0;
	ll v[100100];

	cin >> n;

	for(ll i = 0 ; i < n ; i++){
		ll a;

		cin >> a;

		s += a;
	}

	for(ll i = 0 ; i < n ; i++){
		cin >> v[i];
	}

	sort(v, v + n);

	if(v[n-1] + v[n-2] >= s){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}

	return 0;
}
