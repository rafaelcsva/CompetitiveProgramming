#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
typedef pair<int, pii> pipii;
const int N = 10, F = 110, INF = (int) 1e9;
int t[N];
vector<int>adj[N];
vector<int>::iterator it;
int dis[N][F];
priority_queue<pipii>pq;
int n, k;

void dijkstra(int e){
	dis[e][0] = 0;
	
	pq.push(make_pair(-dis[e][0], make_pair(0, e)));
	
	while(!pq.empty()){
		int u = pq.top().second.second;
		int f = pq.top().second.first;
		pq.pop();
		
	//	cout << u << ' ' << f << '\n';
		
		for(int i = 0 ; i < adj[u].size() ; i++){
			int v = adj[u][i];
			int d = abs(v - f);
			
			if(dis[u][v] > d * t[u] + dis[u][f]){
				dis[u][v] = d * t[u] + dis[u][f];
				pq.push(make_pair(-dis[u][v], make_pair(v, u)));
			}
			
			for(int k = 0 ; k < n ; k++){
				if(k == u)
					continue;
					
				it = lower_bound(adj[k].begin(), adj[k].end(), v);
				
				if(it != adj[k].end() && *it == v){
					if(dis[k][v] > dis[u][v] + 60){
						dis[k][v] = dis[u][v] + 60;
						
						pq.push(make_pair(-dis[k][v], make_pair(v, k)));
					}
				}
			}
		}
	}
}

int main (){	
	while(scanf("%d%d", &n, &k) != EOF){
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &t[i]);
		}		
		
		for(int i = 0 ; i < n ; i++){
			char s[F];
			
			scanf("\n%[^\n]s", s);
			
			int j = 0;
			
			while(j < strlen(s)){
				if(s[j] == ' ')
					j++;
				
				int n1 = s[j] - '0';
				
				if(j + 1 < strlen(s) && s[j + 1] != ' '){
					j++;
					
					int n2 = s[j] - '0';
					
					adj[i].push_back(n1 * 10 + n2);
					//cout << "push " << i << " " << n1 * 10 + n2 << '\n';
				}else{
					adj[i].push_back(n1);
					//cout << i << " push " << n1 << '\n';
				}
				
				j++;
			}
		}

		int best = INF;
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < F ; j++){
				dis[i][j] = INF;
			}
		}
		
		for(int i = 0 ; i < n ; i++){
			if(adj[i][0] == 0){
				dijkstra(i);
			}
		}
		
		for(int i = 0 ; i < n ; i++){
			best = min(dis[i][k], best);
		}
		
		if(best != INF)
			printf("%d\n", best);
		else
			printf("IMPOSSIBLE\n");
			
		for(int i = 0 ; i < n ; i++){
			adj[i].clear();
		}
	}

	return 0;
}
