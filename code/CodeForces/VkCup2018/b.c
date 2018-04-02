#include <stdio.h>
#include <stdlib.h>

typedef long long int 	lli;
lli x[100010];
lli gcd = 0LL;

int compar(const void *a, const void *b){
	lli x = *((lli *) a), y = *((lli *) b);
	
	return x - y;
}

lli __gcd(lli a, lli b){
	if(a == 0LL){
		return b;
	}
	
	return __gcd(b % a, a);
}

int main (){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &x[i]);
	}	
	
	qsort(x, n, sizeof(lli), compar);
	
	for(int i = 1 ; i < n ; i++){
		gcd = __gcd(x[i] - x[i - 1], gcd);
	}
	
	lli tot = 0LL;
	
	for(int i = 1 ; i < n ; i++){
		tot += (x[i] - x[i - 1]) / gcd - 1LL;
	} 
	
	printf("%lld\n", tot);
		
	return 0;
}
