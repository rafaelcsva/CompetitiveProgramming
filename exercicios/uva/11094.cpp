#include <bits/stdc++.h>

using namespace std;

const int N = 100;
char tab[N][N];
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};

int n, m;
char c;

int dfs(int x, int y){
	int r = 0;
	
	if(tab[x][y] == c){
		r++;
		
		tab[x][y] = !c;
	
		for(int i = 0 ; i < 4 ; i++){
			int tx = vx[i] + x;
			int ty = vy[i] + y;
		
			if(ty < 0){
				ty = n - 1;
			}
			if(ty >= n){
				ty = 0;
			}
		
			if(tx >= 0 && tx < m){
				r += dfs(tx, ty);
			}
		}
	}
	
	return r;
}

int main (){
	
	while(scanf("%d%d", &m, &n) != EOF){
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				scanf("\n%c", &tab[i][j]);
			}
		}
		
		int x, y;
		
		scanf("%d%d", &x, &y);
		
		c = tab[x][y];
		
		dfs(x, y);
		
		int ans = 0;
		
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				ans = max(ans, dfs(i, j));
			}
		}
		
		printf("%d\n", ans);
	}

	return 0;
}

