#include <bits/stdc++.h>

using namespace std;

string sa, sb;

const int N = 5010;
int used[N][N][2];
int dp[N][N][2];
int n, m, t;

int solve(int pa, int pb, int last){	
	int &ans = dp[pa][pb][last];
	
	if(used[pa][pb][last] == t){
		return ans;
	}

	used[pa][pb][last] = t;

	ans = -1;

	char c;
	
	if(last == 0){
		c = sa[pa - 1];
	}else{
		c = sb[pb - 1];
	}

	int ca, cb;

	if(pa < n){
		if(sa[pa] != c){
			ca = 1;
		}else{
			ca = 0;
		}
	
		ans = ca + solve(pa + 1, pb, 0);
	}
	
	if(pb < m){
		if(sb[pb] != c){
			cb = 1;
		}else{
			cb = 0;
		}

		if(ans != -1){
			ans = min(cb + solve(pa, pb + 1, 1), ans);
		}
		else{
			ans = cb + solve(pa, pb + 1, 1);
		}
	}

	ans = max(ans, 0);
	return ans;
}

int main (){
	int T;

	ios::sync_with_stdio(false);

	cin >> T;

	for(t = 1 ; t <= T ; t++){
	
		cin >> n >> m;
	
		cin >> sa >> sb;

		cout << 1 + min(solve(1, 0, 0), solve(0, 1, 1)) << '\n';		
	}

	return 0;
}
