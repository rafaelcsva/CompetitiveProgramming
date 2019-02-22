#include <stdio.h>

int main(){
	int t = 1;
	
	printf("%d\n", t);
	
	
	while(t--){
		int n = 300, m = 300;
		printf("%d %d\n", n, m);
		
		for(int i = 0 ; i< n ; i++){
			for(int j = 0 ; j < m ; j++){
				char c = j == m - 1 ? '\n' : ' ';
				printf("1%c", c);
			}
		}
	}
	
	return 0;
}
