#include <bits/stdc++.h>

#define MAXIMO	100

char grid[MAXIMO][MAXIMO];
	
int vx[4] = {0, 1, -1, 0};
int vy[4] = {1, 0, 0, -1};

void dfs(int x, int y,int n, int m){

	for(int i = 0 ; i < 4 ; i++){
		int a = vx[i] +x;
		int b = vy[i]+y;
		
		if(a < n && a >= 0 && b < m && b >= 0 && grid[a][b] != 0 && grid[a][b] != 'W'){
			grid[a][b] = 0;
			
			dfs(a, b, n, m);
		}
	}
		
}

int main (){
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j++){
			scanf("\n%c", &grid[i][j]);
		}
	}

	int ilhas = 0;
		
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			if(grid[i][j] == 'L'){
				ilhas++;
				
				dfs(i, j, n, m);
			}
		}
		
	printf("%d\n", ilhas);
	
	return 0;
}
