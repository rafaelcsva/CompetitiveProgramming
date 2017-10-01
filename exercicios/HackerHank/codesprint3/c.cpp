#include <bits/stdc++.h>

using namespace std;

const int V = 70;

int graph[V][V];
int n;

void dfs(char c, int i, int j ,int t){
	graph[i][j] = t;
	
	if(c == 'n'){
		if(i-1 >= 0 && graph[i-1][j] == 0){
			dfs(c, i-1, j, t+1);
		}else if(j+1 < n && graph[i][j+1] == 0){
			dfs(c, i, j+1, t+1);
		}else if(j-1 >= 0 && graph[i][j-1] == 0){
			dfs(c, i, j-1, t+1);
		}else if(i+1 < n && graph[i+1][j] == 0){
			dfs(c,i+1, j, t+1);
		}
	}
	else if(c == 's'){
		if(i+1 < n && graph[i+1][j] == 0){
			dfs(c, i+1, j, t+1);
		}else if(j+1 < n && graph[i][j+1] == 0){
			dfs(c, i, j+1, t+1);
		}else if(j-1 >= 0 && graph[i][j-1] == 0){
			dfs(c, i, j-1, t+1);
		}else if(i-1 >= 0 && graph[i-1][j] == 0){
			dfs(c,i-1, j, t+1);
		}
	}
	else if(c == 'e'){
		if(j + 1 < n && graph[i][j+1] == 0){
			dfs(c, i, j+1, t+1);
		}else if(i + 1 < n && graph[i+1][j] == 0){
			dfs(c, i+1, j, t+1);
		}else if(i - 1 >= 0 && graph[i-1][j] == 0){
			dfs(c, i-1, j, t+1);
		}else if(j - 1 >= 0 && graph[i][j-1] == 0){
			dfs(c, i, j-1, t+1);
		}
	}else if(c == 'w'){
		if(j - 1 >= 0 && graph[i][j-1] == 0){
			dfs(c, i, j-1, t+1);
		}else if(i + 1 < n && graph[i+1][j] == 0){
			dfs(c, i+1, j, t+1);
		}else if(i - 1 >= 0 && graph[i-1][j] == 0){
			dfs(c, i-1, j, t+1);
		}else if(j + 1 < n && graph[i][j+1] == 0){
			dfs(c, i, j+1, t+1);
		}
	}
}

int main (){
	char c;
	int x, y;
	
	cin>>n;
	cin>>c;
	cin>>x>>y;
	
	dfs(c, x, y, 1);
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0; j < n ; j++){
			cout<<graph[i][j]<<' ';
		}
		
		cout<<'\n';
	}	
	
	return 0;
}
