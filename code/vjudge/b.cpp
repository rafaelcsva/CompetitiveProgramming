#include <bits/stdc++.h>

using namespace std;

char c[2] = {'.', '@'};
const int N = int(1e4);
char tab[N][3];

int main(){
	freopen("black.in", "r", stdin);
	freopen("black.out", "w", stdout);

	int b, w;

	scanf("%d %d", &b, &w);

	int t = 0;

	if(b < w){
		t = 1;
		swap(b, w);
	}

	int l = 0;

	if(b != w){
		w--;

		while(w != b){
			for(int j = 0 ; j < 3 ; j++){
				for(int k = 0 ; k < 3 ; k++){
					if(j == 1 && k == 1){
						tab[j + l][k] = c[!t];
					}else{
						tab[j + l][k] = c[t];
					}
				}
			}

			b--;
			l += 3;
			// printf("%d %d\n", b, w);
		}
	}

	w += b;

	while(w != 0){
		for(int k = 0 ; k < 3 ; k++){
			tab[l][k] = c[!t];
		}
		w--;
		l++;
		t = !t;
	}

	printf("%d %d\n", l, 3);
	
	for(int i = 0 ; i < l ; i++){
		for(int j = 0 ; j < 3 ; j++){
			printf("%c", tab[i][j]);
		}

		printf("\n");
	}

	return 0;
}