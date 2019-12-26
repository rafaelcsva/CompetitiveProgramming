#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = int(1e5 + 10), M = int(1e5 + 10);
ll a[N];
const int D = 62;
int cnt[D];
vector< int > adj[N];
queue< int > q;
int dis[M];
int marked[N];
int father[M];

int bfs(int u){
	q.push(u);
	int res = int(1e9);
	dis[u] = 0;
	marked[u] = u + 1;
	father[u] = u;		

	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(int i = 0 ; i < adj[v].size() ; i++){
			int e = adj[v][i];

			if(marked[e] != u + 1){
				marked[e] = u + 1;
				dis[e] = dis[v] + 1;
				father[e] = v;
				q.push(e);
			}else if(father[v] != e){ 
				while(!q.empty()){
					q.pop();
				}

				return min(res, dis[e] + dis[v] + 1);
			}
		}
	}

	return res;
}

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i]);	

		ll b = 1LL;

		for(int d = 0 ; d < D ; d++){
			if(a[i] & b){
				cnt[d]++;
			}

			b <<= 1LL;
		}
	}

	for(int i = 0 ; i < D ; i++){
		if(cnt[i] >= 3){
			printf("3\n");
			return 0;
		}
	}

	for(int i = 0 ; i < n ; i++){
		if(a[i] == 0) continue;
		
		for(int j = 0 ; j < n ; j++){
			if((a[i] & a[j]) && i != j){
				adj[i].push_back(j);
			}
		}
	}

	int best = int(1e9);

	for(int i = 0 ; i < n ; i++){
		if(adj[i].size() >= 2)
			best = min(best, bfs(i));
	}

	if(best == int(1e9)){
		printf("-1\n");
	}else{
		printf("%d\n", best);
	}

	return 0;
}