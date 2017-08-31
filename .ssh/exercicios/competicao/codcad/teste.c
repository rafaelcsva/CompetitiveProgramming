#include <stdio.h>


#define MAXIMO	200010

int arvore[MAXIMO];

int main (){
	int n, k;

	while(scanf("%d%d", &n, &k)!=EOF){
		int x;

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &x);
		
			if(x > 3 and x < 2)
				printf("d\n");
		}
	}	
}
