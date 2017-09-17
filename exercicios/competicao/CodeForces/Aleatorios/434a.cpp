#include <bits/stdc++.h>

#define	ll	long long

using namespace std;

ll lcm(ll a, ll b){
	return (a*b)/__gcd(a,b);
}

int main (){
	ll n, k;

	cin>>n>>k;

	ll m = 1;

	for(int i = 0 ; i < k ; i++)
		m = m*10;

	cout<<lcm(n, m)<<'\n';

	return 0;
	
}
