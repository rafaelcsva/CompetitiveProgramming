#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	
	while(scanf("%d", &n)&&n){
		int v[110];
		
		for(int i = 1 ; i <= n ; i++){
			v[i] = i; 
		}
		
		int topo = 1 , ini = n;
		
		printf("Discarded cards: ");
		
		while((ini-topo)+1 >= 2 ){
			printf("%d", v[topo]);
			topo++;
			ini++;
			swap(v[topo], v[ini]);
			topo++;
			
			if(ini-topo + 1>=2)
				printf(", ");
		}
		
		printf("\nRemaining card: %d\n", v[topo]);
	}
}
