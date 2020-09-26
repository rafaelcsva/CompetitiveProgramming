#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int T = int(1e4) + 10;
set< char > vert[2][N];
vector< int > adj[N];
char event[T];
int state[N];

void dfs(int u){
	// printf("u: %d\n", u);

	int a = 0;

	for(int v: adj[u]){
		dfs(v);

		for(int d: vert[0][v]){
			vert[a][u].insert(d);
		}

		for(int d: vert[1][v]){
			vert[a][u].insert(d);
		}

		a++;
	}

	if(adj[u].size() == 0){
		vert[0][u].insert((char)u);
	}
}

int main(){
	freopen("instruction.in", "r", stdin);
	freopen("instruction.out", "w", stdout);

	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		char t;

		scanf("\n%c", &t);

		int conn;

		scanf("%d ", &conn);

		if(t != 's'){
			char cod;

			scanf("\n%c", &cod);

			if(conn != 0){
				adj[conn].push_back(cod);
			}
		}else{
			if(conn != 0){
				adj[conn].push_back(i + 1);
			}
		}
	}

	dfs(1);

	int m;

	scanf("%d", &m);

	for(int i = 0 ; i < m ; i++){
		int tim;
		char dest;

		scanf("\n%d %c", &tim, &dest);
		
		event[tim] = dest;
	}

	vector< pair< int, char > > active_trains;
	vector< pair< int, int > > commands;

	for(int i = 0 ; i < T ; i++){
		vector< pair< int, char > > nv;

		for(auto e: active_trains){
			if(adj[e.first].size() == 0){
				continue;
			}

			if(vert[0][e.first].find(e.second) != vert[0][e.first].end()){
				if(state[e.first] != 0){
					state[e.first] = 0;
					commands.push_back({e.first, i});
				}

				nv.push_back({adj[e.first][0], e.second});
			}else{
				// printf("%d %c\n", e.first, e.second);
				fflush(stdout);

				assert(vert[1][e.first].find(e.second) != vert[1][e.first].end());

				if(state[e.first] != 1){
					state[e.first] = 1;
					commands.push_back({e.first, i});
				}

				nv.push_back({adj[e.first][1], e.second});
			}
		}

		if(event[i]){
			nv.push_back({1, event[i]});
			// printf("inserindo %c\n", event[i]);
		}
		active_trains = nv;
		

		// printf("on time %d\n", i);
		// for(auto u: active_trains){
		// 	printf("%d go to %c\n", u.first, u.second);
		// }
	}

	printf("%lu\n", commands.size());
	for(auto u: commands){
		printf("%d %d\n", u.first, u.second);
	}

	return 0;
}