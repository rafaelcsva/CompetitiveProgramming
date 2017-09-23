#include <bits/stdc++.h>

int main (){
	int a, b, c, d;
	int t;

	scanf("%d%d%d%d%d", &a, &b, &c, &d, &t);

	int dif = abs(a-c)+abs(b-d);

	/*if(t != 0){	
			
		if(dif==0||t%dif == 0||t > dif && dif%2 == 0&& t%2 == 0)
			printf("Y\n");
		else
			printf("N\n");
	}
	else{
		if(t%2==0||dif == 0)
			printf("Y\n");
		else
			printf("N\n");
	}*/

	int x = t - dif;
	if (x >= 0 && x % 2 == 0) {
		printf("Y\n");
	} else {
		printf("N\n");
	}

	return 0;
}
