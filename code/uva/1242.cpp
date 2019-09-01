#include <bits/stdc++.h>

using namespace std;

const int N = int(1e4 + 10);
int father[N];
vector< int > adj[N];
int mat[N][N];
int s, t;
int n, m;

bool bfs(){
	memset(father, -1, sizeof(int) * (n + 1));
	queue< int > q;

	q.push(s);

	father[s] = s;

	while(!q.empty()){
		// printf("q: %d\n", q.front());
		int u = q.front();
		q.pop();

		for(int i = 0 ; i < adj[u].size() ; i++){
			int v = adj[u][i];

			if(father[v] == -1 && mat[u][v]){
				father[v] = u;
				q.push(v);
			}
		}
	}

	return father[t] != -1;
}

bool edmonds_karp(){
	int it = 0;

	while(bfs() && it < 2){
		int u = t;

		while(u != s){
			// printf("%d\n", u);
			mat[father[u]][u]--;
			mat[u][father[u]]++;
			u = father[u];
		}

		it++;
	}

	// printf("it = %d\n", it);

	return it >= 2;
}

int main(){
	int test = 1;

	while(scanf("%d %d", &n, &m) != EOF){
		if(n == 0 && m == 0){
			break;
		}
		for(int i = 0 ; i < m ; i++){
			int u, v;

			scanf("%d %d", &u, &v);

			adj[u].push_back(v);
			adj[v].push_back(u);
			mat[u][v]++;
			mat[v][u]++;
		}

		scanf("%d %d", &s, &t);

		printf("Case %d: ", test++);

		if(edmonds_karp()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		// printf("teste!\n");

		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j < adj[i].size() ; j++){
				mat[i][adj[i][j]] = 0;
			}

			adj[i].clear();
		}
	}

	return 0;
}