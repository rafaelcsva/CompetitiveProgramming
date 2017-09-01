#include <bits/stdc++.h>

using namespace std;
#define MAXIMO	110

int valores[MAXIMO];

int max(int a, int b){
	return a > b ? a : b;
}

int main (){
	int n;
	int i = 0;
	
	while(scanf("%d", &n)!=EOF){
		if(n == -999999){
			long long int maximo = valores[0];
			long long int produto;

			for(int x = 0 ;x < i ; x++){
				produto = 1;
				for(int j = x ; j < i ; j++){
					produto = produto*valores[j];
					maximo = max(produto, maximo);
				}
			}

			printf("%lli\n", maximo);

			i = 0;
		}
		else{
			valores[i++] = n;
		}
	}	

	return 0;
}
