#include <bits/stdc++.h>

#define	MAXIMO	1010

using namespace std;

vector<int>graph[MAXIMO];
int cor[MAXIMO];

void dfs(int x){
	cor[x] = 1;

	for(int i = 0 ; i < graph[x].size() ; i++){
		if(!cor[graph[x][i]]){
			dfs(graph[x][i]);
		}
	}
}

int main (){
	int n, m;

	scanf("%d%d", &n, &m);

	for(int i = 0 ; i < m ; i++){
		int a, b;

		scanf("%d%d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int times = 0;

	for(int i = 1 ; i <= n ;i ++){
		if(!cor[i]){
			times++;
	
			dfs(i);
		}
	}

	printf("%d\n", times);

	return 0;
}
