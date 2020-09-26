#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int inf = int(1e9);

int a[N];
int dp[N][(1 << 16) + 1];
int used[N][(1 << 16) + 1];
int test = 1;
int msk;
int m, n;

int solve(int i, int mt){
	if(mt == msk){
		return 0;
	}

	if(i == m){
		return inf;
	}

	int &ans = dp[i][mt];
	int &us = used[i][mt];

	if(us == test){
		return ans;
	}

	us = test;
	ans = inf;

	if((a[i] & msk) == a[i])
		ans = 1 + solve(i + 1, mt | a[i]);

	ans = min(solve(i + 1, mt), ans);

	return ans;
}

int main(){
	while(scanf("%d %d", &m, &n) != EOF){
		for(int i = 0 ; i < m ; i++){
			int ki;

			a[i] = 0;

			scanf("%d", &ki);

			for(int j = 0 ; j < ki ; j++){
				int xi;

				scanf("%d", &xi);

				xi--;

				a[i] |= (1 << xi);
			}
		}

		for(int i = 0 ; i < n ; i++){
			int di;

			scanf("%d", &di);

			msk = 0;

			for(int j = 0 ; j < di ; j++){
				int xi;

				scanf("%d", &xi);

				xi--;

				msk |= (1 << xi);
			}

			int r = solve(0, 0);
			r = (r == inf) ? 0 : r;

			printf("%d%c", r, (i == n - 1) ? '\n' : ' ');
			test++;
		}
	}

	return 0;
}