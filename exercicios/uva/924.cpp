#include <bits/stdc++.h>

using namespace std;

const int N = 2600;
typedef pair<int, int>	pii;
vector<int>adj[N];
int e, n;

pii bfs(int s){
	int dis[N];
	int cnt[N];
	
	memset(dis, -1, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	
	queue<int>q;
	
	q.push(s);
	
	dis[s] = 0;
	cnt[0]++;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i = 0 ; i < adj[u].size() ; i++){
			int v = adj[u][i];
			
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				cnt[dis[v]]++;
				q.push(v);
			}	
		}
	}
	
	int ans = 0, cat = 0;
	
	for(int i = 1 ; i < e ; i++){
		if(cat < cnt[i]){
			cat = cnt[i];
			ans = i;
		}
	}
	
	return make_pair(cat, ans);
}

int main (){
	scanf("%d", &e);
	
	for(int i = 0 ; i < e ; i++){
		scanf("%d", &n);
		
		for(int k = 0 ; k < n ; k++){
			int v;
			
			scanf("%d", &v);
			
			adj[i].push_back(v);
		}
	}
	
	int t;
	
	scanf("%d", &t);
	
	while(t--){
		int s;
		
		scanf("%d", &s);
		
		pii r = bfs(s);
		
		if(r.second == 0){
			printf("0\n");
		}else{
			printf("%d %d\n", r.first, r.second);
		}
	}
	
	return 0;
}
