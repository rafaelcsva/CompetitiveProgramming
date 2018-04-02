	#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
ll a[1000], b[1000];
ll k = (ll) 1e18;

int main (){
	int n, m;
	
	ios::sync_with_stdio(false);
	
	scanf("%d%d", &n, &m);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i]);
	}
	
	for(int j = 0 ; j < m ; j++){
		scanf("%lld", &b[j]);
	}
	
	for(int i = 0 ; i < n ; i++){
		
		ll tk = (ll)-1e18;
		
		for(int j = 0 ; j < n ; j++){
			if(j == i)
				continue;
			ll tmp = (ll)-1e18;
				
			for(int t = 0 ; t < m ; t++){
				tmp = max(tmp, a[j] * b[t]);
			}
			
			tk = max(tk, tmp);
		}
		k = min(k, tk);
	}		
	
	printf("%lld\n", k);
	
	return 0;
}
