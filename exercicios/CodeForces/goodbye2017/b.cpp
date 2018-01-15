#include <bits/stdc++.h>

using namespace std;

const int N = 100;
char table[N][N];
char command[110];
char dir[4] = {'U', 'D', 'L', 'R'};
int act[4];
int n, m;

bool isReacheable(int pos, int x, int y){
	if(pos >= strlen(command)){
		return table[x][y] == 'E';
	}

	//printf("%d %d\n", x, y);
	if(table[x][y] == 'E')
		return true;

	int ac = command[pos] - '0';

	if(dir[act[ac]] == 'U'){
		if(x - 1 >= 0 && table[x - 1][y] != '#'){
			return isReacheable(pos + 1, x - 1, y);
		}
		return false;
	}else if(dir[act[ac]] == 'D'){
		if(x + 1 < n && table[x + 1][y] != '#'){
			return isReacheable(pos + 1, x + 1, y);
		}

		return false;
	}else if(dir[act[ac]] == 'L'){
		if(y - 1 >= 0 && table[x][y - 1] != '#'){
			return isReacheable(pos + 1, x, y - 1);
		}

		return false;
	}else{
		if(y + 1 < m && table[x][y + 1] != '#'){
			return isReacheable(pos + 1, x, y + 1);
		}

		return false;
	}
}

int main (){


	int x = 0, y = 0;
	
	scanf("%d%d", &n, &m);
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			scanf("\n%c", &table[i][j]);

			if(table[i][j] == 'S'){
				x = i;
				y = j;
			}	
		}
	}
//	printf("x = %d y = %d\n", x, y);
	scanf("\n%s", command);
	//printf("\n%s\n", command);
	int ans = 0;

	for(int i = 0 ; i < 4 ; i++){
		act[0] = i;

		for(int j = 0 ; j < 4 ; j++){
			if(j == i)
				continue;

			act[1] = j;

			for(int k = 0 ; k < 4 ; k++){
				if(k == i || k == j)
					continue;

				act[2] = k;

				for(int m = 0 ; m < 4 ; m++){
					if(m == k || m == j || m == i)	
						continue;
	
					act[3] = m;
					//printf("%c %c %c %c\n", dir[i], dir[j], dir[k], dir[m]);
					if(isReacheable(0, x, y)){
						ans++;
					}
					//printf("-------------------\n");
				}
			} 
		}
	}

	printf("%d\n", ans);

	return 0;
}
