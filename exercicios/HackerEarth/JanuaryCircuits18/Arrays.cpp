#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9, N = (int) 1e6;

int d[N];

int main (){
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	for(int i = 0 ; i < n ; i ++){
		scanf("%d", &d[i]);
	}
	
	for(int i = 0 ; i < n ; i++){
		int a;
		
		scanf("%d", &a);
		
		d[i] += a;
	}
	
	for(int i = 0 ; i < n ; i++){
		int a;
		
		scanf("%d", &a);
		
		d[i] += a;
		
		d[i] %= k;
	}
	
	sort(d, d + n);
	
	int ans = inf;
	int carry = 0;
	
	for(int i = n - 1 ; i >= 0 ; i--){
		ans = min(ans, min(d[i], (d[i] + carry) % k ));
		
		carry = k - d[i];
	}
	
	printf("%d\n", ans);
	
	return 0;
}
