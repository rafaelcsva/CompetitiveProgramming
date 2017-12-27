#include <bits/stdc++.h>

using namespace std;

char tab[100][100];

bool mark(int x, int y){
	bool flag = false;

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			if(tab[x + i][y + j] == '.'){
				//printf("here\n");
				flag = true;
				tab[x + i][y + j] = '!';
			}		
		}
	}

	return flag;
}

int main (){
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			scanf("\n%c", &tab[i][j]);
		}
	}

	int x, y;

	scanf("\n%d%d", &x, &y);
	
	x--;
	y--;
	x = x % 3;
	y = y % 3;
	
	//printf("init %d %d\n", x * 3, y * 3);
	bool flag = mark(x * 3, y * 3);

	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			if(!flag){
				if(tab[i][j] == '.'){
					printf("!");
				}else{
					printf("%c", tab[i][j]);
				}
			}else{
				printf("%c", tab[i][j]);
			}

			if((j + 1) % 3 == 0 && j + 1 != 9){
				printf(" ");
			}
		}
		printf("\n");

		if((i + 1) % 3 == 0)
			printf("\n");
	}

	return 0;
}
