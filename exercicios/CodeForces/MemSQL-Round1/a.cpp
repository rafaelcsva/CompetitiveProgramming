#include <bits/stdc++.h>

using namespace std;

int main (){
	int a;

	int maior = -1;

	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a);

		maior = max(maior, a);

	}

	if(maior < 25)
		printf("0\n");
	else
		printf("%d\n", maior-25);

	return 0;
}