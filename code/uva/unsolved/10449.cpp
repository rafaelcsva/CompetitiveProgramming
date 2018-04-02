#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;
typedef pair<int, int>	pii;
const int N = 210;
const lli INF = (lli) 1e9;
vector<pii>edges;
vector<int>adj[N];
int n, r, q;
lli b[N];
lli dis[N];
int cor[N];

void mark(int x){
	cor[x] = 1;
	dis[x] = -1LL;
	
	for(int i = 0 ; i < adj[x].size() ; i++){
		int v = adj[x][i];
		
		if(cor[v] == 0){
			mark(v);
		}
	}
}

void bellmanford(){
	for(int i = 1 ; i <= n ; i++)
		dis[i] = INF;
		
	dis[1] = 0LL;
	
	for(int i = 0 ; i < n - 1 ; i++){
		for(int k = 0 ; k < r ; k++){
			int u = edges[k].first, v = edges[k].second;
			
			if(dis[u] == INF)
				continue;
			
			lli cost = b[v] - b[u];
			
			dis[v] = min(dis[v], dis[u] + cost * cost * cost);
		}
	}
	
	for(int k = 0 ; k < edges.size() ; k++){
		int v = edges[k].second, u = edges[k].first;
		
		if(dis[u] == INF)
			continue;
			
		lli cost = b[v] - b[u];
		
		if(dis[v] > dis[u] + cost * cost * cost && cor[v] == 0){
			mark(v);	
		}
	}
	
}

int main (){
	int test = 1;
	
	while(cin >> n){
		memset(cor, 0, sizeof cor);
		
		for(int i = 1 ; i <= n ; i++){
			cin >> b[i];
		}
		
		cin >> r;
		
		for(int i = 0 ; i < r ; i++){
			int u, v;
			
			cin >> u >> v;
			
			edges.push_back(make_pair(u, v));
			adj[u].push_back(v);
		}
		
		cin >> q;
		
		cout << "Set #" << test++ << '\n';
		bellmanford();
		
		for(int i = 0 ; i < q ; i++){
			int v;
			
			cin >> v;
			
			if(dis[v] == INF || dis[v] < 3LL){
				cout << "?\n";
			}else{
				cout << dis[v] << '\n';
			}
		}
		
		for(int i = 1 ; i <= n ; i++){
			adj[i].clear();
		}
		
		edges.clear();
	}
	
	return 0;
}
