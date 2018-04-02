#include <bits/stdc++.h>

using namespace std;

const int N = 60, S = 6000;
int dis[N][N], save[N];
int dp[N][S];
int used[N][S], test;
int ind[N], ip[N], p;
const int inf = (int) 1e9;
int best = 0;

int solve(int x, int s){
	int &ans = dp[x][s];
	
	if(used[x][s] == test){
		return ans;
	}
	
	used[x][s] = test;
	
	ans = -dis[x][0];
	
	if(x == 0){
		ans = 0;
	}

	for(int i = 0 ; i < p ; i++){
		int chk = 1 << i;
		
		if((s & chk) == 0){
			int d = solve(ind[i], s | chk) + save[ind[i]] - dis[x][ind[i]];
			ans = max(ans, d);
		}
	}
	
	return ans;
}

int main (){
	int t;
	
	scanf("%d", &t);
	
	while(t--){
		test++;
		
		int n, m;
		
		scanf("%d%d", &n, &m);
		
		for(int i = 0 ; i <= n ; i++){
			save[i] = 0;
			for(int j = 0 ; j <= n ; j++){
				if(i != j)
					dis[i][j] = inf;
				else{
					dis[i][j] = 0;
				}
			}
		}
		
		while(m--){
			int u, v, d, f;
			
			scanf("%d%d%d.%d", &u, &v, &d, &f);

			dis[u][v] = dis[v][u] = min(d * 100 + f, dis[u][v]);
		}
		
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= n ; j++){
				for(int k = 0 ; k <= n ; k++){
					dis[i][k] = min(dis[i][k], dis[i][j] + dis[j][k]);
				}
			}
		}

		scanf("%d", &p);
		
		for(int i = 0 ; i < p ; i++){
			int d, f;
			
			scanf("%d%d.%d", &ip[i], &d, &f);
			
			while(save[ip[i]]){
				
			}
			
			save[ip[i]] += d * 100 + f;
		}
		
		int tmpp = 0;
		
		for(int i = 0 ; i <= n ; i++){
			if(save[i]){
				ind[tmpp++] = i;
			}
		}
		
		p = tmpp;
		
		int sav = solve(0, 0);
		
		if(sav == 0){
			printf("Don't leave the house\n");
		}else{
			printf("Daniel can save $%d.%02d\n", sav / 100, sav % 100);
		}
	}
	
	return 0;
}
