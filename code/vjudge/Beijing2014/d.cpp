#include <bits/stdc++.h>

using namespace std;

const int N = 210;
int dp[N][N];
int test = 1;
int used[N][N];
int n;
int a[N];
const int inf = int(1e9);

int get(int i){
	if(i >= n || i < 0){
		return 0;
	}

	return a[i];
}

int solve(int i, int j){
	if(i >= j){
		return 0;
	}

	int &us = used[i][j];
	int &ans = dp[i][j];

	if(us == test){
		return ans;
	}

	// printf("ak\n");

	us = test;
	ans = inf;
	int tmp1 = 0;

	for(int k = i ; k <= j ; k++){
		int add = 0;

		if(k != 0 && k != i){
			tmp1 += a[k - 1];
		}

		if(k != j){
			add += a[k + 1];
		}

		ans = min(ans, tmp1 + solve(k + 1, j) + ((k + 1 > j) ? 0 : a[k + 1]) * (k - i) + add);
	}

	int tmp2 = 0;

	for(int k = j ; k >= i ; k--){
		int add = 0;

		if(k != 0 && k != i){
			add += a[k - 1];
		}

		if(k != j){
			tmp2 += a[k + 1];
		}

		ans = min(ans, tmp2 + solve(i, k - 1) + ((k - 1 < i) ? 0 : a[k - 1]) * (j - k) + add);
	}

	// printf("%d-%d = %d %d %d\n", i, j, ans, tmp1, tmp2);

	return ans;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		int sum = 0;

		for(int i = 0 ; i < n ; i++){
			int ai;

			scanf("%d", &ai);

			sum += ai;
		}

		for(int i = 0 ; i < n ; i++) scanf("%d", &a[i]);

		printf("Case #%d: %d\n", test, sum + solve(0, n - 1));

		test++;
	}

	return 0;
}