#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;

typedef long long	ll;

const int D = 22;
const int P = 50;
vector< int > con[P][P], tmp[P][P], tmp1[P][P];

pii classify(int val){
	int tmp = 0;
	int ones = 0;
	int zero = 0;

	for(int d = 0 ; d < D ; d++){
		int e = 1 << d;

		if(val & e){
			zero += tmp;
			tmp = 0;
			ones++;
		}else{
			tmp++;
		}
	}

	return {ones, zero};
}

int main(){
	freopen("zeros.in", "r", stdin);

	int lim = 1 << D;

	for(int i = 1 ; i < lim ; i++){
		pii c = classify(i);
		
		con[c.first][c.second].push_back(i);
	}

	int t;

	scanf("%d", &t);

	while(t--){
		int x, y, m, k;

		scanf("%d %d %d %d", &x, &y, &m, &k);
		
		int hx = x;
		int hy = y ;
		int half = (x + y) / 2 + ((x + y) & 1);

		int lim = 1 << half;

		for(int i = 0 ; i < lim ; i++){
			int one = 0, zero = 0;

			for(int j = 0 ; j < half ; j++){
				int e = 1 << j;

				if(i & e){
					one++;
				}else{
					zero++;
				}
			}

			tmp1[one][zero].push_back(i % m);
		}

		for(int i = 0 ; i <= x ; i++){
			for(int j = 0 ; j <= y ; j++){
				sort(tmp1[i][j].begin(), tmp1[i][j].end());
			}
		}

		for(int i = 0; i <= hx ; i++){
			for(int j = 0 ; j <= hy ; j++){

				// printf("%d, %d\n", i, j);

				for(auto d: con[i][j]){
					tmp[i][j].push_back(d % m);
				}

				// printf("%d, %d %lu\n", i, j, tmp[i][j].size());

				sort(tmp[i][j].begin(), tmp[i][j].end());
			}
		}

		ll tot = 0;

		for(int i = 0 ; i <= hx ; i++){
			for(int j = 0 ; j <= hy ; j++){
				if(i + j != half || i > x || j > y) continue;

				for(auto d: tmp[i][j]){
					int nx = x - i, ny = y - j;
					// printf("->%d %d %d %d\n", d, x, nx, ny);
					// fflush(stdout);
					int x = (ll(d) * ((1LL << (ll(nx + ny))))) % ll(m);
					// printf("p on %d\n", d);

					int lo = ((k - x) + m) % m;
					int hi = ((m - 1 - x) % m + m) % m; 
					// printf("(%d, %d)\n", lo, hi);

					// printf("%d - %d\n", lo, hi);

					int lb = lower_bound(tmp1[nx][ny].begin(), tmp1[nx][ny].end(), lo) - tmp1[nx][ny].begin();
					int hb = upper_bound(tmp1[nx][ny].begin(), tmp1[nx][ny].end(), hi) - tmp1[nx][ny].begin();
					// printf("%d %d %lu\n", lb, hb);

					if(lb < hb){
						tot += ll(hb - lb);
					}else{
						tot += ll(tmp1[nx][ny].size() - lb + hb);
					}
				}
			}
		}

		printf("%lld\n", tot);

		for(int i = 0 ; i <= hx ; i++){
			for(int j = 0 ; j <= hy ; j++){
				// printf("free on %d, %d\n", i, j);
				tmp[i][j].clear();
				tmp1[i][j].clear();
			}
		}
	}

	return 0;
}