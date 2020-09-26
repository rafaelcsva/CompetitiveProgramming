#include <bits/stdc++.h>

using namespace std;

int n;
const int inf = 1e9;
const int N = 1001, K = 11, E = 51;
int dp[N][K][E][4];
int used[N][K][E][4];
int test = 1;
int a[N];
int power[4] = {0, 4, 8, 11};

int solve(int i, int k, int e, int last){
	// printf("%d %d %d %d %d\n", i, k, e, last, n);
	
	if(i == n){
		return 0;	
	}

	int &ans = dp[i][k][e][last];
	int &us = used[i][k][e][last];

	if(us == test){
		return ans;
	}
	
	us = test;
	ans = inf;

	if(k == 0){
		if(e >= last){
			ans = solve(i + 1, 0, e - last, last) + max(a[i] - power[last], 0);
		}

		ans = min(ans, solve(i + 1, 0, e, 0) + a[i]);
	}else{
		for(int x = 0 ; x <= min(e, 3) ; x++){
			ans = min(ans, solve(i + 1, k - (x != last), e - x, x) + max(a[i] - power[x], 0));
		}
	}

	return ans;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int k, e;

		scanf("%d %d %d", &n, &k, &e);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}

		printf("Case #%d: %d\n", test++, solve(0, k, e, 0));
	}

	return 0;
}