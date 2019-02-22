#include <stdio.h>

int main(){
	int n, k, x;
	
	scanf("%d %d %d", &n, &k, &x);
	
	printf("%d %d %d\n", n, k, x);
	
	for(int i = 1 ; i <= n ; i++){
		printf("%d ", i % 2 + 1);
	}
	
	printf("\n");
	
	return 0;
}
