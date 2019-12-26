#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 10);
vector< int > adj[N];
vector< int > edges;
vector< int > vert;
int coin = 0;
const int inf = int(1e9) + 10;

void dfs(int u, int ft, int val, int &ed, int &ve){
	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i];

		if(v == ft) continue;

		int nxt = edges[ed];

		if(nxt > val){
			ve--;
			coin++;
			val = inf;
		}

		int nxtv = vert[ve];
		int sonw;

		if(nxtv < nxt){
			coin++;
			sonw = inf;
		}else{
			sonw = nxtv;
			ve++;
		}

		ed++;

		dfs(v, u, sonw, ed, ve);
	}
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 1 ; i < n ; i++){
			int ui, vi, wi;

			scanf("%d %d %d", &ui, &vi, &wi);

			adj[ui].push_back(vi);
			adj[vi].push_back(ui);

			edges.push_back(wi);
		}

		for(int i = 1 ; i <= n ; i++){
			int wi;

			scanf("%d", &wi);

			vert.push_back(wi);
		}

		sort(vert.begin(), vert.end(), greater< int >());
		sort(edges.begin(), edges.end(), greater< int >());

		int ed = 0;
		int ve = 1;

		dfs(1, 1, vert[0], ed, ve);

		printf("%d\n", coin);

		edges.clear();
		vert.clear();
		coin = 0;

		for(int i = 1 ; i <= n ; i++) adj[i].clear();
	}

	return 0;
}