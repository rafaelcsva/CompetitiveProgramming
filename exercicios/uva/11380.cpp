#include <bits/stdc++.h>

using namespace std;

#define	DEBUG	1
const int N = 30 * 30 + 10;
int n, m, p;
char tab[N][N];
int f[N], adj[N][N];
int source, sink, size;
int dis[N];
int vi[] = {0, 0, 1, -1}, vj[] = {1, -1, 0, 0};
pair<int, int>mp[N];

bool ok(int ti, int tj){
	return ti >= 1 && ti <= n && tj >= 1 && tj <= m;
}

void mark(int i, int j, int w){
	int u = (i - 1) * m + j;
	
	for(int k = 0 ; k < 4 ; k++){
		int ti = vi[k] + i, tj = vj[k] + j;
		
		if(ok(ti, tj)){
			int v = (ti - 1) * m + tj;
			
			adj[u][v] = w;
		}
	}
}

void unmark(int u){
	int i = mp[u].first, j = mp[u].second;
		 
	if(tab[i][j] == '.' || tab[i][j] == '*'){
		for(int k = 0 ; k < 4 ; k++){
			int ti = vi[k] + i, tj = vj[k] + j;
			
			if(ok(ti, tj)){
				int v = (ti - 1) * m + tj;
			
				if(f[u] != v){
					//printf("(%d, %d) unmarking (%d, %d)\n", i, j, ti, tj);
					adj[u][v] = 0;
					adj[v][u] = 1;
				}
			}
		}
	}
}

int augment(){
	int ac = sink;
	int mn = N;
	
	while(ac != source){
	
		if(DEBUG)
			printf("%d ", ac);
			
		mn = min(mn, adj[f[ac]][ac]);
		ac = f[ac];
	}
	
	if(DEBUG)
		printf("\n");
		
	ac = sink;
	
	while(ac != source){
		
		adj[f[ac]][ac] -= mn;
		adj[ac][f[ac]] += mn;
		
		ac = f[ac];
		unmark(ac);
		
	}
	
	return mn;
}

bool bfs(){
	memset(dis, -1, sizeof dis);
	
	queue<int>q;
	q.push(source);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i = 1 ; i <= size ; i++){
			if(adj[u][i] && dis[i] == -1){
				dis[i] = 1;
				f[i] = u;
				q.push(i);
			}
		}
	}
	//printf("%d\n", dis[size]);
	return dis[sink] != -1;
}

int edmondskarp(){
	int flow = 0;
	
	while(bfs()){
		flow += augment();
	}
	
	return flow;
}

int main (){
	while(scanf("%d%d%d", &n, &m, &p) != EOF){
		memset(adj, 0, sizeof adj);
		sink = (n * m) + 1;
		size = sink;
		
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				scanf("\n%c", &tab[i][j]);
			}
		}
		
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				int u = (i - 1) * m + j;
				mp[u] = make_pair(i, j);
				
				if(tab[i][j] == '.' || tab[i][j] == '*'){
					mark(i, j, 1);
					
					if(tab[i][j] == '*'){
						//printf("%d->%d\n", 0, u); 
						adj[0][u] = 1;
					}
					
				}else if(tab[i][j] == '@'){
					mark(i, j, N);
				}else if(tab[i][j] == '#'){
					adj[u][sink] = p;
					//printf("%d->%d (%d)\n", u, sink, p);
					mark(i, j, N);
				}
			}
		}
		
		printf("%d\n", edmondskarp());
	}
		
	return 0;
}
