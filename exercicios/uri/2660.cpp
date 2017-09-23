#include <bits/stdc++.h>

#define	MAXIMO	101000

#define	ll	long long
using namespace std;

ll lcd(ll a, ll b){
	return (a*b)/__gcd(a,b);	
}

int main (){
	int n, l;
	int ciclos[MAXIMO];
	
	scanf("%d%d", &n, &l);
	
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &ciclos[i]);
		
	ll m = ciclos[0];
	
	for(int i = 1 ; i < n ; i++){
		m = lcd(m, ciclos[i]);
	}
	
	ll r = m;
	int rsp = 1;
	
	for(int i = 2 ; i <= l ; i++){
		ll aux = lcd(m, i);
		
		if(aux <= l && aux > r){
				r = aux;
				rsp = i;
		}
	}
	
	printf("%d\n", rsp);
	
	return 0;
}
