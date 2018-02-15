#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 510;
char t[N][M];
int n, m;

int vx[4] = {0, 0, 1, -1};
int vy[4] = {1, -1, 0, 0};

void dfs(int i, int j, int &c){
	if(c == 0)
		return;
		
	t[i][j] = 'm';
	c--;
	
	for(int k = 0 ; k < 4 ; k++){
		int tx = i + vx[k];
		int ty = j + vy[k];
		
		if(tx >= 0 && tx < n && ty >= 0 && ty < m && t[tx][ty] == '.'){
			dfs(tx, ty, c);
		}
	}
}
int main (){
	int k;
	
	scanf("%d%d%d", &n, &m, &k);
	
	int h = 0;
		
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			scanf("\n%c", &t[i][j]);
			if(t[i][j] == '#')
				h++;
		}
	}
	
	bool find = false;
	
	for(int i = 0 ;i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(t[i][j] == '.'){
				int c = n * m - h - k;
				
				find = true;
				dfs(i, j, c);
				break;
			}
		}
		
		if(find)
			break;
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(t[i][j] != 'm'){
				if(t[i][j] == '.'){
					printf("X");
				}else{
					printf("#");
				}
			}else{
				printf(".");
			}
		}
		printf("\n");
	}

	return 0;
}
