#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e3;
char sqr[N][N];
char sqr2[N][N];
char sqr90[N][N], sqr180[N][N], sqr270[N][N];
int cnt[10];

void rotate90(int mod, int m){
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < m ; j++){
			if(mod == 1){
				sqr90[i][j] = sqr2[m - j - 1][i];
			}else if(mod == 2){
				sqr180[i][j] = sqr90[m - j - 1][i];
			}else if(mod == 3){
				sqr270[i][j] = sqr180[m - j - 1][i];
			}
		}
	}
}

int isEqual(int x, int y, int m, int mod){
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < m ; j++){
			char c;

			if(mod == 0){
				c = sqr2[i][j];
			}
			else if(mod == 1){
				c = sqr90[i][j];
			}else if(mod == 2){
				c = sqr180[i][j];
			}else if(mod == 3){
				c = sqr270[i][j];
			}

			if(sqr[i + x][j + y] != c)
				return 0;
		}
	}

	return 1;
}

int main (){
	int n, m;

	while(scanf("%d%d", &n, &m)){
		if(n == 0){
			break;
		}

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				scanf("\n%c", &sqr[i][j]);
			}
		}	

		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < m ; j++){
				scanf("\n%c", &sqr2[i][j]);
			}
		}

		rotate90(1, m);
		rotate90(2, m);
		rotate90(3, m);

		for(int i = 0 ; i <= n - m ; i++){
			for(int j = 0 ; j <= n - m ; j++){
				cnt[0] += isEqual(i, j, m, 0);
				cnt[1] += isEqual(i, j, m, 1);
				cnt[2] += isEqual(i, j, m, 2);
				cnt[3] += isEqual(i, j, m, 3);
			}
		}
	
		for(int i = 0 ; i < 4 ; i++){
			char c = i == 3 ? '\n' : ' ';
	
			printf("%d%c", cnt[i], c);
			cnt[i] = 0;
		}
		
	}

	return 0;
}
