#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;
typedef pair<int, int>	pii;
const int N = 210;
const lli INF = (lli) 1e9;
vector<pii>edges;
int n, r, q;
lli b[N];
lli dis[N];

void bellmanford(){
	for(int i = 1 ; i <= n ; i++)
		dis[i] = INF;
		
	dis[1] = 0LL;
	
	for(int i = 0 ; i < n - 1 ; i++){
		for(int k = 0 ; k < r ; k++){
			int u = edges[k].first, v = edges[k].second;
			
			if(dis[u] == INF)
				continue;
				
			dis[v] = min(dis[v], dis[u] + b[v] - b[u]);
		}
	}
	
	for(int k = 0 ; k < edges.size() ; k++){
		int v = edges[k].second, u = edges[k].first;
		
		if(dis[v] > dis[u] + b[v] - b[u])
			dis[v] = -1LL;
	}
	
}

int main (){
	int test = 1;
	
	while(cin >> n){
		for(int i = 1 ; i <= n ; i++){
			cin >> b[i];
		}
		
		cin >> r;
		
		for(int i = 0 ; i < r ; i++){
			int u, v;
			
			cin >> u >> v;
			
			edges.push_back(make_pair(u, v));
			//adj[v].push_back(u);
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
		
		edges.clear();
	}
	
	return 0;
}
