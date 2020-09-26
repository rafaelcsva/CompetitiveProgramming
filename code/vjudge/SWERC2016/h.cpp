#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long	ll;

set< ll > st;
vector< int > tmp;
vector< vector< int > > vals, end_vert;
map< vector< int >, ll > dp;

void solve(int dim, int val, int last){
	if(dim < 0){
		vals.push_back(tmp);

		if(val == 0){
			end_vert.push_back(tmp);
		}
		return;
	}

	for(int i = last ; i <= val ; i++){
		tmp.push_back(i);

		solve(dim - 1, val - i, i);

		tmp.pop_back();
	}
}

ll solve_dp(vector< int > &vert){
	if(dp.count(vert) != 0){
		// printf("retornei aqui!\n");
		// fflush(stdout);

		return dp[vert];
	}

	ll sum = 0LL;
	// printf("cheguei aqui!n\n");

	for(int i = 0 ; i < vert.size() ; i++){
		vector< int > tmp = vert;
		if(tmp[i]){
			tmp[i]--;
			
			sort(tmp.begin(), tmp.end());
			sum += solve_dp(tmp);
		}
	}

	sum = max(sum, 1ULL);

	dp[vert] = sum;

	return sum;
}

int main(){
	int d, h;

	scanf("%d %d", &d, &h);

	solve(d - 1, h - 1, 0);
	// printf("sai aui!\n");

	// fflush(stdout);
	// return 0;

	for(auto u: end_vert){
		st.insert(solve_dp(u));
		// printf("sai aqui!\n");
		// fflush(stdout);
	}

	for(auto u: st){
		printf("%llu\n", u);
	}

	return 0;
}