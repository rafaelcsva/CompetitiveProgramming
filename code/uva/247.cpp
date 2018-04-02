#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
map<string, int>mp;
map<int, string>pm;
int id, test, cor1[N], cor2[N];
vector<int>graph[N], ord;
int comp, cmp[N];
int dfs_low[N], dfs_num[N], visited[N];
int cnt;

void dfs(int u){
	dfs_low[u] = dfs_num[u] = cnt++;
	ord.push_back(u);
	
	visited[u] = 1;
	
	for(int i = 0 ; i < graph[u].size() ; i++){
		int v = graph[u][i];
		
		if(dfs_low[v] == -1){
			dfs(v);
		}
		
		if(visited[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		
	}
	
	if(dfs_low[u] == dfs_num[u]){
		comp++;
		
		while(true){
			int v = ord.back();
			
			ord.pop_back();
			visited[v] = 0;
			
			cmp[v] = comp;
			 
			if(v == u){
				break;
			}
		}
	}
}

void print(int n){
	for(int i = comp ; i >= 1 ; i--){
		bool space = false;
		
		for(int j = 1 ; j <= n ; j++){
			
			if(cmp[j] == i){
				if(space){
					cout << ", ";
				}
				
				cout << pm[j];
				space = true;
			}
				
		}
		if(space)
			cout << '\n';
	}
}

int main (){
	int n, m;
	int test = 1;
	
	while(cin >> n >> m){
		if(n == 0 && m == 0){
			break;
		}
		
		memset(dfs_num, -1, sizeof dfs_num);
		memset(dfs_low, -1, sizeof dfs_low);

		for(int i = 0 ; i < N ; i++){
			cmp[i] = 0;
			visited[i] = 0;
		}
		
		id = 1;
		
		for(int i = 0 ; i < m ; i++){
			string u, v;
			
			cin >> u >> v;
			//cout << u << ' ' << v << '\n';
			if(mp[u] == 0){
				mp[u] = id++;
				pm[id - 1] = u;
			}
			if(mp[v] == 0){
				mp[v] = id++;
				pm[id - 1] = v;
			}
		
			graph[mp[u]].push_back(mp[v]);
		}
		
		if(test >= 2){
			cout << '\n';
		}
		
		comp = 0;
		id--;
		n = id;
		
		cout << "Calling circles for data set " << test++ << ":\n";
		 
		for(int i = 1 ; i <= id ; i++){
			if(dfs_num[i] == -1){
				cnt = 0;
				dfs(i);	
			}	
		}
		
		print(id);
		
		
		
		for(int i = 0 ; i < N ; i++){
			graph[i].clear();
			cor1[i] = cor2[i] = 0;
		}
		
		ord.clear();
		mp.clear();
		pm.clear();
	}

}
