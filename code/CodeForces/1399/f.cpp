#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
pair< int, int > seg[N];

bool compar(pair< int, int > a, pair< int, int > b){
	if(a.first < b.first){
		return true;
	}else if(a.first > b.first){
		return false;
	}else{
		return a.second > b.second;
	}
}

int dp[N][N];
int used[N][N];
int test = 1;
int n;

bool inside(int i, int j){
	return seg[i].first <= seg[j].first && seg[j].second <= seg[i].second;
}

int solve(int i, int l){
	if(i == n + 1){
		return 0;
	}

	int &us = used[i][l];
	int &ans = dp[i][l];

	if(us == test){
		return ans;
	}

	us = test;
	ans = 0;

	int u = lower_bound(seg + 1, seg + n + 1, make_pair(seg[i].second + 1	, -1)) - seg;

	if(l == 0){
		ans = max(1 + solve(i + 1, i) + solve(u, 0), solve(i + 1, 0));
	}else{	
		if(inside(l, i)){
			ans = solve(i + 1, i) + 1 + solve(u, l);
		}

		ans = max(ans, solve(i + 1, l));
	}

	return ans;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		for(int i = 1 ; i <= n  ;i++){
			scanf("%d %d", &seg[i].first, &seg[i].second);
		}

		sort(seg + 1, seg + 1 + n, compar);

		printf("%d\n", solve(1, 0));

		test++;
	}

	return 0;
}