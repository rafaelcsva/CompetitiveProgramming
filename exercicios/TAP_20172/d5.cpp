#include <bits/stdc++.h>

#define	ll	long long

using namespace	std;

int main (){
	ll n;

	scanf("%Ld", &n);

	ll d = 0;
	ll aux = n;

	for(ll i = 2 ; i*i <= n ; i++){
		if(aux%i == 0){
			d++;
			
			while(aux%i == 0){
				//printf("%Ld*", i);
				aux = aux/i;
			}

			//printf("\n%Ld\n", aux);
		}
	}	
	if(aux != 1)
		d++;

	ll c = 1<<d;

	printf("%Ld\n", c-d-1);

	return 0;
}
