#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;
vector<int>graph[N];
int cor[N];
int c[N];
int nv[N];

void dfs(int x, int m){
	nv[x] = m;

	for(int i = 0 ; i < graph[x].size() ; i++){
		if(nv[graph[x][i]] == -1){
			dfs(graph[x][i], m + 1);
		}
	}
}

void dfs1(int x, int c){
	cor[x] = c;
	//printf("%d->", x);
	for(int i = 0 ; i < graph[x].size() ; i++){
		
		if(nv[graph[x][i]] > nv[x]){
			dfs1(graph[x][i], c);
		}
	}
}

int main (){
	int n;

	scanf("%d", &n);

	for(int i = 1; i <= n ; i++)
		nv[i] = -1;

	for(int i = 2 ; i <= n ; i++){
		int a;

		scanf("%d", &a);

		graph[i].push_back(a);
		graph[a].push_back(i);
	}

	dfs(1, 0);

	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &c[i]);
	}
	
	int ans = 0;

	for(int i = 1 ; i <= n ; i++){
		if(cor[i] != c[i]){
			ans++;
			dfs1(i, c[i]);
		}
	}
	
	printf("%d\n", ans);

}
