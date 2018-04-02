#include <bits/stdc++.h>

using namespace std;

const int N = 110;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
vector<pipii>edges;
int f[N];
int dis[N][N], memo[N][N];
int c, s, q;

int find(int x){
	if(f[x] == x){
		return x;
	}
	
	return f[x] = find(f[x]);
}

void join(int u, int v, int w){
	int x = find(u), y = find(v);
	
	if(x != y){
		dis[u][v] = dis[v][u] = w;
		
		if(x > y){
			f[x] = y;
		}else{
			f[y] = x;
		}
	}
}

bool dfs(int u, int v, int f, int w){
	if(u == v){
		memo[u][v] = memo[v][u] = w;
		printf("%d\n", w);
		return true;
	}
	
	for(int i = 1 ; i <= c ; i++){
		if(dis[u][i] != -1 && i != f){
			if(dfs(i, v, u, max(dis[u][i], w))){
				return true;	
			}
		}
	}
	
	return false;
}

int main (){
	int test = 0;
	
	while(scanf("%d%d%d", &c, &s, &q) != EOF){
		memset(dis, -1, sizeof dis);
		memset(memo, -1, sizeof memo);
		
		if(c == 0 && s == 0 && q == 0){
			break;
		}
		
		if(test){
			printf("\n");
		}	
		
		for(int i = 0 ; i < c ; i++){
			f[i] = i;
		}
		
		printf("Case #%d\n", ++test);
		
		while(s--){
			int u, v, w;
			
			scanf("%d%d%d", &u, &v, &w);
			
			edges.push_back(make_pair(w, make_pair(u, v)));
		}
		
		sort(edges.begin(), edges.end());
		
		for(int i = 0 ; i < edges.size() ; i++){
			pii ii = edges[i].second;
			int d = edges[i].first;
			
			join(ii.first, ii.second, d);
		}
		
		while(q--){
			int u, v;
			
			scanf("%d%d", &u, &v);
			
			if(find(u) != find(v)){
				printf("no path\n");
			}else{
				if(memo[u][v] != -1){
					printf("%d\n", memo[u][v]);
				}else{
					dfs(u, v, u, 0);
				}
			}
		}
		
		edges.clear();
	}

	return 0;
}
