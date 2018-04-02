#include <bits/stdc++.h>

using namespace std;

const int N = 110;
vector<pair<int, char> > graph[N];
bool dp[N][N][2][300], used[N][N][2][300];

bool solve(int i, int j, int k, char last){
	bool &ans = dp[i][j][k][last];

	//cout << i << ' ' << j << '\n';
	
	if(used[i][j][k][last]){
		return ans;
	}
	
	used[i][j][k][last] = true;
	
	int x = k == 0 ? i : j;

	for(int d = 0; d < graph[x].size() ; d++){
		pair<int, char> ii = graph[x][d];

		if(ii.second >= last){
			if(k == 0){
				ans = ans || !(solve(ii.first, j, 1, ii.second));
			}else{
				ans = ans || !(solve(i, ii.first, 0, ii.second));
			}
		}
	}
	
	return ans;
}

int main (){
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	while(m--){
		int u, v;
		char m;
		
		scanf("%d %d", &u, &v);
		scanf("\n%c", &m);
		
		graph[u].push_back(make_pair(v, m));
	}
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(solve(i, j, 0, 0)){
				printf("A");
			}else{
				printf("B");
			}
		}
		
		printf("\n");
	}
	
	return 0;
}	
