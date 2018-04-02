#include <bits/stdc++.h>

#define MAXIMO	60

using namespace std;

int main (){
	char grid[MAXIMO][MAXIMO];
	int n, m;

	scanf("%d%d", &n, &m);

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			scanf("\n%c", &grid[i][j]);

	for(int i = n-2; i >= 0 ; i--){
		for(int j = 0 ; j < m ;j++){
			if(grid[i][j] == 'o'){
				
				int k;
				for(k = i+1 ; k < n ; k++){
					if(grid[k][j] != '.'){
						int c = grid[k-1][j];
						grid[k-1][j] = grid[i][j];
						grid[i][j] = c;
						break;
					}
				}

				if(k == n){
					
					int c = grid[k-1][j];
					grid[k-1][j] = grid[i][j];
					grid[i][j] = c;
				}
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			printf("%c", grid[i][j]);
		printf("\n");
	}
	return 0;
	
}
