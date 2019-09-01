#include <bits/stdc++.h>

using namespace std;

class Triple{
public:
	int a, b, c;
};

const int N = 52;
vector< Triple > reqs;
int mat[N][N];

int main(){
	int t;

	scanf("%d", &t);

	for(int test = 1 ; test <= t ; test++){
		memset(mat, -1, sizeof mat);

		int n, m;

		scanf("%d %d", &n, &m);

		for(int i = 0 ; i < m ; i++){
			int ui, vi, zi;

			scanf("%d %d %d", &ui, &vi, &zi);

			reqs.push_back({ui, vi, zi});

			mat[ui][vi] = mat[vi][ui] = zi;
		}

		for(int k = 1 ; k <= n ; k++){
			for(int i = 1 ; i <= n ; i++){
				for(int j = 1 ; j <= n ; j++){
					if(mat[i][k] == -1 || mat[k][j] == -1){
						continue;
					}

					if(mat[i][j] == -1){
						mat[i][j] = mat[i][k] + mat[k][j];
					}

					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}

		bool ok = true;

		for(auto u: reqs){
			if(mat[u.a][u.b] != u.c){
				ok = false;
				break;
			}
		}

		printf("Case #%d:", test);

		if(ok){
			printf(" %lu\n", reqs.size());

			for(auto u: reqs){
				printf("%d %d %d\n", u.a, u.b, u.c);
			}
		}else{
			printf(" Impossible\n");
		}

		reqs.clear();
	}

	return 0;
}