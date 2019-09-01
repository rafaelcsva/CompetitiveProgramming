#include <stdio.h>

int main(){
	int t = 350;

	printf("%d\n", t);

	while(t--){
		int n = 4000;
		int m = 10000;

		printf("%d %d\n", n, m);

		for(int i = 0 ; i < m ; i++){
			printf("%d %d\n", 1, n);
		}
	}

	return 0;
}