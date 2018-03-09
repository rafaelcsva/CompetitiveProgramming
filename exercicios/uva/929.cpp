#include <bits/stdc++.h>

using namespace std;

const int N = 1010, INF = (int) 1e9;
typedef pair<int, int>pii;
typedef pair<int, pii>pipii;

priority_queue<pipii>pq;
int n, m;
int tab[N][N], dis[N][N];
int vx[] = {0, 0, 1, -1};
int vy[] = {1, -1, 0, 0};

int dijkstra(){
	pq.push(make_pair(-tab[0][0], make_pair(0, 0)));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			dis[i][j] = INF;
		}
	}
	
	dis[0][0] = tab[0][0];
	
	while(!pq.empty()){
		pii u = pq.top().second;
		pq.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int tx = u.first + vx[i], ty = u.second + vy[i];
			
			if(tx >= 0 && tx < n && ty >= 0 && ty < m){
				if(dis[tx][ty] > dis[u.first][u.second] + tab[tx][ty]){
					dis[tx][ty] = dis[u.first][u.second] + tab[tx][ty];
					pq.push(make_pair(-dis[tx][ty], make_pair(tx, ty)));
				}
			}
		}		
	}
	
	return dis[n - 1][m - 1];
}

int main (){
	int t;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				scanf("%d", &tab[i][j]);
			}
		}
		
		printf("%d\n", dijkstra());
	}
	
	return 0;	
}
