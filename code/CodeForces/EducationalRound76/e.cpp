#include <bits/stdc++.h>

using namespace std;

vector< int > a[3];
const int N = int(2e5 + 10);
int dp[N][3];
const int inf = 1e9;
int n;

int solve(int i, int k){
	int &ans = dp[i][k];

	if(i == n + 1){
		return 0;
	}

	if(k >= 3){
		return inf;
	}

	if(ans != -1){
		return ans;
	}

	ans = solve(i, k + 1);

	int l = lower_bound(a[k].begin(), a[k].end(), i) - a[k].begin();

	if(l == a[k].size() || a[k][l] != i){
		ans = min(ans, 1 + solve(i + 1, k));
	}else{
		ans = min(ans, solve(i + 1, k));
	}

	return ans;
}

int main(){
	memset(dp, -1, sizeof dp);

	int k[3];

	scanf("%d %d %d", &k[0], &k[1], &k[2]);

	for(int i = 0 ; i < 3 ; i++){
		n += k[i];

		for(int j = 0 ; j < k[i] ; j++){
			int ai;

			scanf("%d", &ai);

			a[i].push_back(ai);
		}

		sort(a[i].begin(), a[i].end());
	}

	printf("%d\n", solve(1, 0));

	return 0;
}