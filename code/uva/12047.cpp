#include <bits/stdc++.h>

using namespace std;

int n, m, s, t, p;

typedef long long int	lli;
const lli INF = (lli) 1e9;
const int N = 10010;
lli dis[2][N];
typedef pair<int, lli>	pii;
priority_queue<pii>pq;
vector<pii>adj[2][N];

void dijkstra(int s, int l){
	dis[l][s] = 0LL;
	
	pq.push(make_pair(dis[l][s], s));
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		
		for(int i = 0 ; i < adj[l][u].size() ; i++){
			int v = adj[l][u][i].first;
			lli w = adj[l][u][i].second;
			
			if(dis[l][v] > dis[l][u] + w){
				dis[l][v] = dis[l][u] + w;
				
				pq.push(make_pair(-dis[l][v], v));
			}
			
		}
	}
	
}

int main (){
	int T;
	
	scanf("%d", &T);
	
	while(T--){		
		scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
		
		for(int i = 0 ; i < m ; i++){
			int u, v;
			lli w;
			
			scanf("%d%d%lld", &u, &v, &w);
			
			adj[0][u].push_back(make_pair(v, w));
			adj[1][v].push_back(make_pair(u, w));
		}
				
		for(int i = 0 ; i < 2 ; i++){
			for(int j = 0 ; j <= n ; j++){
				dis[i][j] = INF;
			}
		}
		
		dijkstra(s, 0), dijkstra(t, 1);
		
		lli best = -1LL;
		
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j < adj[0][i].size() ; j++){
				int v = adj[0][i][j].first;
				lli w = adj[0][i][j].second;
				
				lli d = dis[0][i] + dis[1][v] + w;
					
				if(d <= p){
					best = max(best, w);
				}		
				
				//if(adj[i][j].second == 37){
					//printf("%d comes from source(%lld), %d comes from sink(%lld)\n", i, dis[0][i], adj[i][j].first, dis[1][adj[i][j].first]);
				//}
			}
		}
		
		printf("%lli\n", best);
		
		for(int i = 0 ; i <= n ; i++){
			adj[0][i].clear();
			adj[1][i].clear();
		}
	}
	
	return 0;
}
