#include <bits/stdc++.h>

using namespace std;

int DEBUG = 1;
const int N = 40 * 40 * 2;
char tab[N][N];
int adj[N][N];
int n, m;
int vi[] = {0, 0, -1, 1}, vj[] = {1, -1, 0, 0};
int source, sink, INF = (int) 1e9;
int dis[N], p[N];

bool ok(int i, int j){
	return i < n && i >= 0 && j < m && j >= 0 && tab[i][j] != '~';
}

void AddEdge(int u, int v, int w){
	adj[u][v] = w;
}

void mark(int i, int j, int w){
	int u = i * m + j;
	u *= 2;

	AddEdge(u, u + 1, w);

	for(int t = 0 ; t < 4 ; t++){
		int ti = vi[t] + i, tj = vj[t] + j;

		if(ok(ti, tj)){
			int c = w;

			if(tab[ti][tj] == '@' || tab[ti][tj] == '#'){
				c = INF;
			}

			int v = ti * m + tj;
			v *= 2;
		
			AddEdge(u + 1, v, c);
		}
	}
}

bool bfs(){
	queue<int>q;
	memset(dis, -1, sizeof dis);

	q.push(source);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		// if(DEBUG){
		// 	printf("%d", u / 2);

		// 	if(u % 2){
		// 		printf("'");
		// 	}
		// 	printf(" ");
		// }

		for(int i = 0 ; i <= sink ; i++){
			if(adj[u][i] && dis[i] == -1){
				dis[i] = 1;
				p[i] = u;
				q.push(i);
			}
		}
	}

	// if(DEBUG){
	// 	printf(" ended candidate\n");
	// }

	return dis[sink] != -1;
}

int augment(){
	int ac = sink;
	int r = INF;

	while(ac != source){
		r = min(r, adj[p[ac]][ac]);
		ac = p[ac];
	}

	ac = sink;

	while(ac != source){
		adj[p[ac]][ac] -= r;
		adj[ac][p[ac]] += r;
		ac = p[ac];
	}

	return r;
}

int EdmondsKarp(){
	int flow = 0;

	while(bfs()){
		flow += augment();
	}

	return flow;
}

int main (){
	int k;

	while(scanf("%d%d%d", &n, &m, &k) != EOF){
		memset(adj, 0, sizeof adj);
		
		source = 2 * n * m + 1, sink = source + 1;

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				scanf("\n%c", &tab[i][j]);
			}
		}

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				int u = i * m + j;

				u *= 2;
				
				if(tab[i][j] == '#'){
					mark(i, j, INF);
					AddEdge(u + 1, sink, k);
				}else if(tab[i][j] == '@'){
					mark(i, j, INF);
				}else if(tab[i][j] == '.'){
					mark(i, j, 1);
				}else if(tab[i][j] == '*'){
					mark(i, j, 1);
					AddEdge(source, u, 1);
				}
			}
		}

		printf("%d\n", EdmondsKarp());
	}

	return 0;
}