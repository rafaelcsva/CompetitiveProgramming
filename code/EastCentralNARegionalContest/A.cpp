#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;
const int N = 300;
int tab[N][N];
pii adj[N][N];
bool marked[N * N];
vector< int > resp;
int label[N][N];
int n, m;

bool ok(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m && tab[x][y] != -2;
}

bool dfs(int i, int j){
	if(!ok(i, j)){
		return false;
	}

	if(tab[i][j] == -1){
		return true;
	}

	if(marked[label[i][j]]){
		return false;
	}

	marked[label[i][j]] = true;
	int u = adj[i][j].first;
	int v = adj[i][j].second;

	if(dfs(u, v)){
		resp.push_back(label[i][j]);
		return true;
	}

	return false;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			scanf("%d", &tab[i][j]);
			label[i][j] = tab[i][j];
		}
	}

	int r, c;

	scanf("%d %d", &r, &c);

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(tab[i][j] < 0){
				continue;
			}

			if(ok(i - 1, j) && tab[i - 1][j] == tab[i][j]){
				adj[i][j] = {i - 2, j};
			}else if(ok(i + 1, j) && tab[i][j] == tab[i + 1][j]){
				adj[i][j] = {i + 2, j};
			}else if(ok(i, j - 1) && tab[i][j] == tab[i][j - 1]){
				adj[i][j] = {i, j - 2};
			}else if(ok(i, j + 1) && tab[i][j] == tab[i][j + 1]){
				adj[i][j] = {i, j + 2};
			}
		}
	}

	if(dfs(r, c)){
		for(int i = 0 ; i < resp.size() ; i++){
			char c = (i == int(resp.size()) - 1) ? '\n' : ' ';

			printf("%d%c", resp[i], c);
		}
	}else{
		printf("impossible\n");
	}

	return 0;
}