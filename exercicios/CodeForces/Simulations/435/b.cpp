#include <bits/stdc++.h>

using namespace std;

#define	MAXIMO	100100
#define ll	long long

int c[MAXIMO];
vector<int>graph[MAXIMO];

void dfs(int x, int cor){
	c[x] = cor;

	for(int i = 0 ; i < graph[x].size() ; i++){
		if(c[graph[x][i]] == 0){
			int r;
	
			r = cor == 1 ? 2 : 1;

			c[graph[x][i]] = r;
			dfs(graph[x][i], r);
		}
	}
}

int main (){
	int n;	

	cin>>n;

	for(int i = 0 ; i < n-1; i++){
		int a, b;

		cin>>a>>b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 1);
	ll qtd = 0;

	for(int i = 1 ; i <= n ; i++){
		if(c[i] == 1)
			qtd++;
	}

	cout<<(qtd)*(n-qtd)-(n-1)<<'\n';

	return 0;
}
