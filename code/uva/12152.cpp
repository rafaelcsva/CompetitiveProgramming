#include <bits/stdc++.h>

using namespace std;

const int N = 710;
int adj[N][N];
int is_bridge[N][N];
int runt = 1;
int mark[N];
bool is_one[N];
int n, m;
int deg[N];
vector< int > odds;
vector< int > con[N];

int NO; // number of nodes
vector< int > madj[N];
int visited[N];
int tin[N], low[N];
int timer;

void dfs(int v, int p = -1) {
    visited[v] = runt;
    tin[v] = low[v] = timer++;
    for (int to : madj[v]) {
        if (to == p) continue;
        if (visited[to] == runt) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                is_bridge[v][to] = is_bridge[to][v] = runt;
            }
        }
    }
}

int find_bridges() {
    timer = 0;

    for(int i = 0 ; i < NO ; i++){
    	tin[i] = low[i] = -1;
    } 

    int comp = 0;

    dfs(0);

    for(int i = 0 ; i < n ; i++){
    	if(visited[i] != runt){
    		return 2;
    	}
    }

    return 1;
}

int main(){
	int test = 1;

	while(scanf("%d %d", &n, &m) != EOF){
		NO = n + m;

		if(n == 0 && m == 0){
			break;
		}

		for(int i = 0 ; i < m ; i++){
			int ki;

			scanf("%d", &ki);

			for(int j = 0 ; j < ki ; j++){
				int ai;

				scanf("%d", &ai);

				adj[ai][i + n] = adj[i + n][ai] = runt;
				madj[ai].push_back(i + n);
				madj[i + n].push_back(ai);

				deg[i + n]++;
				con[ai].push_back(i + n);
			}
		}

		for(int i = 0 ; i < n ; i++){
			if(con[i].size() == 1){
				deg[con[i][0]]++;
				madj[con[i][0]].push_back(i);
				madj[i].push_back(con[i][0]);
			}
		}

		int r = find_bridges();

		if(r > 1){
			printf("-1\n");
		}else{
			for(int i = 0 ; i < m ; i++){
				if(deg[i + n] & 1){
					odds.push_back(i + n);
				}
			}

			if(odds.size() != 2 && odds.size() != 0){
				printf("-1\n");
			}else{
				if(odds.size() == 0){
					printf("0\n");
				}else{
					int best = n;

					for(int i = 0 ; i < odds.size() ; i++){
						int u = odds[i];

						bool tested = false;

						for(int j = 0 ; j < n ; j++){
							if(adj[u][j] == runt && (is_bridge[u][j] != runt || con[j].size() == 1)){
								best = min(best, j);
								tested = true;
							}
						}

						if(!tested){
							for(int j = 0 ; j < n ; j++){
								if(adj[u][j] == runt){
									best = min(best, j);
								}
							}
						}
					}

					printf("%d\n", best);
				}
			}

			odds.clear();
		}

		for(int i = 0 ; i < n ; i++){
			con[i].clear();
		}

		for(int i = 0 ; i < m + n ; i++){
			is_one[i] = false;
			deg[i] = 0;
			madj[i].clear();
		}

		runt++;
		test++;
	}

	return 0;
}
