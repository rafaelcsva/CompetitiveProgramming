#include <stdio.h>

int main (){
	int n;
	int k;
	int sum = 0;

	scanf("%d%d", &n, &k);
	sum = n;

	int i;
	
	for(i = 0 ; i < k ; i++){
		n = n*10;

		sum+=n;		
	}	

	printf("%d\n", sum);

	return 0;
}
