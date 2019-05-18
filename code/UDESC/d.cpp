#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

typedef pair< int, int >	pii;
typedef pair< ll, pii >	pll;

const int N = 60;
ll dis[N][N][N][N];
const ll inf = 1e18;
priority_queue< pll > pq;
ll a[N][N];
int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};
int n, m;

bool ok(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

ll dijkstra(int i, int j){
	pq.push({-dis[i][j][i][j], {i, j}});

	while(!pq.empty()){
		pll uu = pq.top();
		pq.pop();

		pii u = uu.second;

		uu.first *= -1LL;

		if(dis[i][j][u.first][u.second] < uu.first){
			continue;
		}

		for(int k = 0 ; k < 4 ; k++){
			int x = u.first + vi[k];
			int y = u.second + vj[k];

			if(ok(x, y) && dis[i][j][x][y] > dis[i][j][u.first][u.second] + a[x][y]){
				dis[i][j][x][y] = dis[i][j][u.first][u.second] + a[x][y];
				pq.push({-dis[i][j][x][y], {x, y}});
			}
		}
	}

	ll best = inf;

	for(int k = 1 ; k <= m ; k++){
		best = min(best, dis[i][j][n][k]);
	}

	return best;
}

int main(){
	int c;
	int ts = 1;

	scanf("%d", &c);

	while(c--){
		scanf("%d %d", &n, &m);

		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				for(int d = 1 ; d <= n ; d++){
					for(int p = 1 ; p <= m ; p++){
						dis[i][j][d][p] = inf;
					}
				}
			}
		}

		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				scanf("%lld", &a[i][j]);
				dis[i][j][i][j] = a[i][j];
			}
		}

		ll best = inf;

		for(int j = 1 ; j <= m ; j++){
			best = min(best, dijkstra(1, j));
		}
	
		printf("Caso #%d : CUSTO: %lld\n", ts++, best);
	}

	return 0;
}