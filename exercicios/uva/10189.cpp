#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int M = 110;

int vx[8] = {0, -1, 1, 0, 1, -1, 1, -1};
int vy[8] = {1, 0, -1, -1, 0, -1, 1, 1};

int main (){
	int n, m;
	char tab[N][M];
	int t = 0;

	while(scanf("%d%d", &n, &m)){
			
		
		if(n == 0 && m == 0)
			break;

		if(t)
			printf("\n");
		t++;

		for(int i = 0 ; i < n ; i++){
			for(int k = 0 ; k < m ; k++){
				scanf("\n%c", (*(tab + i) + k));
			}
		}

		printf("Field #%d:\n", t);

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(tab[i][j] == '*'){
					printf("*");
				}
				else{
					int sum = 0;

					for(int k = 0 ; k < 8 ; k++){
						int a = vx[k] + i;
						int b = vy[k] + j;

						if(a >= 0 && a < n && b >= 0 && b < m){
							if(tab[a][b] == '*')
								sum++;
						}
					}

					printf("%d", sum);
				}
			}
			printf("\n");
		}	
	}

	return 0;
}
