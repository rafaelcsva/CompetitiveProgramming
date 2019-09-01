#include <bits/stdc++.h>

using namespace std;

int r[2], c[2];
int ma[310][310];

const int D = 4;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

bool ok(int x, int y, int n, int m){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

bool is_traped(int n, int m, int a, int b){
	for(int i = 0 ; i < D ; i++){
		int x = di[i] + a, y = dj[i] + b;

		if(ok(x, y, n, m)){
			if(!ma[x][y]){
				return false;
			}
		}
	}

	return false;
}

int main(){
	int t;

	scanf("%d", &t);

	for(int test = 1 ; test <= t ; test++){
		int n, m, k;

		scanf("%d %d %d", &n, &m, &k);

		int a, b;

		scanf("%d %d", &a, &b);

		for(int i = 0 ; i < k ; i++){
			scanf("%d %d", &r[i], &c[i]);
			ma[r[i]][c[i]] = 1;
		}

		printf("Case #%d: ", test);

		if(k == 1){
			printf("N\n");
		}else{
			int d1 = abs(r[0] - a) + abs(c[0] - b);
			int d2 = abs(r[1] - a) + abs(c[1] - b);

			if(is_traped(n, m, a, b) || ((d1 & 1) == (d2 & 1) && ((d1 & 1) == 0))){
				printf("Y\n");
			}else{
				printf("N\n");
			}
		}

		memset(ma, 0, sizeof ma);
	}

	return 0;
}