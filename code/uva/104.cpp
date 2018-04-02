#include <bits/stdc++.h>

using namespace std;

typedef	pdi	pair<double, int>;
const int N = 30;
double dis[N][N], profit[N][N], tab[N][N], f[N][N];
priority_queue<pdi>pq;
int n;

void dijkstra(int x){
	pq.push(make_pair(0.00, x));
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		
		for(int i = 1 ; i <= n ; i++){
			if(i == u)
				continue;
				
			int c = dis[x][u] + 1;
			
			if(c <= n){
				if(
			}
		}
	}
}

int main (){
	
	while(scanf("%d", &n) != EOF){
		memset(dis, 0, sizeof dis);
		memset(profit, 0, sizeof profit);
		
		for(int i = 1 ; i <= n ; i++){
			profit[i][i] = 1.0;
			
			for(int j = 1 ; j <= n ; j++){
				if(j == i)	
					continue;
				
				p[i][j] = i;
				s[i][j] = 1;
						
				scanf("%lf", &tab[i][j]);
			}
		}
		
		
	}
	
	return 0;
}
