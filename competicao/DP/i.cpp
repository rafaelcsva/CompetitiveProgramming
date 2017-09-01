#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;

	while(scanf("%d", &n)&&n){
		int soma = 0;

		for(int i = 1 ; i <= n ; i++){
			soma += (n*n)/(i*i);
		}

		printf("%d\n", soma);
	}

	return 0;
}
