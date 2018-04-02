#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;

const int N = 110;
int dis[N][N];

int main (){
	int t;
	int test = 1;
	
	scanf("%d", &t);
	
	while(t--){
		int n;
		
		memset(dis, -1, sizeof dis);
		
		scanf("%d", &n);
		int r;
		
		scanf("%d", &r);
		
		for(int i = 0 ; i < r ; i++){
			int u, v;
			
			scanf("%d%d", &u, &v);
			
			dis[u][v] = dis[v][u] = 1;	
		}
		
		for(int i = 0 ; i < n ; i++){
			dis[i][i] = 0;
			
			for(int j = 0 ; j < n ; j++){
				for(int k = 0 ; k < n ; k++){
					
					if(dis[i][j] == -1 || dis[j][k] == -1){
						continue;
					}
					
					if(dis[i][k] == -1)
						dis[i][k] = dis[i][j] + dis[j][k];
						
					dis[i][k] = min(dis[i][k], dis[i][j] + dis[j][k]);
				}
			}
		}
		
		int s, e;
		
		scanf("%d%d", &s, &e);
		
		int best = -1;
		
		for(int i = 0 ; i < n ; i++){
			best = max(dis[s][i] + dis[i][e], best);
		}
		
		printf("Case %d: %d\n", test++, best);
	}
	
	return 0;
}
