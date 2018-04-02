#include <bits/stdc++.h>

using namespace std;

const int N = 100;
char tab[N][N];
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};

int n, m;

int dfs(int x, int y){
	if(tab[x][y] == 'l'){
		tab[x][y] = 'w';
	
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
				dfs(tx, ty);
			}
		}
	}
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
		
		dfs(x, y);
		
		int cnt = 0;
		
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				cnt += tab[i][j] == 'l';
			}
		}
		
		printf("%d\n", cnt);
	}

	return 0;
}

