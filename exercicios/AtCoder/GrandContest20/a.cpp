#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main (){
	scanf("%d%d%d", &n, &a, &b);
	
	
	if((b - a) % 2 == 0){
		printf("Alice\n");
	}else{
		printf("Borys\n");
	}

	return 0;
}
