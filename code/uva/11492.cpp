#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
const int N = 3000, INF = (int) 1e9;
string s, e;
string w[N];
vector<pii>adjw[N];
vector<int>adj[N];
priority_queue<pii>pq;
int dis[N];
int m;
map<string, int>mp;

int dijkstra(int s, int e){
	for(int i = 0 ; i <= m + 1 ; i++){
		dis[i] = INF;
	}
	
	dis[s] = 0;
	pq.push(make_pair(0, s));
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		
		for(int i = 0 ; i < adjw[u].size() ; i++){
			int v = adjw[u][i].second;
			int w = adjw[u][i].first;
			
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				pq.push(make_pair(-dis[v], v));
			}
		}
	}
	
	return dis[e];
}

int main (){
	
	while(true){
		cin >> m;
		
		if(m == 0)
			break;
			
		cin >> s >> e;
		
		mp[s] = 1, mp[e] = 2;
		
		int id = 2;
		
		for(int i = 0 ; i < m ; i++){
			string u, v;
			
			cin >> u >> v >> w[i];
			
			if(mp[u] == 0)
				mp[u] = ++id;
			if(mp[v] == 0)
				mp[v] = ++id;
				
			adj[mp[u]].push_back(i), adj[mp[v]].push_back(i);
		}
		
		for(int i = 1 ; i <= id ; i++){
			for(int k = 0 ; k < adj[i].size() ; k++){
				int u = adj[i][k];
				
				for(int l = k + 1 ; l < adj[i].size() ; l++){
					int v = adj[i][l];
					
					if(w[u][0] == w[v][0])
						continue;
						
					adjw[u].push_back(make_pair(w[v].length(), v)), adjw[v].push_back(make_pair(w[u].length(), u));
				}
			}
		}
		
		for(int i = 0 ; i < adj[mp[s]].size() ; i++){
			int v = adj[mp[s]][i];
			
			adjw[m].push_back(make_pair(w[v].length(), v));
			adjw[v].push_back(make_pair(0, m));
		}
		
		for(int i = 0 ; i < adj[mp[e]].size() ; i++){
			int v = adj[mp[e]][i];
			
			adjw[m + 1].push_back(make_pair(w[v].length(), m + 1));
			adjw[v].push_back(make_pair(0, m + 1));
		}
		
		int r = dijkstra(m, m + 1);
		
		if(r == INF){
			printf("impossivel\n");
		}else{
			printf("%d\n", r);
		}
		
		for(int i = 0 ; i <= m + 1 ; i++){
			adjw[i].clear();
		}
		
		for(int i = 1 ; i <= id ; i++){
			adj[i].clear();
		}
		
		mp.clear();
	}
	
	return 0;
}
