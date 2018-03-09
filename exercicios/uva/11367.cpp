#include <bits/stdc++.h>

using namespace std;

const int N = 1010, INF = (int) 1e9;
typedef pair<int, int>	pii;
typedef pair<int, pii> pipii;
priority_queue<pipii>pq;
vector<pii>adj[N];
int dis[N][N];
int n, m;
int p[N];

int dijkstra(int s, int e, int c){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j <= c ; j++){
			dis[i][j] = INF;
		}
	}
	
	dis[s][0] = 0;
	
	pq.push(make_pair(0 , make_pair(0, s)));
	
	while(!pq.empty()){
		int u = pq.top().second.second;
		int cur = pq.top().second.first;
		//cout << u << ' ' << cur << '\n';
		pq.pop();
		
		for(int k = 0 ; k < adj[u].size() ; k++){
			int v = adj[u][k].first;
			int x = adj[u][k].second;
			
			if(cur >= x){
			
				if(dis[v][cur - x] > dis[u][cur]){
					dis[v][cur - x] = dis[u][cur];
					pq.push(make_pair(-dis[v][cur - x], make_pair(cur - x, v)));
				}
				
			}
		}
		
		if(cur + 1 <= c){
			if(dis[u][cur + 1] > dis[u][cur] + p[u]){
				dis[u][cur + 1] = dis[u][cur] + p[u];
				pq.push(make_pair(-dis[u][cur + 1], make_pair(cur + 1, u)));
			}
		}
	}
		
	return dis[e][0];
}

int main (){
	scanf("%d%d", &n, &m);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &p[i]);
	}
	
	for(int i = 0 ; i < m ; i++){
		int u, v, w;
		
		scanf("%d%d%d", &u, &v, &w);
		
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	
	int q;
	
	scanf("%d", &q);
	
	while(q--){
		int c, s, e;
		scanf("%d%d%d", &c, &s, &e);
		
		int d = dijkstra(s, e, c);
		
		if(d == INF){
			printf("impossible\n");
		}else{
			printf("%d\n", d);
		}
	}
	
	return 0;
}
