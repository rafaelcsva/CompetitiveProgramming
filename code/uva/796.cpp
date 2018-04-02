#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 10000;
vector<int>graph[N];
int dfs_num[N], dfs_low[N];
set<pii>st;
int cnt;

void dfs(int x, int f){
	dfs_num[x] = dfs_low[x] = cnt++;
	
	for(int i = 0 ; i < graph[x].size() ; i++){
		int v = graph[x][i];
		
		if(dfs_num[v] == -1){
			dfs(v, x);
			
			if(dfs_low[v] > dfs_num[x]){
				if(x > v){
					st.insert(make_pair(v, x));
				}else{
					st.insert(make_pair(x, v));
				}
			}
			
			dfs_low[x] = min(dfs_low[v], dfs_low[x]);
			
		}else if(v != f){
			dfs_low[x] = min(dfs_num[v], dfs_low[x]);
		}
	}
}

int main (){
	int n;
	bool pr = false;
	
	while(scanf("%d", &n) != EOF){
		memset(dfs_num, -1, sizeof dfs_num);
		memset(dfs_low, -1, sizeof dfs_low);
		cnt = 0;
		
		
		pr = true;
		
		for(int i = 0 ; i < n ; i++){
			int v, t;
			
			scanf("%d (%d)", &v, &t);
			
			for(int k = 0 ; k < t ; k++){
				int u;
				
				scanf("%d", &u);
				
				graph[v].push_back(u);
				graph[u].push_back(v);
			}	
		}
		
		for(int i = 0 ; i < n ; i++){
			if(dfs_num[i] == -1){
				dfs(i, i);
			}
		}
		
		printf("%lu critical links\n", st.size());
		
		for(set<pii>::iterator it = st.begin() ; it != st.end() ; it++){
			printf("%d - %d\n", it->first, it->second);
		}
		
		printf("\n");
		
		for(int i = 0 ; i < n ; i++){
			graph[i].clear();
		}
		
		st.clear();
	}

	return 0;
}
