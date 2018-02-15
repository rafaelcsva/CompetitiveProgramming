#include <bits/stdc++.h>

using namespace std;

typedef long long int	ll;

const ll inf = (ll) 1e18;
const int N = 510;
int  tab[N][N];
int n, m;
ll cost[N];

map<pair<int, set<int> >, ll>dp, us;

ll solve(int pos, set<int> st = set<int>()){
	pair<int, set<int> > ii;
	
	if(pos == m){
		if(st.size() == n){
			//cout << "returned 0\n";
			return 0LL;
		}else{
			//cout << "return inf\n";
			return inf;
		}
	}
	
	ii = make_pair(pos, st);

	if(us[ii] != 0LL){
		return dp[ii];
	}
	
	us[ii] = 1LL;
	
	dp[ii] = solve(pos + 1, st);

	for(int i = 0 ; i < n ; i++){
		if(tab[pos][i]){
			//cout << pos << ' ' << i << '\n';
			st.insert(i);
		}
	}

	dp[ii] = min(dp[ii], solve(pos + 1, st) + cost[pos]);

	return dp[ii];
}

/*void printDp(int pos, set<int> st = set<int>()){
	if(pos == m){
		return;
	}
	
	ii = make_pair(pos, st);
	
	iii = make_pair(pos + 1, st);
	
	if(dp[ii] == dp[iii]){
		cout << "Dont take " << pos << '\n';
		printDp(pos + 1, st);
		
		return;
	}
	
	
	cout << "Take " << pos << '\n';
	
	for(int i = 0 ; i < n ; i++){
		
		if(tab[pos][i]){
			cout << "+ " << i << '\n';
			st.insert(i);
		}
	}
	if(dp[ii] == dp[make_pair(pos + 1, st)]){
		
	cout << "cost = " << dp[ii] << '\n';
	printDp(pos + 1, st);
	}
	
}*/

int main (){
	scanf("%d %d", &n, &m);
	
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			scanf("%d", &tab[i][j]);
		}
		
		scanf("%lld", &cost[i]);
	}

	printf("%lld\n", solve(0));

	//printDp(0);
		
	return 0;
}
