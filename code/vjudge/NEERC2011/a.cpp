#include <bits/stdc++.h>

using namespace std;

const int N = 110;
char tab[N][N];
int marked[N][N];
int test = 1;
int n, m;

int vi[4] = {0, 0, -1, 1};
int vj[4] = {1, -1, 0, 0};

bool ok(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

int dfs(int i, int j){
	marked[i][j] = test;
	int sum = 2;

	for(int k = 0 ; k < 4 ; k++){
		int x = vi[k] + i;
		int y = vj[k] + j;

		if(!ok(x, y)){
			return -10000000;
		}

		if(marked[x][y] != test && tab[x][y] == '.'){
			sum += dfs(x, y);
		}
	}

	return sum;
}

int main(){

	while(scanf("%d %d", &n, &m) != EOF){
		for(int i = 0 ; i < n ; i++){
			scanf("\n%s", tab[i]);
		}

		int area = 0;

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(tab[i][j] == '/' || tab[i][j] == '\\'){
					area++;
				}else if(marked[i][j] != test){
					area += max(dfs(i, j), 0);
				}
			}
		}

		printf("%d\n", area / 2);
		test++;
	}

	return 0;
}