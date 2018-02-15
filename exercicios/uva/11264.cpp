#include <bits/stdc++.h>

using namespace std;

typedef long long int	ll;
const int N = (int) 1e3 + 10;
ll c[N], ans;

int main (){
	int t, n;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		ans = 0;
		
		ll sum = 0;
		
		for(int i = 0 ; i < n ; i++){
			scanf("%lld", &c[i]);
		}
		
		for(int i = 0; i < n - 1 ; i++){
			if(c[i] + sum < c[i + 1]){
				
				sum += c[i];
				ans++;
			}
		
		}
		
		printf("%lld\n", ans + 1LL);
	}

	return 0;
}
