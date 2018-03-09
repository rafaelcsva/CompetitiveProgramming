#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;
lli b[100010];

int main (){
	lli n, k;
	
	scanf("%lld%lld", &n, &k);

	lli ans = 0;
	lli qtd = 0;
	lli type = 0;
	
	for(int i = 0 ; i < k ; i++){
		scanf("%lld", &b[i]);
		
		lli q = n / b[i];
		
		if(q * b[i] >= ans){
			ans = q * b[i];
			qtd = q;
			type = i;
		}
	}
	
	printf("%lld %lld\n", type + 1, qtd);
	
	return 0;
}
