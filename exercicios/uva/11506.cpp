#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int adj[N][N], pre[N][N];
int p[N];
int source = 2, sink;
int dis[N];
const int INF = (int) 1e9;

bool bfs(){
	queue<int>q;
	memset(dis, -1, sizeof dis);
	q.push(source);
	dis[source] = 1;
	
	while(!q.empty()){
		int u = q.front();
	//	cout << u << ' ';
		q.pop();

		for(int i = 1 ; i <= sink ; i++){
			if(adj[u][i] && dis[i] == -1){
				//cout << "returned true\n";
				if(i == sink){
					p[i] = u;
					dis[i] = 1;
					
					continue;
				}

				int v = i + !(i % 2);

				if(v == i || adj[i][v]){
			//		cout << "pushed " << v << '\n';
					dis[v] = dis[i] = 1;
					q.push(v);
					p[i] = u;

					if(v != i)
						p[v] = i;
				}
			}
		}
	}
//	cout << endl;
	return dis[sink] != -1;
}

void bfs2(){
	queue<int>q;
	memset(dis, -1, sizeof dis);

	q.push(source);
	dis[source] = 1;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i = 1 ; i <= sink ; i++){
			if(dis[i] == -1 && adj[u][i]){
				dis[i] = 1;
				q.push(i);
			}
		}
	}

}
int augment(){
	int r = (int) 1e9;
	int ac = sink;
	
	while(ac != source){
		r = min(r, adj[p[ac]][ac]);
	//	cout << ac / 2 ;

		if(ac % 2){
		//	cout << "'";
		}

		//cout << " ";

		ac = p[ac];
	}

	//cout << "1 (" << r << ")\n";

	ac = sink;

	while(ac != source){
		adj[p[ac]][ac] -= r;
		adj[ac][p[ac]] += r;
		ac = p[ac];
	}

	return r;
}

int edmondskarp(){
	int flow = 0;
	
	while(bfs()){
		flow += augment();
	}

	return flow;
}

int main (){
	int n, w;
	
	while(scanf("%d %d", &n, &w)){
		if(n == 0)
			break;
		memset(adj, 0, sizeof adj);
		memset(pre, 0, sizeof pre);

		sink = 2 * n;
		
		adj[source][source + 1] = adj[sink][sink + 1] = INF;
//		cout << source << " " << source + 1 << '\n';
		
		for(int i = 1 ; i < n - 1 ; i++){
			int index, w;

			scanf("%d%d", &index, &w);

			index *= 2;
			adj[index][index + 1] = w;
			pre[index][index + 1] = w;
		}

		for(int i = 0 ; i < w ; i++){
			int u, v, d;

			scanf("%d%d%d", &u, &v, &d);

			if(u > v){
				swap(u, v);
			}

			u *= 2;
			v *= 2;
		
			adj[u + 1][v] = d;
		//	cout << "(" << u + 1 << "," << v << ")\n";
			pre[u + 1][v] = d;

			adj[v + 1][u] = d;
		//	cout << "(" << v + 1 << "," << u << ")\n";
			pre[v + 1][u] = d;
		}

		edmondskarp();
		bfs2();

		int minCut = 0;

		for(int i = source ; i <= sink ; i++){
			if(dis[i] == 1){
				for(int j = i + 1 ; j <= sink ; j++){
					if(dis[j] == -1){
						minCut += pre[i][j];
			//			cout << i << "->" << j << " " << pre[i][j]<< '\n';
					}
				}
			}
		}

		printf("%d\n", minCut);
	}

	return 0;
}
