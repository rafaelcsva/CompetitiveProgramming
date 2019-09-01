#include <bits/stdc++.h>

using namespace std;

#define x	first
#define y	second

typedef pair< int, int >	point;

class Rider{
public:
	int start_time;
	int end_time;
	point start, end;

	Rider(int a, int b, point c, point dd){
		start_time = a;
		end_time = b;
		start = c;
		end = dd;
	}

	Rider(){

	}
};

const int N = int(500 + 10);
Rider p[N];
vector< int > adj[N];
int match[N], vis[N];

int dfs(int u){
	if(vis[u]) return 0;

	vis[u] = 1;

	for(int v: adj[u]){
		if(match[v] == -1 || dfs(match[v])){
			match[v] = u;
			return 1;
		}
	}

	return 0;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			int h, m;

			scanf("%d:%d", &h, &m);

			point start, end;

			scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);

			int tim = h * 60 + m;
			int dis = abs(start.x - end.x) + abs(start.y - end.y);

			p[i] = Rider(tim, tim + dis, start, end);
		}

		for(int i = 0 ; i < n ; i++){
			for(int j = i + 1; j < n ; j++){
				int dis = abs(p[i].end.x - p[j].start.x) + abs(p[i].end.y - p[j].start.y);

				if(p[i].end_time + dis < p[j].start_time){
					adj[i].push_back(j);
				}
			}
		}

		int mcbm = 0;

		memset(match, -1, sizeof match);

		for(int i = 0 ; i < n ; i++){
			memset(vis, 0, sizeof vis);

			if(dfs(i)){
				mcbm++;
			}
		}

		printf("%d\n", n - mcbm);

		for(int i = 0 ; i < n ; i++) adj[i].clear();
	}

	return 0;
}
