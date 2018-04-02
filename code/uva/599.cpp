#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const int M = 30;

enum colors{white, black};
string edges[N], v;

vector<int>graph[M];
int cor[M];

bool dfs(int u){
	cor[u] = black;
	bool isTree = false;

	for(int i = 0 ; i < graph[u].size() ; i++){
		isTree = true;

		if(cor[graph[u][i]] == white){
			dfs(graph[u][i]);
		}
	}

	return isTree;
}

int main (){
	int n;

	cin >> n;

	while(n--){
		string s;

		int i = 0;

		while(cin >> edges[i++]){
			if(edges[i - 1][0] == '*')
				break;

		}

		i--;
		cin >> v;

		for(int k = 0 ; k < i ; k++){
			int u = edges[k][1] - 'A';
			int v = edges[k][3] - 'A';

			graph[u].push_back(v);
			graph[v].push_back(u);			
		}

		int acorn = 0, tree = 0;

		for(int k = 0 ; k < v.length() ; k++){
			if(!(v[k] >= 'A' && v[k] <= 'Z')){
				continue;
			}

			int u = v[k] - 'A';

			if(cor[u] != white)
				continue;

			if(dfs(u)){
				tree++;
			}else{
				acorn++;
			}
		}
		
		cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";

		for(int i = 0 ; i < M ; i++){
			graph[i].clear();
		}

		for(int i = 0 ; i < M ; i++){
			cor[i] = white;
		}
	}

	return 0;
}
