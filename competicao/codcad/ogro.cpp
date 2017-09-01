#include <bits/stdc++.h>

#define MAXIMO	100010

using namespace std;

int busca(int n, int key, int a[]){
	int ini = 0;
	int fim = n-2;

	if(a[ini] > key){
		return ini;
	}else if(key >= a[fim]){
		return fim+1;
	}

	while(fim>=ini){
		int meio = (ini+fim)/2;

		if(a[meio-1] <= key && a[meio] > key){
			return meio;
		}

		if(a[meio-1] > key){
			fim = meio-1;
		}else{
			ini = meio+1;
		}
	}	

	return -1;
}

int main (){
	int n, m;
	int a[MAXIMO];
	int f[MAXIMO];

	scanf("%d%d", &n, &m);

	for(int i = 0 ; i < n-1 ; i++)
		scanf("%d", &a[i]);

	for(int i = 0; i < n ; i++)
		scanf("%d", &f[i]);

	for(int i = 0 ; i < m ; i++){
		int o;

		scanf("%d", &o);

		printf("%d", f[busca(n,o, a)]);
		if(i != m-1)
			printf(" ");
	}

	printf("\n");

	return 0;
				
}
