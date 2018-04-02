#include <bits/stdc++.h>

#define lli	long long int
using namespace std;

map<lli, lli> dp;

lli solve(lli n){
	if(dp[n] != 0){
		return dp[n];
	}

	lli num = n;
	lli sum = n;
	bool ver = false;

	for(lli i = 2 ; i * i <= n ; i++){
		if(n % i == 0){
			ver = true;
			sum += solve(n / i);

			break;
		}
	}

	if(!ver && n != 1){
		sum ++;
	}

	return dp[n] = sum;
}

int main (){
	int n;
	lli ans = 0;

	cin >> n;

	for(int i = 0 ; i < n ; i++){
		lli a;

		cin >> a;

		ans += solve(a);		
	}

	cout << ans << '\n';

	return 0;
}
