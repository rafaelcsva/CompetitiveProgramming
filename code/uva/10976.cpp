#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int vect[N], pnt = 0;

int main (){
	int k;
	
	while(scanf("%d", &k) != EOF){
		for(int y = k + 1 ; y <= 2 * k ; y++){
			if((k * y) % (y - k) == 0){
				vect[pnt++] = y;
			}
		}
		
		printf("%d\n", pnt);
		
		for(int i = 0 ; i < pnt ; i++){
			int x = (k * vect[i]) / (vect[i] - k);
			
			printf("1/%d = 1/%d + 1/%d\n", k, x, vect[i]);
		}
		
		pnt = 0;
	}

	return 0;
}
