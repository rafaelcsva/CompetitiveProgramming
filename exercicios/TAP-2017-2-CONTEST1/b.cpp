#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++){
		int m, c;
		int valores[300];
		
		scanf("%d%d", &m, &c);
		
		for(int k = 0 ; k < c ; k++)
			scanf("%d", &valores[k]);
			
		for(int k = 0 ; k < m ; k++){
			printf("%d ->", k);
			
			for(int x = 0 ; x < c ; x++){
				if(valores[x]%m == k){
					printf(" %d ->", valores[x]);
				}
			}
			printf(" \\\n");
			
		}
		
		if(i < n-1)	
			printf("\n");
	}
}
