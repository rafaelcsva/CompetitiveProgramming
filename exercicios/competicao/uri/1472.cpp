#include <bits/stdc++.h>

#define MAXIMO	100100

using namespace std;

int main (){
	int n;
	int pontos[MAXIMO];
	int sum = 0;
	int d = 0;

	while(scanf("%d", &n)!=EOF){

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &pontos[i]);
			sum+=pontos[i];
		}

		if(sum/3!=(double)sum/3.0){
			printf("0\n");
		}else{
			d = __gcd(pontos[0], pontos[1]);

			for(int i = 2 ; i < n ; i++){
				d = __gcd(pontos[2], d);		
			}

			printf("%d\n", d);
		}
	}
	
	return 0;
}
