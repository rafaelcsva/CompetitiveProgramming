#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int p[N];
int cost[] = {2, 4, 6, 8, 10, 12, 14};
int main(){
	p[10] = 0;
	p[9] = p[8] = 1;
	p[7] = 2;
	p[5] = p[6] = 3;
	p[4] = 4;
	p[2] = p[3] = 5;
	p[1] = 6;

	int piece;

	while(scanf("%d", &piece) != EOF){
		if(piece == -1){
			break;
		}

		int tot = 0;

		int init = p[piece];

		while(init >= 0){
			tot += cost[init];
			init--;
		}

		printf("%d\n", tot);
	}

	return 0;
}