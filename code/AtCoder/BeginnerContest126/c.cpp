#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

double solve(ll t, ll k){
	double prob = 1.0;

	while(t < k){
		prob *= 0.5;
		t *= 2LL;
	}

	return prob;
}

int main(){
	ll n, k;

	cin >> n >> k;

	double prob = 0.0;

	for(ll t = 1LL ; t <= n ; t++){
		prob += (1.0 / n) * solve(t, k);
	}

//	prob *= (1.0 / n);

	cout << setprecision(13) << fixed << prob << endl;

	return 0;
}