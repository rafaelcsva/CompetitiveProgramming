#include <bits/stdc++.h>

using namespace std;

typedef long long int	ll;

int main (){
	int n;
	
	ios::sync_with_stdio(false);
	
	cin >> n;

	while(n--){
		ll a, b, c;
		
		cin >> a >> b >> c;
		
		bool find = false;
		
		for(ll i = -100 ; i <= 100 && !find ; i++){
			for(ll j = i + 1; j <= 100 ; j++){
				ll k = a - i - j;
				ll eq2 = k * i * j;
				ll eq3 = k * k + i * i + j * j;
				
				if(i != j && j != k && k != i){
					if(eq3 == c && eq2 == b){
						find = true;
					
						printf("%lld %lld %lld\n", i, j, k);	
						break;			
					}
				}
			}
		}
		
		if(!find){
			printf("No solution.\n");
		}
	}
	
	return 0;
}
