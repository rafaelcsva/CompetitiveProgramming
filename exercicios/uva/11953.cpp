#include <bits/stdc++.h>

using namespace std;

const int N = 110;
char tab[N][N];
int n;
int vx[4] = {0, 0, -1, 1};
int vy[4] = {1, -1, 0, 0};

void dfs(int i, int j){
	tab[i][j] = '.';
	
	for(int k = 0 ; k < 4 ; k++){
		int ti = i + vx[k], tj = j + vy[k];
		
		if(ti >= 0 && ti < n && tj >= 0 && tj < n){
			if(tab[ti][tj] != '.'){
				dfs(ti, tj);
			}
		}
		
	}
	
}

int main (){
	int t;
	int test = 1;
	
	scanf("%d", &t);
	
	while(t--){
		
		scanf("%d", &n);
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				scanf("\n%c", &tab[i][j]);
			}
		}
		
		int cnt = 0;
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(tab[i][j] == 'x'){
					cnt++;
					
					dfs(i, j);
				}
			}
		}
		
		printf("Case %d: %d\n", test++, cnt);
	}
	
	return 0;
}
