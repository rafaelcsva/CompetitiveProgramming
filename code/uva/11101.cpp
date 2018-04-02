#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
const int N = 2010;
bool belongMall2[N][N];
int dis[N][N];
queue<pii>q;
int vx[] = {-1, 1, 0, 0}, vy[] = {0, 0, -1, 1};

int bfs(){
	int best = -1;
	
	while(!q.empty()){
		pii u = q.front();
		q.pop();
				
		if(belongMall2[u.first][u.second]){
			if(best == -1){
				best = dis[u.first][u.second];
			}else{
				best = min(best, dis[u.first][u.second]);
			}
			
			continue;
		}
		
		for(int i = 0 ; i < 4 ; i++){
			int tx = u.first + vx[i], ty = u.second + vy[i];
			
			if(tx >= 0 && tx <= 2000 && ty >= 0 && ty <= 2000){
				if(dis[tx][ty] == -1){
					dis[tx][ty] = dis[u.first][u.second] + 1;
					q.push(make_pair(tx, ty));
				}
			}
		}	
	}
	
	return best;
}

int main (){
	int n, p;
	
	while(scanf("%d", &n) && n){
		memset(dis, -1, sizeof dis);
		memset(belongMall2, 0, sizeof belongMall2);
				
		for(int i = 0 ; i < n ; i++){
			int x, y;
			
			scanf("%d%d", &x, &y);
			
			dis[x][y] = 0;
			q.push(make_pair(x, y));
		}	
		
		scanf("%d", &p);
		
		for(int i = 0 ; i < p ; i++){
			int x, y;
			
			scanf("%d%d", &x, &y);
			
			belongMall2[x][y] = true;
		}
		
		printf("%d\n", bfs());
	}

	return 0;
}
