#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;

const int N = int(1e6);
pii dp[N];

int revert(int number){
	for(int i = 20 ; i >= 0 ; i--){
		int e = 1 << i;

		if(number & e){
			number ^= e;
			number <<= 1;
			number |= 1;
			//printf("change on bit %d\n", i);
			return number;
		}
	}

	assert(false);
}

pii solve(int n){
	if(dp[n].first != -1){
		return dp[n];
	}

	int r = revert(n);

	if(n == r){
		return dp[n] = {0, n};
	}

	dp[n] = solve(r);
	dp[n].first++;

	return dp[n];
}

int main(){
	int t;
	int n;
	//printf("%d, %d\n", 3, revert(3));

	memset(dp, -1, sizeof dp);

	scanf("%d", &t);

	for(int test = 1 ; test <= t ; test++){
		scanf("%d", &n);

		printf("Case %d: %d %d\n", test, solve(n).first, solve(n).second);
	}

	return 0;
}