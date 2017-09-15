#include <bits/stdc++.h>
#define MAXIMO	510
#define INF	10000000

using namespace std;

int grafo[MAXIMO][MAXIMO];

int bfs(int m, int n){
	int dist[MAXIMO][MAXIMO];

	for(int i = 0 ; i < m; i++)
		for(int j = 0 ; j < n ; j++)
			dist[i][j] = INF;	

	dist[0][0] = 0;
	
	pair <int, pair<int,int> > ii;

	priority_queue<pair<int, pair<int,int> > >fila;

	fila.push(make_pair(grafo[0][0], make_pair(0,0)));

	while(!fila.empty()){
		ii = fila.top();
		fila.pop();
		int p = grafo[ii.second.first][ii.second.second];

		int vx[] = {0, p, 0, -p};
		int vy[] = { p, 0, -p, 0};
 
		for(int i = 0 ; i < 4; i++){
			int a = ii.second.first ;
			int b = ii.second.second ;
			
			if(a + vx[i] >= 0 && a + vx[i] < m && b + vy[i] >= 0 && b + vy[i] < n){
				
				if(dist[a+vx[i]][b+vy[i]] > dist[a][b] + 1){
					dist[a+vx[i]][b+vy[i]] = dist[a][b]+1;
					fila.push(make_pair(-dist[a+vx[i]][b+vy[i]], make_pair(a+vx[i], b+vy[i])));
				}
			}
		}
	}	

	return dist[m-1][n-1];
}

int main (){
	int m, n;

	scanf("%d%d", &m, &n);	
	char c;

	for(int i = 0 ; i < m ; i ++){
		for(int j = 0 ; j < n ; j++){
			scanf("\n%c", &c);

			grafo[i][j] = c - '0';

		}
	}

	int r = bfs(m,n);

	r == INF ? printf("IMPOSSIBLE\n") : printf("%d\n", r) ;

	return 0;
}
