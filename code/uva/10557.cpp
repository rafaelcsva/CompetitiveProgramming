#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
const int N = 100000;
vector<int>adj[N];
vector<pii>edges;
int n;
int dis[N];
int p[N];
const int INF = (int) -1e9, G = (int) 1e5;
bool marked[N], cor[N];

void mark(int v){
	marked[v] = true;
	dis[v] = G;
	
	for(int i = 0 ; i < adj[v].size() ; i++){
		int u = adj[v][i];
		
		if(!marked[u]){
			mark(u);
		}
	}
}

bool bellmanford(){
	dis[1] = 100;
	memset(marked, 0, sizeof marked);
	
	for(int i = 2 ; i <= n ; i++){
		dis[i] = INF;
	}
	
	for(int i = 0 ; i < n - 1 ; i++){
		for(int j = 0 ; j < edges.size() ; j++){
			int u = edges[j].first, v = edges[j].second;
			
			if(dis[u] + p[v] <= 0)
				continue;
				
			dis[v] = max(dis[v], dis[u] + p[v]);
		}
	}
	
	for(int i = 0 ; i < edges.size() ; i++){
		int u = edges[i].first, v = edges[i].second;
		
		if(dis[u] + p[v] <= 0)
			continue;
		
		if(dis[v] < dis[u] + p[v] && !marked[v]){
		//	printf("%d %d %d %d %d %d\n", dis[v], dis[u], p[v], v, u, v);
			mark(v);
		}
	}
	//printf("%d\n", dis[n]);
	return dis[n] > 0;
}

bool isConnected(int x){
	cor[x] = 1;
	
	if(x == n)
		return true;
		
	bool find = false;
	
	for(int i = 0 ; i < adj[x].size() ; i++){
		if(cor[adj[x][i]] == 0)
			find |= isConnected(adj[x][i]);
	}
	
	return find;
}

int main (){
	
	while(true){
		scanf("%d", &n);
		memset(cor, 0, sizeof cor);
		
		if(n == -1)
			break;
			
		for(int i = 1 ; i <= n ; i++){
			scanf("%d", &p[i]);
			
			int k;
			
			scanf("%d", &k);
			
			for(int j = 0 ; j < k ; j++){
				int v;
				
				scanf("%d", &v);
				
			//	adj[v].push_back(i);
				adj[i].push_back(v);
				
				edges.push_back(make_pair(i, v));
			//	edges.push_back(make_pair(v, i));
			}
		}
		
		int r = -1;
		
		if(isConnected(1)){
			r = bellmanford() ? 1 : -1;
		}
		
		printf("%s\n", r < 0 ? "hopeless" : "winnable");
	//	printf("%d\n", r);
		for(int i = 1 ; i <= n ; i++)
			adj[i].clear();
			
		edges.clear();
	}
	
	return 0;
}
