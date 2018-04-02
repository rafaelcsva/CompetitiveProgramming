#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int INF = (int) 1e9;
typedef pair<int, int>pii;
priority_queue<pii>pq;
vector<pii>adj[N];
int n, dis[N];

int dijkstra(int e, int t){
	for(int i = 1 ; i <= n ; i++){
		dis[i] = INF;
	}
	
	pq.push(make_pair(0, e));
	dis[e] = 0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		
		for(int i = 0 ; i < adj[u].size() ; i++){
			pii v = adj[u][i];
			
			if(dis[v.first] > dis[u] + v.second){
				dis[v.first] = dis[u] + v.second;
				pq.push(make_pair(-dis[u], v.first));
			}
		}
	}
	
	int cnt = 0;
	
	for(int i = 1 ; i <= n  ; i++){
		if(dis[i] <= t){
			cnt++;
		}
	}	
	
	return cnt;
}

int main (){	
	int k;
	
	scanf("%d", &k);
	
	while(k--){
		int e, t, m;
		
		scanf("%d%d%d%d", &n, &e, &t, &m);
		
		while(m--){
			int u, v, w;
			
			scanf("%d%d%d", &u, &v, &w);
			
			adj[v].push_back(make_pair(u, w));
		}	
		
		printf("%d\n", dijkstra(e, t));
		
		for(int i = 1 ; i <= n ; i++){
			adj[i].clear();
		}
		
		if(k)
			printf("\n");
	}
	
	return 0;
}
