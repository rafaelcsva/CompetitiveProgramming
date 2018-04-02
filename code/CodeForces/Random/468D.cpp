#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
vector<int>adj[N];
queue<int>q;
int qtd[N];
int dis[N];

void bfs(){
	memset(dis, -1, sizeof dis);
	
	q.push(1);
	dis[1] = 0;
	qtd[0] = 1;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i = 0 ; i < adj[u].size() ; i++){
			int v = adj[u][i];
			
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				qtd[dis[v]]++;
				
				q.push(v);
			}
		}
	}
}

int main (){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 2 ; i <= n ; i++){
		int v;
		
		scanf("%d", &v);
		
		adj[v].push_back(i);
	}
	
	bfs();
	
	int sum = 0;
	
	for(int i = 0 ; i < n ; i++){
		//printf("%d\n", qtd[i]);
		sum += qtd[i] % 2;
	}	
	
	printf("%d\n", sum);
	
	
	return 0;
}
