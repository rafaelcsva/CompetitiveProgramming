#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
int position[N];
int square[120];
int games[N];

int main (){
	int t;

	scanf("%d", &t);

	while(t--){
		int a, b, c;

		scanf("%d%d%d", &a, &b, &c);
	
		for(int i = 0 ; i <= 100 ; i++)
			square[i] = 0;

		for(int i = 0 ; i < a ; i++)
			position[i] = 1;

		for(int i = 0 ; i < b ; i++){
			int bottom, up;
	
			scanf("%d%d", &bottom, &up);

			square[bottom] = up;
		}

		for(int i = 0 ; i < c ; i++){
			scanf("%d", &games[i]);
		}

		if(a == 0)
			continue;
		int player = 0;

		for(int i = 0 ; i < c ; i++){
			int r = games[i];

			int tmp = position[player];

			tmp += r;

			tmp = min(100, tmp);

			if(square[tmp] != 0){
				position[player] = square[tmp];
			}else{
				position[player] = tmp;
			}
			
			if(position[player] == 100){
				break;
			}

			player = (player + 1) % a;
		}
		
		for(int i = 0 ; i < a ; i++){
			printf("Position of player %d is %d.\n", i + 1, position[i]);
		}	
	}
	//printf("\n");

	return 0;
}
