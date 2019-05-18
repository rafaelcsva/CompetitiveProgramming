#include <bits/stdc++.h>

using namespace std;

const int N = 1100;
int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};
int n;
int vis[N][N];
int a[N][N];

bool ok(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void dfs(int i, int j){
	vis[i][j] = 1;

	for(int k = 0 ; k < 4 ; k++){
		int x = vi[k] + i;
		int y = vj[k] + j;

		if(ok(x, y) && !vis[x][y] && a[x][y]){
			dfs(x, y);
		}
	}
}

int main(){
	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			scanf("%d", &a[i][j]);
		}
	}

	dfs(1, 1);

	printf("%s\n", vis[n][n] ? "Vai pra aula, Dilsinho!" : "Fica em casa, Dilsinho!");

	return 0;
}