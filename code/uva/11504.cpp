#include <bits/stdc++.h>

using namespace std;

const int N = 100100;
int cor1[N], cor2[N], comp[N];
vector<int>graph[N], orderedNode, inv[N];
bool in[N];

void dfs1(int x){
	cor1[x] = 1;
	
	for(int i = 0 ; i < graph[x].size() ; i++){
		int v = graph[x][i];
		
		if(cor1[v] == 0){
			dfs1(v);
		}
	}
	
	orderedNode.push_back(x);
}

void dfs2(int x, int c){
	cor2[x] = 1;
	comp[x] = c;
	
	for(int i = 0 ; i < inv[x].size() ; i++){
		int v = inv[x][i];
		//cout << v << "->" << x << '\n';
		if(cor2[v] == 0){
			dfs2(v, c);
		}else if(comp[v] != comp[x]){
		//	cout << comp[v] << " have in edges " << x << "\n";
			in[c] = true;
		}
	}
}

int main (){
	int t;
	
	scanf("%d", &t);
	
	while(t--){
		int n, m;
		
		memset(cor1, 0, sizeof cor1);
		memset(cor2, 0, sizeof cor2);
		memset(in, 0, sizeof in);
		memset(comp, 0, sizeof comp);
		
		scanf("%d%d", &n, &m);
		
		while(m--){
			int u, v;
			
			scanf("%d%d", &u, &v);
			
			graph[u].push_back(v);
			inv[v].push_back(u);
		}
		
		for(int i = 1 ; i <= n ; i++){
			if(cor1[i] == 0){
				dfs1(i);
			}
		}
		
		int sccs = 0;
		
		for(int i = n ; i >= 1 ; i--){
			int u = orderedNode[i - 1];
			
			if(cor2[u] == 0){
				dfs2(u, ++sccs);
			}
		}
		
		int tot = 0;
		
		for(int i = 1 ; i <= sccs ; i++){
			tot += !in[i];
		
		}
		
		for(int i = 1 ; i <= n ; i++){
			graph[i].clear();
			inv[i].clear();
		}
		
		orderedNode.clear();
		
		cout << tot << '\n';
	}

	return 0;
}
