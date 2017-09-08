#include <stdio.h>

int main (){
	int x, y;

	scanf("%d%d", &x, &y);

	if(y > 0){
		if (x < 0)	
			printf("2\n");
		else
			printf("1\n");
	}
	else{
		if(x < 0)
			printf("3\n");
		else
			printf("4\n");	
	}

	return 0;
}
