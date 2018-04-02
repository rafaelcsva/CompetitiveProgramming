#include <bits/stdc++.h>

using namespace std;

const int N = 10100;
vector<int>adj[N];
int add[N], dis[N];
int l, u, r;
const int mod = 10000;

void build(int x){
	if(adj[x].size()){
		return;
	}
	
	for(int i = 0 ; i < r ; i++){
		int tmp = x + add[i];
		
		tmp %= mod;
		//cout << tmp << '\n';
		adj[x].push_back(tmp);
		build(tmp);
	}
	
}

int bfs(int x, int k){
	memset(dis, -1, sizeof dis);
	
	queue<int>q;
	
	q.push(x);
	dis[x] = 0;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i = 0 ; i < adj[u].size() ; i++){
			int v = adj[u][i];
			
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	
	return dis[k];
}

int main (){
	int test = 1;
	
	while(scanf("%d%d%d", &l, &u, &r) != EOF){
		if(l == 0 && u == 0 && r == 0){
			break;
		}
		
		for(int i = 0 ; i < r ; i++){
			scanf("%d", &add[i]);
		}
		
		build(l);
		
		int ans = bfs(l, u);

		printf("Case %d: ", test++);
		
		if(ans == -1){
			printf("Permanently Locked\n");
		}else{
			printf("%d\n", ans);
		}
		
		for(int i = 0 ; i < mod ; i++){
			adj[i].clear();
		}
	}

	return 0;
}
