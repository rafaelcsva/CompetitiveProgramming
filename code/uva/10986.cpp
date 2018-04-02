#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
const int N = 20010, INF = (int) 1e9;
int n, m, s, t;
vector<pii>adj[N];
priority_queue<pii>pq;
int dis[N];

int dijkstra(int s, int t){
	for(int i = 0 ; i < n ; i++){
		dis[i] = INF;
	}
	
	dis[s] = 0;
	
	pq.push(make_pair(0, s));
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		
		for(int i = 0 ; i < adj[u].size() ; i++){
			pii v = adj[u][i];
			
			if(dis[v.first] > dis[u] + v.second){
				dis[v.first] = dis[u] + v.second;
				pq.push(make_pair(-dis[v.first], v.first));
			}
		}
	}
	
	return dis[t];
}

int main (){
	int k;
	int test = 1;
	
	scanf("%d", &k);
	
	while(k--){
		scanf("%d%d%d%d", &n, &m, &s, &t);
		
		while(m--){
			int u, v, w;
			
			scanf("%d%d%d", &u, &v, &w);
			
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
		
		int ans = dijkstra(s, t);
		
		printf("Case #%d: ", test++);
		
		ans == INF ? printf("unreachable\n") : printf("%d\n", ans);
		
		for(int i = 0 ; i < n ; i++){
			adj[i].clear();
		}
	}

	return 0;
}
