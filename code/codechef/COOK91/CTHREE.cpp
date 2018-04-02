#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
set<ll>::iterator it, jt;
set<ll>divisors;

int main (){
	int t;
	
	cin >> t;
	
	while(t--){
		ll n, a, b, c;
		
		cin >> n >> a >> b >> c;
		
		for(ll i = 1LL ; i * i <= n ; i++){
			if(n % i == 0){
				divisors.insert(n / i);
				divisors.insert(i);
			}
		}
		
		ll cnt = 0LL;
		
		for(it = divisors.begin() ; it != divisors.end() && *it <= a ; it++){
			for(jt = divisors.begin() ; jt != divisors.end() && *jt <= b && (*jt) * (*it) <= n ; jt++){
				ll prod = (*it) * (*jt);
				
				if(n % prod == 0LL){
					ll y = n / prod;
					
					if(divisors.find(y) != divisors.end() && y <= c){
						cnt++;
					}
				}
			}
		}
		
		cout << cnt << '\n';
		
		divisors.clear();
	}
	
	return 0;
}
