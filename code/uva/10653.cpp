#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
const int N = 1010;
int tab[N][N], dis[N][N];
int r, c;
int vx[] = {-1, 1, 0, 0};
int vy[] = {0, 0, 1, -1};

int bfs(int x, int y, int destx, int desty){
	memset(dis, -1, sizeof dis);
	
	dis[x][y] = 0;
	
	queue<pii>q;
	
	q.push(make_pair(x, y));
	
	while(!q.empty()){
		pii u = q.front();
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int tx = vx[i] + u.first, ty = vy[i] + u.second;
			
			if(tx >= 0 && tx < r && ty >= 0 && ty < c){
				if(dis[tx][ty] == -1 && tab[tx][ty] != 1){
					dis[tx][ty] = dis[u.first][u.second] + 1;
					
					q.push(make_pair(tx, ty));
				}
			}
		}
	}
	
	return dis[destx][desty];
}

int main (){
	
	while(scanf("%d%d", &r, &c) != EOF){
		if(r == 0 && c == 0){
			break;
		}
		
		memset(tab, 0, sizeof tab);
		
		int row;
		
		scanf("%d", &row);
		
		while(row--){
			int index, n;
			
			scanf("%d%d", &index, &n);
			
			while(n--){
				int x;
				
				scanf("%d", &x);
				
				tab[index][x] = 1;
			}
		}
		
		int x, y, destx, desty;
		
		scanf("%d%d%d%d", &x, &y, &destx, &desty);
		
		printf("%d\n", bfs(x, y, destx, desty));
	}
	
	return 0;
}
